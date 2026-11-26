#pragma once

#include "Core/Utility.h"

namespace Nanoforce
{

class Engine final : public NonCopyable
{
public:
    explicit Engine();
    ~Engine();

    // core
    void run();
};

}  // namespace Nanoforce
