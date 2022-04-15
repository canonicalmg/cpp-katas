#include <igloo/igloo_alt.h>
#include "weight_for_weight/weight_sort.h"

using namespace igloo;

void testequal(std::string ans, std::string sol) {
    Assert::That(ans, Equals(sol));
}

static void dotest(const std::string &s, std::string expected) {
    testequal(WeightSort::orderWeight(s), expected);
}

Describe(orderWeight_Tests) {
    It(Fixed_Tests) {
        dotest("103 123 4444 99 2000", "2000 103 123 4444 99");
        dotest("2000 10003 1234000 44444444 9999 11 11 22 123", "11 11 2000 10003 22 123 1234000 44444444 9999");
        dotest("", "");
        dotest("103 123 4444 99 2000 ", "2000 103 123 4444 99");
    }
};
