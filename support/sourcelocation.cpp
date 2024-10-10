#include "support/sourcelocation.h"
#include "support/u8utils.h"

namespace flyplum {

std::u8string SourceLocation::toString() const
{
    return *path + u8":" + flyplum::to_u8string(line) + u8":" + flyplum::to_u8string(column);
}

}