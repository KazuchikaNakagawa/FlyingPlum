#ifndef SUPPORT_SOURCELOCATION_H
#define SUPPORT_SOURCELOCATION_H

#include <cstdint>
#include <memory>
#include <string>

namespace flyplum {

using SharedPath = std::shared_ptr<std::u8string>;

class SourceLocation {
    //! ファイル名
    SharedPath path;
    //! 行番号
    std::uint32_t line;
    //! 何文字目か
    std::uint32_t column;

    //! どれくらいの長さか
    std::uint32_t length;

public:
    SourceLocation(SharedPath path, std::uint32_t line, std::uint32_t column, std::uint32_t length)
        : path(path)
        , line(line)
        , column(column)
        , length(length)
    {
    }

    SharedPath getPath() const { return path; }
    std::uint32_t getLine() const { return line; }
    std::uint32_t getColumn() const { return column; }
    std::uint32_t getOffset() const { return length; }

    std::u8string toString() const;
};

}

#endif /* SUPPORT_SOURCELOCATION_H */