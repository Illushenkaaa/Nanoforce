project(Sandbox VERSION 0.1.0)

set(SANDBOX_SOURCES
    Source/main.cpp
)

add_executable(${PROJECT_NAME} ${SANDBOX_SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER Engine)

setup_compile_options(${PROJECT_NAME})
create_ide_folders(SANDBOX_SOURCES)
