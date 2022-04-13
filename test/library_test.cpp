#include <igloo/igloo_alt.h>
#include "library.h"

using namespace igloo;

Describe(a_simple_test) {
    It(should_return_greeting) {
        Assert::That(greeting(), Equals("Hello, World!"));
    }
};

int main(int argc, const char *argv[]) {
    return TestRunner::RunAllTests(argc, argv);
}
