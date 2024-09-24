#include "lexer/lexer.h"
#include <iostream>

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
    // TODO: 実装頼む
}

}