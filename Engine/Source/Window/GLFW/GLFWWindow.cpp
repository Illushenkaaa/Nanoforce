#include "Window/GLFW/GLFWWindow.h"

#include "Log/Log.h"
#include "Window/GLFW/GLFWKeyMapper.h"

#include <GLFW/glfw3.h>

DEFINE_LOG_CATEGORY_STATIC(LogGLFWWindow)

namespace Nanoforce
{

GLFWWindow::GLFWWindow(WindowId id, const WindowSettings& settings) : m_id(id)
{
    // create window ->
    m_window = glfwCreateWindow(settings.width, settings.height, settings.title.c_str(), nullptr, nullptr);
    if (!m_window)
    {
        NF_LOG(LogGLFWWindow, Error, "Failed to create GLFW window");
        return;
    }
    glfwSetWindowPos(m_window, settings.x, settings.y);

    // user pointer ->
    glfwSetWindowUserPointer(m_window, this);

    // callbacks ->
	glfwSetWindowCloseCallback(m_window,
		[](GLFWwindow* window)
        {
            invokeEvent(window, WindowCloseEventData{});
        });

	glfwSetFramebufferSizeCallback(m_window,
		[](GLFWwindow* window, int width, int height)
        {
            invokeEvent(window, WindowResizeEventData{width, height});
        });

	glfwSetKeyCallback(m_window,
		[](GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/)
        {
            invokeEvent(window, KeyEventData{GLFWKeyMapper::toKey(key), GLFWKeyMapper::toAction(action)});
        });

	glfwSetMouseButtonCallback(m_window,
		[](GLFWwindow* window, int button, int action, int /*mods*/)
		{
            invokeEvent(window, MouseButtonEventData{GLFWKeyMapper::toMouseButton(button), GLFWKeyMapper::toAction(action)});
        });

    glfwSetCursorPosCallback(m_window,
        [](GLFWwindow* window, double x, double y)
        {
            invokeEvent(window, MouseMoveEventData{x, y});
        });

    glfwSetScrollCallback(m_window,
        [](GLFWwindow* window, double xOffset, double yOffset)
        {
            invokeEvent(window, MouseScrollEventData{xOffset, yOffset});
        });
}

GLFWWindow::~GLFWWindow()
{
    if (m_window)
    {
        glfwSetWindowUserPointer(m_window, nullptr);
        glfwDestroyWindow(m_window);
        m_window = nullptr;
    }
}

WindowId GLFWWindow::getId() const
{
    return m_id;
}

bool GLFWWindow::isValid() const
{
    return m_window != nullptr;
}

bool GLFWWindow::shouldClose() const
{
    return !m_window || glfwWindowShouldClose(m_window) == GLFW_TRUE;
}

Event<const InputEvent&>& GLFWWindow::event()
{
    return m_event;
}

void GLFWWindow::setTitle(const std::string& title)
{
    if (m_window)
    {
        glfwSetWindowTitle(m_window, title.c_str());
    }
}

void GLFWWindow::invokeEvent(GLFWwindow* nativeWindow, const EventData& data)
{
    // find window ->
    auto* const window = static_cast<GLFWWindow*>(glfwGetWindowUserPointer(nativeWindow));
    if (!window)
    {
        return;
    }

    // invoke ->
    const InputEvent event{window->m_id, data};
    window->m_event.invoke(event);
}

}  // namespace Nanoforce