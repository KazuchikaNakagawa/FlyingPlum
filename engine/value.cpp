#include "engine/value.h"
#include "support/u8utils.h"
#include <cstdlib>
#include <iostream>
#include <string>

namespace flyplum {

FlyPlumValue FlyPlumValue::Integer(std::int64_t value)
{
    std::int64_t* ptr = new std::int64_t(value);
    return FlyPlumValue(std::int64_t(ptr) << 3 | static_cast<std::uint64_t>(FlyPlumValueType::INTEGER));
}

FlyPlumValue FlyPlumValue::Float(double value)
{
    double* ptr = new double(value);
    return FlyPlumValue(std::int64_t(ptr) << 3 | static_cast<std::uint64_t>(FlyPlumValueType::FLOAT));
}

FlyPlumValue::~FlyPlumValue()
{
    switch (getType()) {
    case FlyPlumValueType::INTEGER:
        delete reinterpret_cast<std::int64_t*>(value >> 3 << 3);
        break;
    case FlyPlumValueType::FLOAT:
        delete reinterpret_cast<double*>(value >> 3 << 3);
        break;
    case FlyPlumValueType::STRING:
        delete reinterpret_cast<std::u8string*>(value >> 3 << 3);
        break;
    default:
        // オブジェクトなのでdeinitを呼びたいが
        // 今はnullptrなので何もしない
        break;
    }
}

std::u8string FlyPlumValue::toString() const
{
    std::u8string typeData;
    switch (getType()) {
    case FlyPlumValueType::INTEGER:
        typeData = u8"INTEGER";
        break;
    case FlyPlumValueType::FLOAT:
        typeData = u8"FLOAT";
        break;
    case FlyPlumValueType::STRING:
        typeData = u8"STRING";
        break;
    default:
        std::cerr << "Error: unknown type" << std::endl;
        std::exit(1);
    }
    // address data
    std::uint64_t addr = value >> 3 << 3;
    std::u8string addrData = flyplum::to_u8string(addr, 16);
    return u8"FlyPlumValue(" + typeData + u8", " + addrData + u8")";
}

} // namespace flyplum