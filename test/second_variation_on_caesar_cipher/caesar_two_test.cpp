#include <igloo/igloo_alt.h>
#include "second_variation_on_caesar_cipher/caesar_two.h"

#include <vector>

using namespace igloo;

void testequal1(std::vector<std::string> ans, std::vector<std::string> sol) {
    Assert::That(ans, Equals(sol));
}

static void dotest1(const std::string &s, int shift, std::vector<std::string> expected) {
    testequal1(CaesarTwo::encodeStr(s, shift), expected);
}

void testequal2(std::string ans, std::string sol) {
    Assert::That(ans, Equals(sol));
}

static void dotest2(std::vector<std::string> &s, std::string expected) {
    testequal2(CaesarTwo::decode(s), expected);
}

Describe(encode_decode_Tests) {
    It(encode_Tests1) {
        std::string u = "I should have known that you would have a perfect answer for me!!!";
        std::vector<std::string> sol = {"ijJ tipvme ibw", "f lopxo uibu z", "pv xpvme ibwf ", "b qfsgfdu botx",
                                        "fs gps nf!!!"};
        dotest1(u, 1, sol);
    }

    It(decode_Tests) {
        std::string u = "I should have known that you would have a perfect answer for me!!!";
        std::vector<std::string> sol = {"ijJ tipvme ibw", "f lopxo uibu z", "pv xpvme ibwf ", "b qfsgfdu botx",
                                        "fs gps nf!!!"};
        dotest2(sol, u);
    }

    It(encode_and_decode_tests) {
        std::string text = "O CAPTAIN! my Captain! our fearful trip is done;";

        std::vector<std::string> encoded = CaesarTwo::encodeStr(text, 1);
        std::string decoded = CaesarTwo::decode(encoded);

        Assert::That(decoded, Equals(text));
    }

    It(encode_and_decode_with_shift25_tests) {
        std::string text = "O CAPTAIN! my Captain! our fearful trip is done;";

        std::vector<std::string> encoded = CaesarTwo::encodeStr(text, 25);
        std::string decoded = CaesarTwo::decode(encoded);

        Assert::That(decoded, Equals(text));
    }
};
