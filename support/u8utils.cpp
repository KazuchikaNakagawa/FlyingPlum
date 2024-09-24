#include "support/u8utils.h"

namespace flyplum {

std::u8string to_u8string(std::uint64_t value)
{
    auto str = std::to_string(value);
    return std::u8string(str.begin(), str.end());
}

std::ostream& operator<<(std::ostream& stream, std::u8string value)
{
    stream << reinterpret_cast<char*>(const_cast<char8_t*>(value.c_str()));
    return stream;
}

}