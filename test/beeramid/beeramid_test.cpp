#include <igloo/igloo_alt.h>
#include "beeramid/beeramid.h"

using namespace igloo;

Describe(Beeramid_Tests) {
    It(Fixed_tests) {
        Assert::That(beeramid(9, 2), Equals(1));
        Assert::That(beeramid(10, 2), Equals(2));
        Assert::That(beeramid(11, 2), Equals(2));
        Assert::That(beeramid(21, 1.5), Equals(3));
        Assert::That(beeramid(454, 5), Equals(5));
        Assert::That(beeramid(455, 5), Equals(6));
        Assert::That(beeramid(4, 4), Equals(1));
        Assert::That(beeramid(3, 4), Equals(0));
        Assert::That(beeramid(0, 4), Equals(0));
        Assert::That(beeramid(-1, 4), Equals(0));
    }
};
