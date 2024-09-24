#include "lexer/lexer.h"
#include "support/u8utils.h"
#include <iostream>

using namespace flyplum;
using namespace std;

int main()
{
    Lexer lexer(u8"test/sample.fly");
    Token* tokens = lexer.lex();
    for (auto* iter = tokens->getNext(); iter != tokens; iter = iter->getNext()) {
        std::cout << iter->toString() << std::endl;
    }
    return 0;
}