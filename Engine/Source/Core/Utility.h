#pragma once

namespace Nanoforce
{

class NonCopyable
{
protected:
    explicit NonCopyable() = default;
    ~NonCopyable()         = default;

    NonCopyable(const NonCopyable&)            = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};

}  // namespace Nanoforce

#if defined(_MSC_VER)
#define NF_DEBUG_BREAK() __debugbreak()
#else
#include <csignal>
#define NF_DEBUG_BREAK() std::raise(SIGTRAP)
#endif
