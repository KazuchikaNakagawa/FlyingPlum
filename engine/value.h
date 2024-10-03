#ifndef ENGINE_VALUE_H
#define ENGINE_VALUE_H

#include <cstdint>
#include <string>

namespace flyplum {

enum class FlyPlumValueType : std::uint64_t {
    OBJECT = 0,
    INTEGER,
    FLOAT,
    STRING,
    BOOLEAN,
    // VARIABLE,
    FUNCTION,
    CFUNCTION,
};

struct FlyPlumValue {
private:
    std::uint64_t value;
    FlyPlumValue(std::uint64_t value)
        : value(value)
    {
    }

public:
    static FlyPlumValue Integer(std::int64_t value);
    static FlyPlumValue Float(double value);

    FlyPlumValueType getType() const
    {
        return static_cast<FlyPlumValueType>(value & 0b111);
    }

    std::u8string toString() const;

    std::int64_t getInteger() const
    {
        return *reinterpret_cast<std::int64_t*>(value >> 3 << 3);
    }

    double getFloat() const
    {
        return *reinterpret_cast<double*>(value >> 3 << 3);
    }

    std::u8string getString() const
    {
        return *reinterpret_cast<std::u8string*>(value >> 3 << 3);
    }

    // move constructor
    FlyPlumValue(FlyPlumValue&& other)
        : value(other.value)
    {
        other.value = 0;
    }

    ~FlyPlumValue();
};

}

#endif /* ENGINE_VALUE_H */