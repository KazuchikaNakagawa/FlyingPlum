#include "support/u8utils.h"
#include <__fwd/string.h>

namespace flyplum {

std::u8string to_u8string(std::uint64_t value)
{
    auto str = std::to_string(value);
    return std::u8string(str.begin(), str.end());
}

}