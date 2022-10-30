#include <vector>
#include <igloo/igloo_alt.h>
#include "help_the_bookseller/StockList.h"

using namespace igloo;

static void testequal(std::string ans, std::string sol) {
    Assert::That(ans, Equals(sol));
}

static void dotest(std::vector<std::string> &lstOfArt, std::vector<std::string> &categories, std::string expected) {
    testequal(StockList::stockSummary(lstOfArt, categories), expected);
}

Describe(stockSummary_Tests) {
    It(Fixed_Test_1) {
        std::vector<std::string> art = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
        std::vector<std::string> cd = {"A", "B"};
        dotest(art, cd, "(A : 200) - (B : 1140)");
    }

    It(Fixed_Test_2) {
        std::vector<std::string> art = {"BBAR 150", "CDXE 515", "BKWR 250", "BTSQ 890", "DRTY 600"};
        std::vector<std::string> cd = {"A", "B", "C", "D"};
        dotest(art, cd, "(A : 0) - (B : 1290) - (C : 515) - (D : 600)");
    }

    It(Fixed_Test_3) {
        std::vector<std::string> art = {"BBAR 150", "CDXE 515", "BKW2 250", "BTSQ 890", "DRTY 600"};
        std::vector<std::string> cd = {"A", "B", "C", "D"};
        dotest(art, cd, "(A : 0) - (B : 1290) - (C : 515) - (D : 600)");
    }

    It(Empty_art_Test) {
        std::vector<std::string> art = {};
        std::vector<std::string> cd = {"A", "B"};
        dotest(art, cd, "");
    }

    It(Empty_cat_test) {
        std::vector<std::string> art = {"BBAR 150", "CDXE 515", "BKW2 250", "BTSQ 890", "DRTY 600"};
        std::vector<std::string> cd = {};
        dotest(art, cd, "");
    }
};

