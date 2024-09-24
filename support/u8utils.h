#ifndef SUPPORT_U8UTILS_H
#define SUPPORT_U8UTILS_H

#include <cstdint>
#include <ostream>
#include <string>

namespace flyplum {

extern std::u8string to_u8string(std::uint64_t value);
extern std::ostream& operator<<(std::ostream& stream, std::u8string value);

}

#endif /* SUPPORT_U8UTILS_H */