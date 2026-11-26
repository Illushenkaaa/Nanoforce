project(NanoforceEngine VERSION 0.1.0)

set(ENGINE_SOURCES
    Source/pch.h
    Source/pch.cpp
    Source/main.cpp
)

add_executable(${PROJECT_NAME} ${ENGINE_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE Source)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER Engine)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /external:anglebrackets /external:W0 /permissive- /Zc:preprocessor /utf-8)
endif()

create_ide_folders(ENGINE_SOURCES)
setup_precompiled_headers(${PROJECT_NAME} Source/pch.cpp Source/pch.h "${ENGINE_SOURCES}")
