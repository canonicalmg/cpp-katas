#include <unordered_map>
#include <igloo/igloo_alt.h>
#include "josephus_survivor/josephus_survivor.h"

using namespace igloo;

Describe(JosephusSurvivorTest) {
    It(Examples) {
        Assert::That(josephusSurvivor(7, 3), Equals(4));
        Assert::That(josephusSurvivor(11, 19), Equals(10));
        Assert::That(josephusSurvivor(1, 300), Equals(1));
        Assert::That(josephusSurvivor(14, 2), Equals(13));
        Assert::That(josephusSurvivor(100, 1), Equals(100));
    }

    It(Basic) {
        Assert::That(josephusSurvivor(40, 3), Equals(28));
        Assert::That(josephusSurvivor(2, 300), Equals(1));
        Assert::That(josephusSurvivor(5, 300), Equals(1));
        Assert::That(josephusSurvivor(7, 300), Equals(7));
        Assert::That(josephusSurvivor(300, 300), Equals(265));
    }
};
