#pragma once

#include <string>
#include <string_view>

namespace Nanoforce
{

class Filesystem final
{
public:
    [[nodiscard]] static std::string getFileName(std::string_view path);
};

}  // namespace Nanoforce
