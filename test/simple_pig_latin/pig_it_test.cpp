#include <igloo/igloo_alt.h>
#include "simple_pig_latin/pig_it.h"

using namespace igloo;

Describe(Simple_Pig_Latin) {
    It(Tests) {
        Assert::That(pig_it("This is my string"), Equals("hisTay siay ymay tringsay"));
        Assert::That(pig_it("Pig latin is cool"), Equals("igPay atinlay siay oolcay"));
        Assert::That(pig_it("Acta est fabula"), Equals("ctaAay steay abulafay"));
        Assert::That(pig_it("O tempora o mores !"), Equals("Oay emporatay oay oresmay !"));
        Assert::That(pig_it("Quis custodiet ipsos custodes ?"), Equals("uisQay ustodietcay psosiay ustodescay ?"));
        Assert::That(pig_it("ilpidrh ."), Equals("lpidrhiay ."));
        Assert::That(pig_it("u , gvzi"), Equals("uay , vzigay"));
    }
};
