#ifndef INPUT_H
#define INPUT_H
#include <vector>

namespace KeyboardInput
{
    void setKey(int key_constant, bool pressed);
    bool keyIsPressed(int key_constant);
}

#endif // INPUT_H
