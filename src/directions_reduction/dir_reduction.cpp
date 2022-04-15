#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

/**
 * https://www.codewars.com/kata/550f22f4d758534c1100025a/train/cpp
 */
class DirReduction {
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr);
};

static const std::unordered_map<std::string, std::string> DIRECTION_OPPOSITES = {
        {"NORTH", "SOUTH"},
        {"SOUTH", "NORTH"},
        {"EAST",  "WEST"},
        {"WEST",  "EAST"}};

/**
 * @param arr an array of strings ("NORTH", "SOUTH", "EAST", "WEST" only)
 * @return an array of strings with the needless directions removed
 */
std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr) {
    std::vector<std::string> reduced;

    for (const std::string &direction: arr) {
        if (reduced.empty()) {
            reduced.push_back(direction);
        } else {
            std::string &last = reduced.back();

            if (DIRECTION_OPPOSITES.at(last) == direction) {
                reduced.pop_back();
            } else {
                reduced.push_back(direction);
            }
        }
    }

    return reduced;
}
