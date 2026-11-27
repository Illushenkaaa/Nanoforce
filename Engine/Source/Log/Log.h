#pragma once

#include "Core/Types.h"
#include "Core/Utility.h"

#include <concepts>
#include <format>
#include <memory>
#include <source_location>
#include <string>
#include <string_view>

namespace Nanoforce
{

enum class LogVerbosity : uint8
{
    Log,
    Display,
    Warning,
    Error,
    Fatal
};

class LogCategory final
{
public:
    constexpr explicit LogCategory(std::string_view name) : m_name(name) {}

    // getters
    [[nodiscard]] constexpr std::string_view getName() const { return m_name; }

private:
    std::string_view m_name;
};

class Log final : public NonCopyable
{
public:
    // core
    [[nodiscard]] static Log& getInstance();

    void log(const LogCategory&     category,   //
        LogVerbosity                verbosity,  //
        std::string_view            message,    //
        const std::source_location& location) const;

private:
    explicit Log();
    ~Log();

    class Impl;
    std::unique_ptr<Impl> m_impl;
};

// concepts
constexpr LogVerbosity minLogVerbosity = LogVerbosity::Log;
constexpr LogVerbosity maxLogVerbosity = LogVerbosity::Fatal;

template <typename T>
concept LoggableMessage = std::convertible_to<T, std::string> || std::convertible_to<T, std::string_view>;

template <LogVerbosity V>
concept ValidLogVerbosity = V >= minLogVerbosity && V <= maxLogVerbosity;

template <typename T>
concept ValidLogCategory = std::constructible_from<LogCategory, T>;

}  // namespace Nanoforce

#define DEFINE_LOG_CATEGORY_STATIC(categoryName)                  \
    namespace                                                     \
    {                                                             \
    constexpr Nanoforce::LogCategory categoryName{#categoryName}; \
    }

#define NF_LOG(categoryName, verbosity, formatString, ...)                                                                               \
    do                                                                                                                                   \
    {                                                                                                                                    \
        static_assert(Nanoforce::ValidLogCategory<decltype(categoryName)>, "Category must be declared with DEFINE_LOG_CATEGORY_STATIC"); \
        static_assert(Nanoforce::ValidLogVerbosity<Nanoforce::LogVerbosity::verbosity>, "Verbosity must be between Log and Fatal");      \
        static_assert(Nanoforce::LoggableMessage<decltype(formatString)>, "Message must be convertible to string");                      \
        Nanoforce::Log::getInstance().log(categoryName, Nanoforce::LogVerbosity::verbosity,                                              \
            std::format(formatString __VA_OPT__(, ) __VA_ARGS__), std::source_location::current());                                      \
    } while (0)
