#include "Log/Log.h"

#include "Core/Filesystem.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace
{

[[nodiscard]] spdlog::level::level_enum toSpdlogLevel(Nanoforce::LogVerbosity verbosity)
{
    switch (verbosity)
    {
        case Nanoforce::LogVerbosity::Log:     return spdlog::level::debug;
        case Nanoforce::LogVerbosity::Display: return spdlog::level::info;
        case Nanoforce::LogVerbosity::Warning: return spdlog::level::warn;
        case Nanoforce::LogVerbosity::Error:   return spdlog::level::err;
        case Nanoforce::LogVerbosity::Fatal:   return spdlog::level::critical;
    }
    return spdlog::level::info;
}

[[nodiscard]] bool shouldShowLocation(Nanoforce::LogVerbosity verbosity)
{
    return verbosity >= Nanoforce::LogVerbosity::Warning;
}

}  // namespace

namespace Nanoforce
{

class Log::Impl final : public NonCopyable
{
public:
    explicit Impl()
    {
        m_logger = spdlog::stdout_color_mt("Nanoforce");
        m_logger->set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");
        m_logger->set_level(spdlog::level::trace);
    }

    void log(LogVerbosity verbosity, const std::string& message) const
    {
        const auto level = toSpdlogLevel(verbosity);
        m_logger->log(level, message);
    }

private:
    std::shared_ptr<spdlog::logger> m_logger;
};

Log& Log::getInstance()
{
    static Log instance;
    return instance;
}

Log::Log() : m_impl(std::make_unique<Impl>()) {}

Log::~Log() = default;

void Log::log(const LogCategory& category,   //
    LogVerbosity                 verbosity,  //
    std::string_view             message,    //
    const std::source_location&  location) const
{
    auto line = std::format("{}: {}", category.getName(), message);
    if (shouldShowLocation(verbosity))
    {
        const auto fileName = Filesystem::getFileName(location.file_name());
        line += std::format(" ({}:{})", fileName, location.line());
    }

    m_impl->log(verbosity, line);

    if (verbosity == LogVerbosity::Fatal)
    {
        NF_DEBUG_BREAK();
        std::abort();
    }
}

}  // namespace Nanoforce
