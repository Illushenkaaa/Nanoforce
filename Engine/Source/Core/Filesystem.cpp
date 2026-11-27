#include "Core/Filesystem.h"

namespace Nanoforce
{

std::string Filesystem::getFileName(std::string_view path)
{
    return std::filesystem::path(path).filename().string();
}

}  // namespace Nanoforce
