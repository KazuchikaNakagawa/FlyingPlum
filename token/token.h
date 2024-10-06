#ifndef TOKEN_TOKEN_H
#define TOKEN_TOKEN_H

#include "support/sourcelocation.h"
#include <cstdint>
#include <string>

namespace flyplum {

enum class TokenKind {
    // 予約語
    kKeyword,
    // 識別子
    kIdentifier,
    // 整数リテラル(64bit 符号付き)
    kInteger,
    // 小数リテラル
    kFloat,
    // 文字列リテラル
    kString,
    // シンボル
    kSymbol,
    // ファイルの終わり（ダミートークン）
    kEndOfFile,
};

union TokenValue {
    std::int64_t integerValue;
    double floatValue;
    std::u8string* stringValue;
};

class Token {
private:
    Token* next;
    Token* prev;
    TokenKind kind;
    TokenValue value;
    SourceLocation location;
    Token(Token* next, Token* prev, TokenKind kind, TokenValue value, SourceLocation location)
        : next(next)
        , prev(prev)
        , kind(kind)
        , value(value)
        , location(location)
    {
    }

    Token()
        : next(this)
        , prev(this)
        , kind(TokenKind::kEndOfFile)
        , value({ 0 })
        , location(SharedPath(), 0, 0, 0)
    {
    }

public:
    /* 末端となるダミートークンの生成 */
    static Token* create();

    /* トークンの生成 */
    Token* addStringToken(std::u8string value, SourceLocation location);
    Token* addIntegerToken(std::int64_t value, SourceLocation location);
    Token* addFloatToken(double value, SourceLocation location);
    Token* addSymbolToken(std::u8string value, SourceLocation location);
    Token* addKeywordToken(std::u8string value, SourceLocation location);
    Token* addIdentifierToken(std::u8string value, SourceLocation location);

    /* トークンの取得 */
    Token* getNext() const { return next; }
    Token* getPrev() const { return prev; }

    TokenKind getKind() const { return kind; }

    /* トークンの値の取得 */
    std::u8string& getStringValue() const;
    std::int64_t getIntegerValue() const;
    double getFloatValue() const;

    /* トークンの位置情報の取得 */
    SourceLocation getLocation() const { return location; }

    /* トークンの文字列表現 */
    // TODO: よしなに実装してください　SourceLocationにtoStringがあるから利用を推奨する
    std::u8string toString() const;

    /* トークンの破棄 */
    ~Token();
};

}

#endif /* TOKEN_TOKEN_H */