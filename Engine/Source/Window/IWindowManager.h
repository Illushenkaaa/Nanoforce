#pragma once

#include "Core/Types.h"
#include "Window/IWindow.h"
#include "Window/WindowSettings.h"

#include <expected>
#include <memory>

namespace Nanoforce
{

enum class WindowCreationError : uint8
{
    ManagerIsNotInitialized,
    CreationFailed
};

class IWindowManager
{
public:
    virtual ~IWindowManager() = default;

    // core
    virtual void                                                       update()                                     = 0;
    [[nodiscard]] virtual std::expected<WindowId, WindowCreationError> createWindow(const WindowSettings& settings) = 0;

    // getters
    [[nodiscard]] virtual bool                     areAllWindowsClosed() const      = 0;
    [[nodiscard]] virtual std::shared_ptr<IWindow> getWindowById(WindowId id) const = 0;
};

}  // namespace Nanoforce
