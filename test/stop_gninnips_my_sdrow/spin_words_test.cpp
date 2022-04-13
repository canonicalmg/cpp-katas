#include <igloo/igloo_alt.h>
#include "stop_gninnips_my_sdrow/spin_words.h"

using namespace igloo;

Describe(Sample_Tests) {
    It(Single_Word) {
        Assert::That(spinWords("Welcome"), Equals("emocleW"));
        Assert::That(spinWords("to"), Equals("to"));
        Assert::That(spinWords("CodeWars"), Equals("sraWedoC"));
    }

    It(Mulitple_Words) {
        Assert::That(spinWords("Hey fellow warriors"), Equals("Hey wollef sroirraw"));
        Assert::That(spinWords("Burgers are my favorite fruit"), Equals("sregruB are my etirovaf tiurf"));
        Assert::That(spinWords("Pizza is the best vegetable"), Equals("azziP is the best elbategev"));
    }
};
