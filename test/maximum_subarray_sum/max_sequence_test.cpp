#include <igloo/igloo_alt.h>
#include "maximum_subarray_sum/max_sequence.h"

using namespace igloo;

Describe(Maximum_subarray_sum) {
    It(should_work_on_an_empty_array) {
        Assert::That(maxSequence({}), Equals(0));
    }

    It(should_work_on_the_example) {
        Assert::That(maxSequence({-2, 1, -3, 4, -1, 2, 1, -5, 4}), Equals(6));
    }
};
