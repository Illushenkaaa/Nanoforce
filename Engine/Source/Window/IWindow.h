#pragma once

#include "Window/WindowId.h"
#include "Event/Event.h"
#include "Event/InputEvent.h"

#include <string>

namespace Nanoforce
{

class IWindow
{
public:
    virtual ~IWindow() = default;

    // getters
    [[nodiscard]] virtual WindowId                  getId() const       = 0;
    [[nodiscard]] virtual bool                      isValid() const     = 0;
    [[nodiscard]] virtual bool                      shouldClose() const = 0;
    [[nodiscard]] virtual Event<const InputEvent&>& event()             = 0;

    // setters
    virtual void setTitle(const std::string& title) = 0;
};

}  // namespace Nanoforce