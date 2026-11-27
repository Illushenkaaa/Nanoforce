#pragma once

#include "Core/Types.h"

#include <format>
#include <string_view>
#include <type_traits>
#include <variant>

namespace Nanoforce
{

// enums
enum class EventType : uint8
{
    None = 0,
    WindowClose,
    WindowResize,
    Key,
    MouseButton,
    MouseMove,
    MouseScroll
};

enum class InputAction : uint8
{
    Unknown = 0,
    Release,
    Press,
    Repeat
};

enum class Key : uint16
{
    None = 0,
    Unknown,

    Esc,
    Enter,
    Space,
    Tab,
    Backspace,

    Up,
    Down,
    Left,
    Right,

    Key0,
    Key1,
    Key2,
    Key3,
    Key4,
    Key5,
    Key6,
    Key7,
    Key8,
    Key9,

    KeyA,
    KeyB,
    KeyC,
    KeyD,
    KeyE,
    KeyF,
    KeyG,
    KeyH,
    KeyI,
    KeyJ,
    KeyK,
    KeyL,
    KeyM,
    KeyN,
    KeyO,
    KeyP,
    KeyQ,
    KeyR,
    KeyS,
    KeyT,
    KeyU,
    KeyV,
    KeyW,
    KeyX,
    KeyY,
    KeyZ,

    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,

    LeftShift,
    RightShift,
    LeftCtrl,
    RightCtrl,
    LeftAlt,
    RightAlt,

    Count
};

enum class MouseButtonType : uint8
{
    None = 0,
    Left,
    Middle,
    Right
};

// event data
class WindowCloseEventData final
{
public:
    constexpr explicit WindowCloseEventData() = default;
};

class WindowResizeEventData final
{
public:
    constexpr explicit WindowResizeEventData(int32 width, int32 height) : m_width(width), m_height(height) {}

    // getters
    [[nodiscard]] constexpr int32 getWidth() const { return m_width; }
    [[nodiscard]] constexpr int32 getHeight() const { return m_height; }

private:
    int32 m_width;
    int32 m_height;
};

class KeyEventData final
{
public:
    constexpr explicit KeyEventData(Key key, InputAction action) : m_key(key), m_action(action) {}

    // getters
    [[nodiscard]] constexpr Key getKey() const { return m_key; }
    [[nodiscard]] constexpr InputAction getAction() const { return m_action; }

private:
    Key m_key;
    InputAction m_action;
};

class MouseButtonEventData final
{
public:
    constexpr explicit MouseButtonEventData(MouseButtonType button, InputAction action) : m_button(button), m_action(action) {}

    // getters
    [[nodiscard]] constexpr MouseButtonType getButton() const { return m_button; }
    [[nodiscard]] constexpr InputAction getAction() const { return m_action; }

private:
    MouseButtonType m_button;
    InputAction m_action;
};

class MouseMoveEventData final
{
public:
    constexpr explicit MouseMoveEventData(double x, double y) : m_x(x), m_y(y) {}

    // getters
    [[nodiscard]] constexpr double getX() const { return m_x; }
    [[nodiscard]] constexpr double getY() const { return m_y; }

private:
    double m_x;
    double m_y;
};

class MouseScrollEventData final
{
public:
    constexpr explicit MouseScrollEventData(double xOffset, double yOffset) : m_xOffset(xOffset), m_yOffset(yOffset) {}

    // getters
    [[nodiscard]] constexpr double getXOffset() const { return m_xOffset; }
    [[nodiscard]] constexpr double getYOffset() const { return m_yOffset; }

private:
    double m_xOffset;
    double m_yOffset;
};

// order must match EventType
using EventData = std::variant<std::monostate,  //
                               WindowCloseEventData,
                               WindowResizeEventData,
                               KeyEventData,
                               MouseButtonEventData,
                               MouseMoveEventData,
                               MouseScrollEventData>;

template <EventType Type, typename Data>
constexpr bool eventDataMatches = std::is_same_v<std::variant_alternative_t<static_cast<std::size_t>(Type), EventData>, Data>;

static_assert(eventDataMatches<EventType::None, std::monostate>);
static_assert(eventDataMatches<EventType::WindowClose, WindowCloseEventData>);
static_assert(eventDataMatches<EventType::WindowResize, WindowResizeEventData>);
static_assert(eventDataMatches<EventType::Key, KeyEventData>);
static_assert(eventDataMatches<EventType::MouseButton, MouseButtonEventData>);
static_assert(eventDataMatches<EventType::MouseMove, MouseMoveEventData>);
static_assert(eventDataMatches<EventType::MouseScroll, MouseScrollEventData>);

class InputEvent final
{
public:
    constexpr explicit InputEvent(EventData data) : m_data(data) {}

