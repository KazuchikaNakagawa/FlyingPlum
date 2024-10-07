#include "lexer/lexer.h"
#include "token/token.h"
#include <iostream>
#include <string>

namespace flyplum {

Lexer::Lexer(std::u8string source)
    : file(source) // ファイルを開く
{
    if (!file) {
        // ファイルが開けなかった場合の処理
        std::cerr << "Error: file not found" << std::endl;
        std::exit(1);
    }
}

Token* Lexer::lex()
{
    char ch;
    int lineCounter = 0;
    while(file.get(ch)){
        if(ch == '\n'){
            lineCounter++;
        }
    }
    file.close();
}

}