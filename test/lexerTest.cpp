#include "lexer/lexer.h"
#include <iostream>

using namespace flyplum;
using namespace std;

int main()
{
    Lexer lexer("test/sample.fly");
    Token* tokens = lexer.lex();
    for (auto* iter = tokens->next(); iter != tokens; iter = iter->next()) {
        std::cout << iter->toString() << std::endl;
    }
    return 0;
}