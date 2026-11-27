#include "Window/GLFW/GLFWKeyMapper.h"

#include <GLFW/glfw3.h>

namespace Nanoforce::GLFWKeyMapper
{

Key toKey(int glfwKey) noexcept
{
    switch (glfwKey)
    {
        case GLFW_KEY_ESCAPE:        return Key::Esc;
        case GLFW_KEY_ENTER:         return Key::Enter;
        case GLFW_KEY_SPACE:         return Key::Space;
        case GLFW_KEY_TAB:           return Key::Tab;
        case GLFW_KEY_BACKSPACE:     return Key::Backspace;
        case GLFW_KEY_UP:            return Key::Up;
        case GLFW_KEY_DOWN:          return Key::Down;
        case GLFW_KEY_LEFT:          return Key::Left;
        case GLFW_KEY_RIGHT:         return Key::Right;
        case GLFW_KEY_0:             return Key::Key0;
        case GLFW_KEY_1:             return Key::Key1;
        case GLFW_KEY_2:             return Key::Key2;
        case GLFW_KEY_3:             return Key::Key3;
        case GLFW_KEY_4:             return Key::Key4;
        case GLFW_KEY_5:             return Key::Key5;
        case GLFW_KEY_6:             return Key::Key6;
        case GLFW_KEY_7:             return Key::Key7;
        case GLFW_KEY_8:             return Key::Key8;
        case GLFW_KEY_9:             return Key::Key9;
        case GLFW_KEY_A:             return Key::KeyA;
        case GLFW_KEY_B:             return Key::KeyB;
        case GLFW_KEY_C:             return Key::KeyC;
        case GLFW_KEY_D:             return Key::KeyD;
        case GLFW_KEY_E:             return Key::KeyE;
        case GLFW_KEY_F:             return Key::KeyF;
        case GLFW_KEY_G:             return Key::KeyG;
        case GLFW_KEY_H:             return Key::KeyH;
        case GLFW_KEY_I:             return Key::KeyI;
        case GLFW_KEY_J:             return Key::KeyJ;
        case GLFW_KEY_K:             return Key::KeyK;
        case GLFW_KEY_L:             return Key::KeyL;
        case GLFW_KEY_M:             return Key::KeyM;
        case GLFW_KEY_N:             return Key::KeyN;
        case GLFW_KEY_O:             return Key::KeyO;
        case GLFW_KEY_P:             return Key::KeyP;
        case GLFW_KEY_Q:             return Key::KeyQ;
        case GLFW_KEY_R:             return Key::KeyR;
        case GLFW_KEY_S:             return Key::KeyS;
        case GLFW_KEY_T:             return Key::KeyT;
        case GLFW_KEY_U:             return Key::KeyU;
        case GLFW_KEY_V:             return Key::KeyV;
        case GLFW_KEY_W:             return Key::KeyW;
        case GLFW_KEY_X:             return Key::KeyX;
        case GLFW_KEY_Y:             return Key::KeyY;
        case GLFW_KEY_Z:             return Key::KeyZ;
        case GLFW_KEY_F1:            return Key::F1;
        case GLFW_KEY_F2:            return Key::F2;
        case GLFW_KEY_F3:            return Key::F3;
        case GLFW_KEY_F4:            return Key::F4;
        case GLFW_KEY_F5:            return Key::F5;
        case GLFW_KEY_F6:            return Key::F6;
        case GLFW_KEY_F7:            return Key::F7;
        case GLFW_KEY_F8:            return Key::F8;
        case GLFW_KEY_F9:            return Key::F9;
        case GLFW_KEY_F10:           return Key::F10;
        case GLFW_KEY_F11:           return Key::F11;
        case GLFW_KEY_F12:           return Key::F12;
        case GLFW_KEY_LEFT_SHIFT:    return Key::LeftShift;
        case GLFW_KEY_RIGHT_SHIFT:   return Key::RightShift;
        case GLFW_KEY_LEFT_CONTROL:  return Key::LeftCtrl;
        case GLFW_KEY_RIGHT_CONTROL: return Key::RightCtrl;
        case GLFW_KEY_LEFT_ALT:      return Key::LeftAlt;
        case GLFW_KEY_RIGHT_ALT:     return Key::RightAlt;
        default:                     return Key::Unknown;
    }
}

InputAction toAction(int glfwAction) noexcept
{
    switch (glfwAction)
    {
        case GLFW_RELEASE: return InputAction::Release;
        case GLFW_PRESS:   return InputAction::Press;
        case GLFW_REPEAT:  return InputAction::Repeat;
        default:           return InputAction::Unknown;
    }
}

MouseButtonType toMouseButton(int glfwButton) noexcept
{
    switch (glfwButton)
    {
        case GLFW_MOUSE_BUTTON_LEFT:   return MouseButtonType::Left;
        case GLFW_MOUSE_BUTTON_MIDDLE: return MouseButtonType::Middle;
        case GLFW_MOUSE_BUTTON_RIGHT:  return MouseButtonType::Right;
        default:                       return MouseButtonType::None;
    }
}

}  // namespace Nanoforce::GLFWKeyMapper