    // getters
    [[nodiscard]] constexpr const EventData& getData() const { return m_data; }
    [[nodiscard]] constexpr EventType getType() const { return static_cast<EventType>(m_data.index()); }

private:
    EventData m_data;
};

// to string
[[nodiscard]] constexpr std::string_view toString(EventType type)
{
    switch (type)
    {
        case EventType::None: return "None";
        case EventType::WindowClose: return "WindowClose";
        case EventType::WindowResize: return "WindowResize";
        case EventType::Key: return "Key";
        case EventType::MouseButton: return "MouseButton";
        case EventType::MouseMove: return "MouseMove";
        case EventType::MouseScroll: return "MouseScroll";
    }
    return "Unknown";
}

[[nodiscard]] constexpr std::string_view toString(InputAction action)
{
    switch (action)
    {
        case InputAction::Unknown: return "Unknown";
        case InputAction::Release: return "Release";
        case InputAction::Press: return "Press";
        case InputAction::Repeat: return "Repeat";
    }
    return "Unknown";
}

[[nodiscard]] constexpr std::string_view toString(MouseButtonType button)
{
    switch (button)
    {
        case MouseButtonType::None: return "None";
        case MouseButtonType::Left: return "Left";
        case MouseButtonType::Middle: return "Middle";
        case MouseButtonType::Right: return "Right";
    }
    return "Unknown";
}

[[nodiscard]] constexpr std::string_view toString(Key key)
{
    switch (key)
    {
        case Key::None: return "None";
        case Key::Unknown: return "Unknown";
        case Key::Esc: return "Esc";
        case Key::Enter: return "Enter";
        case Key::Space: return "Space";
        case Key::Tab: return "Tab";
        case Key::Backspace: return "Backspace";
        case Key::Up: return "Up";
        case Key::Down: return "Down";
        case Key::Left: return "Left";
        case Key::Right: return "Right";
        case Key::Key0: return "Key0";
        case Key::Key1: return "Key1";
        case Key::Key2: return "Key2";
        case Key::Key3: return "Key3";
        case Key::Key4: return "Key4";
        case Key::Key5: return "Key5";
        case Key::Key6: return "Key6";
        case Key::Key7: return "Key7";
        case Key::Key8: return "Key8";
        case Key::Key9: return "Key9";
        case Key::KeyA: return "KeyA";
        case Key::KeyB: return "KeyB";
        case Key::KeyC: return "KeyC";
        case Key::KeyD: return "KeyD";
        case Key::KeyE: return "KeyE";
        case Key::KeyF: return "KeyF";
        case Key::KeyG: return "KeyG";
        case Key::KeyH: return "KeyH";
        case Key::KeyI: return "KeyI";
        case Key::KeyJ: return "KeyJ";
        case Key::KeyK: return "KeyK";
        case Key::KeyL: return "KeyL";
        case Key::KeyM: return "KeyM";
        case Key::KeyN: return "KeyN";
        case Key::KeyO: return "KeyO";
        case Key::KeyP: return "KeyP";
        case Key::KeyQ: return "KeyQ";
        case Key::KeyR: return "KeyR";
        case Key::KeyS: return "KeyS";
        case Key::KeyT: return "KeyT";
        case Key::KeyU: return "KeyU";
        case Key::KeyV: return "KeyV";
        case Key::KeyW: return "KeyW";
        case Key::KeyX: return "KeyX";
        case Key::KeyY: return "KeyY";
        case Key::KeyZ: return "KeyZ";
        case Key::F1: return "F1";
        case Key::F2: return "F2";
        case Key::F3: return "F3";
        case Key::F4: return "F4";
        case Key::F5: return "F5";
        case Key::F6: return "F6";
        case Key::F7: return "F7";
        case Key::F8: return "F8";
        case Key::F9: return "F9";
        case Key::F10: return "F10";
        case Key::F11: return "F11";
        case Key::F12: return "F12";
        case Key::LeftShift: return "LeftShift";
        case Key::RightShift: return "RightShift";
        case Key::LeftCtrl: return "LeftCtrl";
        case Key::RightCtrl: return "RightCtrl";
        case Key::LeftAlt: return "LeftAlt";
        case Key::RightAlt: return "RightAlt";
        case Key::Count: break;
    }
    return "Unknown";
}

}  // namespace Nanoforce

// formatters
template <>
struct std::formatter<Nanoforce::EventType> : std::formatter<std::string_view>
{
    auto format(Nanoforce::EventType type, std::format_context& context) const
    {
        return std::formatter<std::string_view>::format(Nanoforce::toString(type), context);
    }
};

template <>
struct std::formatter<Nanoforce::InputAction> : std::formatter<std::string_view>
{
    auto format(Nanoforce::InputAction action, std::format_context& context) const
    {
        return std::formatter<std::string_view>::format(Nanoforce::toString(action), context);
    }
};

template <>
struct std::formatter<Nanoforce::MouseButtonType> : std::formatter<std::string_view>
{
    auto format(Nanoforce::MouseButtonType button, std::format_context& context) const
    {
        return std::formatter<std::string_view>::format(Nanoforce::toString(button), context);
    }
};

template <>
struct std::formatter<Nanoforce::Key> : std::formatter<std::string_view>
{
    auto format(Nanoforce::Key key, std::format_context& context) const
    {
        return std::formatter<std::string_view>::format(Nanoforce::toString(key), context);
    }
};
