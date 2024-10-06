#include "token/token.h"
#include <cstdlib>
#include <iostream>
#include <string>

namespace flyplum {

Token* Token::create()
{
    return new Token();
}

Token* Token::addStringToken(std::u8string value, SourceLocation location)
{
    // そもそもこのトークンが末端でない場合はエラー
    if (this->kind != TokenKind::kEndOfFile) {
        std::cerr << "this token cannot be added" << std::endl;
        std::exit(1);
    }
    // 文字を持つトークンなのでヒープに確保
    // このトークンが削除されるときに文字列も削除される
    auto* heapString = new std::u8string(value);
    auto* newToken = new Token(this, this->prev, TokenKind::kString, { .stringValue = heapString }, location);
    this->prev->next = newToken;
    this->prev = newToken;
    return newToken;
}

Token* Token::addIntegerToken(std::int64_t value, SourceLocation location)
{
    // そもそもこのトークンが末端でない場合はエラー
    if (this->kind != TokenKind::kEndOfFile) {
        std::cerr << "this token cannot be added" << std::endl;
        std::exit(1);
    }

    auto* newToken = new Token(this, this->prev, TokenKind::kInteger, { .integerValue = value }, location);
    this->prev->next = newToken;
    this->prev = newToken;
    return newToken;
}

Token* Token::addFloatToken(double value, SourceLocation location)
{
    // そもそもこのトークンが末端でない場合はエラー
    if (this->kind != TokenKind::kEndOfFile) {
        std::cerr << "this token cannot be added" << std::endl;
        std::exit(1);
    }

    auto* newToken = new Token(this, this->prev, TokenKind::kFloat, { .floatValue = value }, location);
    this->prev->next = newToken;
    this->prev = newToken;
    return newToken;
}

Token* Token::addSymbolToken(std::u8string value, SourceLocation location)
{
    // そもそもこのトークンが末端でない場合はエラー
    if (this->kind != TokenKind::kEndOfFile) {
        std::cerr << "this token cannot be added" << std::endl;
        std::exit(1);
    }
    // 文字を持つトークンなのでヒープに確保
    // このトークンが削除されるときに文字列も削除される
    auto* heapString = new std::u8string(value);
    auto* newToken = new Token(this, this->prev, TokenKind::kSymbol, { .stringValue = heapString }, location);
    this->prev->next = newToken;
    this->prev = newToken;
    return newToken;
}

Token* Token::addKeywordToken(std::u8string value, SourceLocation location)
{
    // そもそもこのトークンが末端でない場合はエラー
    if (this->kind != TokenKind::kEndOfFile) {
        std::cerr << "this token cannot be added" << std::endl;
        std::exit(1);
    }
    // 文字を持つトークンなのでヒープに確保
    // このトークンが削除されるときに文字列も削除される
    auto* heapString = new std::u8string(value);
    auto* newToken = new Token(this, this->prev, TokenKind::kKeyword, { .stringValue = heapString }, location);
    this->prev->next = newToken;
    this->prev = newToken;
    return newToken;
}

Token* Token::addIdentifierToken(std::u8string value, SourceLocation location)
{
    // そもそもこのトークンが末端でない場合はエラー
    if (this->kind != TokenKind::kEndOfFile) {
        std::cerr << "this token cannot be added" << std::endl;
        std::exit(1);
    }
    // 文字を持つトークンなのでヒープに確保
    // このトークンが削除されるときに文字列も削除される
    auto* heapString = new std::u8string(value);
    auto* newToken = new Token(this, this->prev, TokenKind::kIdentifier, { .stringValue = heapString }, location);
    this->prev->next = newToken;
    this->prev = newToken;
    return newToken;
}

Token::~Token()
{
    if (this->kind == TokenKind::kString
        || this->kind == TokenKind::kKeyword
        || this->kind == TokenKind::kIdentifier
        || this->kind == TokenKind::kSymbol) {
        // 文字を持つトークンの場合は文字列を削除
        delete this->value.stringValue;
    }

    // ダミートークンの場合はリストを全て削除
    if (this->kind == TokenKind::kEndOfFile) {
        for (auto* iter = this->next; iter != this; iter = iter->next) {
            delete iter;
        }
    }
}

std::u8string& Token::getStringValue() const
{
    // 文字列を持つトークンでない場合はエラー
    if (this->kind == TokenKind::kString
        || this->kind == TokenKind::kKeyword
        || this->kind == TokenKind::kIdentifier
        || this->kind == TokenKind::kSymbol) {
        return *this->value.stringValue;
    }
    std::cerr << "Token is not string." << std::endl;
    std::exit(1);
}

std::int64_t Token::getIntegerValue() const
{
    if(this->kind == TokenKind::kInteger){
        return this->value.integerValue;
    }
    std::cerr << "Token is not integer." << std::endl;
    std::exit(1);
}

double Token::getFloatValue() const
{
    if(this->kind == TokenKind::kFloat){
        return this->value.floatValue;
    }
    std::cerr << "Token is not float." << std::endl;
    std::exit(1);
}

std::u8string Token::toString() const
{
    
}

} // namespace flyplum