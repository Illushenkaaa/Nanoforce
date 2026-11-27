#pragma once

#include "Event/InputEvent.h"

namespace Nanoforce::GLFWKeyMapper
{

[[nodiscard]] Key             toKey(int glfwKey) noexcept;
[[nodiscard]] InputAction     toAction(int glfwAction) noexcept;
[[nodiscard]] MouseButtonType toMouseButton(int glfwButton) noexcept;

}  // namespace Nanoforce::GLFWKeyMapper
