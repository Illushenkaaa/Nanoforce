#pragma once

#include "Core/Types.h"
#include "Core/Utility.h"
#include "Window/IWindow.h"
#include "Window/IWindowManager.h"

#include <expected>
#include <memory>
#include <unordered_map>

namespace Nanoforce
{

class GLFWWindowManager final : public IWindowManager, public NonCopyable
{
public:
    explicit GLFWWindowManager();
    ~GLFWWindowManager() override;

    // core
    void                                                       update() override;
    [[nodiscard]] std::expected<WindowId, WindowCreationError> createWindow(const WindowSettings& settings) override;

    // getters
    [[nodiscard]] bool                     areAllWindowsClosed() const override;
    [[nodiscard]] std::shared_ptr<IWindow> getWindowById(WindowId id) const override;

private:
    void removeClosedWindows();

    bool                                                   m_initialized{false};
    std::unordered_map<WindowId, std::shared_ptr<IWindow>> m_windows;
    uint32                                                 m_nextWindowId{0};
};

}  // namespace Nanoforce
