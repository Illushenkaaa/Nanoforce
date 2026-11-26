#include "Core/Engine.h"

#include "Log/Log.h"

DEFINE_LOG_CATEGORY_STATIC(LogEngine)

namespace Nanoforce
{

Engine::Engine()
{
    NF_LOG(LogEngine, Display, "Engine started");
}

Engine::~Engine()
{
    NF_LOG(LogEngine, Display, "Engine shutdown");
}

void Engine::run()
{
    while (true)
    {
    }
}

}  // namespace Nanoforce
