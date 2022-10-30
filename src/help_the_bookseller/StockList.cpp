#include <string>
#include <regex>
#include <map>
#include <utility>

/**
 * https://www.codewars.com/kata/54dc6f5a224c26032800005c/train/cpp
 */
class StockList {
public:
    static std::string stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories);
};

namespace help_the_bookseller {
    class StockItem {
    private:
        std::string _category;
        int _quantity;

        StockItem(std::string category, int quantity) : _category(std::move(category)), _quantity(quantity) {
        }

    public:
        [[nodiscard]] std::string category() const {
            return _category;
        }

        [[nodiscard]] int quantity() const {
            return _quantity;
        }

        static StockItem read_one(const std::string &input);

        static std::vector<StockItem> read_many(const std::vector<std::string> &input);
    };

    class Stock {
    private:
        std::map<std::string, int> _stock;

        explicit Stock(std::map<std::string, int> stock) : _stock(std::move(stock)) {
        }

    public:
        static Stock create_from(const std::vector<StockItem> &stock_items);

        std::string format(std::vector<std::string> &categories);
    };

    class Join {
    private:
        std::string delimiter;
        std::vector<std::string> strings;

        Join();

    public:
        explicit Join(std::string delimiter);

        void append(const std::string &str);

        std::string build();
    };
}

using namespace help_the_bookseller;

std::string StockList::stockSummary(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories) {
    if (lstOfArt.empty()) {
        return "";
    }

    const std::vector<StockItem> &stock_items = StockItem::read_many(lstOfArt);
    Stock stock = Stock::create_from(stock_items);

    return stock.format(categories);
}

StockItem StockItem::read_one(const std::string &input) {
    std::regex pattern("([A-Z])[A-Z0-9]* ([0-9]+)");
    std::smatch matches;

    if (std::regex_search(input, matches, pattern) && matches.size() > 2) {
        std::string category = matches[1];
        std::string quantity = matches[2];

        return {category, std::stoi(quantity)};
    } else {
        throw std::exception();
    }
}

std::vector<StockItem> StockItem::read_many(const std::vector<std::string> &input) {
    std::vector<StockItem> items;

    for (const auto &item: input) {
        items.push_back(read_one(item));
    }

    return items;
}

Stock Stock::create_from(const std::vector<StockItem> &stock_items) {
    std::map<std::string, int> stock;
    for (const auto &item: stock_items) {
        const auto &found = stock.find(item.category());

        int quantity = item.quantity();

        if (found != stock.end()) {
            quantity += stock.at(found->first);
        }

        stock[item.category()] = quantity;
    }

    return Stock(stock);
}

std::string Stock::format(std::vector<std::string> &categories) {
    Join joined_items = Join(" - ");

    for (const auto &category: categories) {
        const auto &found = _stock.find(category);

        std::string formatted = "(" + category + " : ";
        if (found != _stock.end()) {
            int quantity = _stock.at(found->first);
            formatted += std::to_string(quantity);
        } else {
            formatted += "0";
        }

        joined_items.append(formatted + ")");
    }

    return joined_items.build();
}

Join::Join() {
    this->delimiter = "";
}

Join::Join(std::string delimiter) {
    this->delimiter = std::move(delimiter);
}

void Join::append(const std::string &str) {
    this->strings.push_back(str);
}

std::string Join::build() {
    if (strings.empty()) {
        return "";
    }

    std::string joined;

    unsigned int ultimo = strings.size() - 1;
    unsigned int index = 0;

    for (; index < ultimo; index++) {
        joined.append(this->strings[index]);
        joined.append(this->delimiter);
    }

    joined.append(this->strings[index]);

    return joined;
}
