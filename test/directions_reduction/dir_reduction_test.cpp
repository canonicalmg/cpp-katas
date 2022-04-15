#include <igloo/igloo_alt.h>
#include "directions_reduction/dir_reduction.h"

using namespace igloo;

#include <vector>

void testequal(std::vector<std::string> ans, std::vector<std::string> sol) {
    Assert::That(ans, Equals(sol));
}

Describe(dirReduc_Tests) {
    It(Fixed_Tests) {
        std::vector<std::string> d1 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
        std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
        std::vector<std::string> sol1 = {"WEST"};
        testequal(ans1, sol1);

        std::vector<std::string> d2 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "NORTH"};
        std::vector<std::string> ans2 = DirReduction::dirReduc(d2);
        std::vector<std::string> sol2 = {"NORTH"};
        testequal(ans2, sol2);
    }
};
