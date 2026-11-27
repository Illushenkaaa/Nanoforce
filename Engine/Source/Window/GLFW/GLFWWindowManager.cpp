#include "Window/GLFW/GLFWWindowManager.h"

#include "Log/Log.h"
#include "Window/GLFW/GLFWWindow.h"

#include <GLFW/glfw3.h>

DEFINE_LOG_CATEGORY_STATIC(LogGLFWWindowManager)

namespace Nanoforce
{

GLFWWindowManager::GLFWWindowManager()
{
    // error callback ->
    glfwSetErrorCallback(                           //
        [](int errorCode, const char* description)  //
        {
            NF_LOG(LogGLFWWindowManager, Error, "GLFW error {}: {}", errorCode, description);
        });

    // init ->
    if (glfwInit() != GLFW_TRUE)
    {
        NF_LOG(LogGLFWWindowManager, Error, "Failed to initialize GLFW");
        return;
    }

    // finalize ->
    m_initialized = true;
    NF_LOG(LogGLFWWindowManager, Display, "GLFW initialized");
}

GLFWWindowManager::~GLFWWindowManager()
{
    // destroy windows ->
    m_windows.clear();

    // terminate ->
    if (m_initialized)
    {
        glfwTerminate();
        glfwSetErrorCallback(nullptr);
        m_initialized = false;
    }

    NF_LOG(LogGLFWWindowManager, Display, "GLFW shutdown");
}

void GLFWWindowManager::update()
{
    if (!m_initialized)
    {
        return;
    }

    glfwPollEvents();
    removeClosedWindows();
}

std::expected<WindowId, WindowCreationError> GLFWWindowManager::createWindow(const WindowSettings& settings)
{
    if (!m_initialized)
    {
        NF_LOG(LogGLFWWindowManager, Error, "Cannot create window: GLFW is not initialized");
        return std::unexpected(WindowCreationError::ManagerIsNotInitialized);
    }

    // create window ->
    const WindowId id{m_nextWindowId};
    auto           window = std::make_shared<GLFWWindow>(id, settings);
    if (!window->isValid())
    {
        return std::unexpected(WindowCreationError::CreationFailed);
    }

    // store ->
    ++m_nextWindowId;
    m_windows.emplace(id, std::move(window));
    NF_LOG(LogGLFWWindowManager, Display, "Window {} created", id.value);

    return id;
}

bool GLFWWindowManager::areAllWindowsClosed() const
{
    return m_windows.empty();
}

std::shared_ptr<IWindow> GLFWWindowManager::getWindowById(WindowId id) const
{
    const auto it = m_windows.find(id);
    return it != m_windows.end() ? it->second : nullptr;
}

void GLFWWindowManager::removeClosedWindows()
{
    std::erase_if(m_windows,
        [](const auto& pair)
        {
            const auto& [id, window] = pair;
            if (!window->shouldClose())
            {
                return false;
            }

            NF_LOG(LogGLFWWindowManager, Display, "Window {} closed", id.value);
            return true;
        });
}

}  // namespace Nanoforce