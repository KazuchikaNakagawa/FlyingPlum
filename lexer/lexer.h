#ifndef LEXER_LEXER_H
#define LEXER_LEXER_H

#include "token/token.h"
#include <fstream>
#include <string>
namespace flyplum {

class Lexer {
    // パスからファイルを読み込む
    // ファイルはifstreamを使うと読み込める
    std::ifstream file;

public:
    // ここでファイルのパスを指定する
    Lexer(std::u8string source);

    // この関数を呼ぶとトークンの列が返ってくる
    Token* lex();
    ~Lexer() {};
};

}
#endif /* LEXER_LEXER_H */