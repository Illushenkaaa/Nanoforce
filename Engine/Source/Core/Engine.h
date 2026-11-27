#pragma once

#include "Core/Utility.h"
#include "Window/IWindowManager.h"

#include <memory>

namespace Nanoforce
{

class Engine final : public NonCopyable
{
public:
    explicit Engine();
    ~Engine();

    // core
    void run();

private:
    std::unique_ptr<IWindowManager> m_windowManager;
    bool                            m_initialized{false};
};

}  // namespace Nanoforce
