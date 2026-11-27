#pragma once

#include "Core/Utility.h"
#include "Event/Event.h"
#include "Event/InputEvent.h"
#include "Window/IWindow.h"
#include "Window/WindowId.h"
#include "Window/WindowSettings.h"

#include <string>

struct GLFWwindow;

namespace Nanoforce
{

class GLFWWindow final : public IWindow, public NonCopyable
{
public:
    explicit GLFWWindow(WindowId id, const WindowSettings& settings);
    ~GLFWWindow() override;

    // getters
    [[nodiscard]] WindowId                  getId() const override;
    [[nodiscard]] bool                      isValid() const override;
    [[nodiscard]] bool                      shouldClose() const override;
    [[nodiscard]] Event<const InputEvent&>& event() override;

    // setters
    void setTitle(const std::string& title) override;

private:
    static void invokeEvent(GLFWwindow* nativeWindow, const EventData& data);

    WindowId                 m_id;
    GLFWwindow*              m_window{nullptr};
    Event<const InputEvent&> m_event;
};

}  // namespace Nanoforce