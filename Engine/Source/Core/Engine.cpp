#include "Core/Engine.h"

#include "Log/Log.h"
#include "Window/WindowSettings.h"
#include "Window/GLFW/GLFWWindowManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogEngine)

namespace Nanoforce
{

Engine::Engine()
{
    NF_LOG(LogEngine, Display, "Engine start...");

    // create managers ->
    m_windowManager = std::make_unique<GLFWWindowManager>();

    // create main window ->
    const auto windowResult = m_windowManager->createWindow(WindowSettings{});
    if (!windowResult)
    {
        NF_LOG(LogEngine, Error, "Failed to create main window");
        return;
    }

    // finalize ->
    m_initialized = true;
}

Engine::~Engine()
{
    NF_LOG(LogEngine, Display, "Engine shutdown...");
}

void Engine::run()
{
    while (!m_windowManager->areAllWindowsClosed())
    {
        m_windowManager->update();
    }
}

}  // namespace Nanoforce
