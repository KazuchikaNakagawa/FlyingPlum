#include "support/u8utils.h"
#include <format>
#include <string>

namespace flyplum {

std::u8string to_u8string(std::uint64_t value, int base)
{
    std::string str;
    if (base == 10) {
        str = std::format("{:d}", value);
    } else if (base == 16) {
        str = std::format("{:x}", value);
    } else {
        str = std::format("{:d}", value);
    }
    return std::u8string(str.begin(), str.end());
}

std::ostream& operator<<(std::ostream& stream, std::u8string value)
{
    stream << reinterpret_cast<char*>(const_cast<char8_t*>(value.c_str()));
    return stream;
}

}