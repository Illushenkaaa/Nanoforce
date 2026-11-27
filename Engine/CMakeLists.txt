project(NanoforceEngine VERSION 0.1.0)

set(ENGINE_SOURCES
    Source/pch.h
    Source/pch.cpp
    Source/main.cpp
    Source/Core/Engine.h
    Source/Core/Engine.cpp
    Source/Core/Filesystem.h
    Source/Core/Filesystem.cpp
    Source/Core/Types.h
    Source/Core/Utility.h
    Source/Event/Event.h
    Source/Event/InputEvent.h
    Source/Log/Log.h
    Source/Log/Log.cpp
)

add_executable(${PROJECT_NAME} ${ENGINE_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE Source)

find_package(spdlog REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER Engine)

setup_compile_options(${PROJECT_NAME})
create_ide_folders(ENGINE_SOURCES)
setup_precompiled_headers(${PROJECT_NAME} Source/pch.cpp Source/pch.h "${ENGINE_SOURCES}")
