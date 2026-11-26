#include "Core/Filesystem.h"

#include <filesystem>

namespace Nanoforce
{

std::string Filesystem::getFileName(std::string_view path)
{
    return std::filesystem::path(path).filename().string();
}

}  // namespace Nanoforce
