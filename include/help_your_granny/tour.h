#ifndef CPP_KATAS_TOUR_H
#define CPP_KATAS_TOUR_H

#include <unordered_map>
#include <vector>

typedef std::unordered_map<std::string, double> stringdblmap;

class Tour {
public:
    static int
    tour(std::vector<std::string> &arrFriends, std::vector<std::vector<std::string>> &ftwns, stringdblmap &h);
};

#endif //CPP_KATAS_TOUR_H
