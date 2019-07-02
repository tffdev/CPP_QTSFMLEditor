#include "keyboardinput.h"
#include <algorithm>
#include <vector>
#include <stdio.h>

namespace KeyboardInput
{
    /* vector containing keycodes of currently-pressed keys */
    std::vector<int> pressed_keys;

    void setKey(int key_constant, bool pressed){
        std::vector<int>::iterator pos_it = std::find(pressed_keys.begin(), pressed_keys.end(), key_constant);
        if(pos_it == pressed_keys.end() &&  pressed) pressed_keys.emplace_back(key_constant);
        if(pos_it != pressed_keys.end() && !pressed) pressed_keys.erase(pos_it);
    }

    bool keyIsPressed(int key_constant) {
        std::vector<int>::iterator pos_it = std::find(pressed_keys.begin(), pressed_keys.end(), key_constant);
        if(pos_it == pressed_keys.end()) return false;
        return true;
    }
}
