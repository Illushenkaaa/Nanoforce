#pragma once

#include "Core/Types.h"

#include <string>

namespace Nanoforce
{

struct WindowSettings final
{
    std::string title{"Nanoforce"};
    int32       width{800};
    int32       height{600};
    int32       x{50};
    int32       y{50};
};

}  // namespace Nanoforce