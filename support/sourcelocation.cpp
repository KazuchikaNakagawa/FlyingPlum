#include "support/sourcelocation.h"
#include "support/u8utils.h"

namespace flyplum {

std::u8string SourceLocation::toString() const
{
    return u8"Path: " + *path + u8"(" + to_u8string(line) + u8"," + to_u8string(column) + u8")";
}

}