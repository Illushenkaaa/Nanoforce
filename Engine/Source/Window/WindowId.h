#pragma once

#include "Core/Types.h"

#include <functional>
#include <compare>
#include <cstddef>

namespace Nanoforce
{

struct WindowId
{
    uint32 value{0};
    constexpr explicit WindowId(uint32 id = 0) : value(id) {}

    constexpr WindowId operator++(int)
    {
        WindowId temp = *this;
        ++value;
        return temp;
    }

    constexpr auto operator<=>(const WindowId&) const = default;
};
}  // namespace Nanoforce

namespace std
{
template <>
struct hash<Nanoforce::WindowId>
{
    size_t operator()(const Nanoforce::WindowId& id) const noexcept  //
    {
        return std::hash<Nanoforce::uint32>{}(id.value);
    }
};
}  // namespace std