#pragma once

#include "Core/Types.h"

#include <functional>
#include <utility>
#include <vector>

namespace Nanoforce
{

class EventHandle final
{
public:
    constexpr explicit EventHandle(uint64 value = 0) : m_value(value) {}

    // getters
    [[nodiscard]] constexpr uint64 getValue() const { return m_value; }

    // operators
    [[nodiscard]] constexpr auto operator<=>(const EventHandle&) const = default;

private:
    uint64 m_value;
};

template <typename... Args>
class Event final
{
public:
    using Subscriber = std::function<void(Args...)>;

    // core
    [[nodiscard]] EventHandle add(Subscriber subscriber)
    {
        const EventHandle handle{m_nextHandleId++};
        m_subscribers.emplace_back(handle, std::move(subscriber));
        return handle;
    }

    template <typename ObjType, typename RetType>
    [[nodiscard]] EventHandle add(ObjType* obj, RetType (ObjType::*method)(Args...))
    {
        return add([obj, method](Args... args) { (obj->*method)(args...); });
    }

    void remove(EventHandle handle)
    {
        std::erase_if(m_subscribers, [handle](const auto& pair) { return pair.first == handle; });
    }

    void invoke(Args... args) const
    {
        for (const auto& [handle, subscriber] : m_subscribers)
        {
            subscriber(args...);
        }
    }

private:
    std::vector<std::pair<EventHandle, Subscriber>> m_subscribers;
    uint64 m_nextHandleId{0};
};

}  // namespace Nanoforce
