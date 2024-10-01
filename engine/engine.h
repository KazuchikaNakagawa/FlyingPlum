#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "engine/value.h"
#include <stack>
namespace flyplum {

class Engine {
    std::stack<FlyPlumValue> stack;

public:
    Engine() { }
    ~Engine() { }
};

}

#endif /* ENGINE_ENGINE_H */