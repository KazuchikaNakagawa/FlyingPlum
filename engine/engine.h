#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "engine/value.h"
#include <stack>
namespace flyplum {

class Engine {
    std::stack<FlyPlumValue> stack;

public:
    Engine() { }
    void push(FlyPlumValue value) { stack.push(value); }
    FlyPlumValue pop()
    {
        FlyPlumValue value(stack.top());
        stack.pop();
        return value;
    }
    ~Engine() { }
};

}

#endif /* ENGINE_ENGINE_H */