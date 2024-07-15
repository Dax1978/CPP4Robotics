cmake_minimum_required(VERSION 3.5)
project(
    snake
    VERSION 0.0.1                                   # Версия проекта
    DESCRIPTION "Snake Qt5"
    LANGUAGES CXX
)

set(CMAKE_AUTOUIC ON)   
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Для Windows
set(LINK_FLAGS "-mwindows -mconsole -Wl,-subsystem,console")
set(sources
    src/game.h
    src/game.cpp
    src/main.cpp
)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# add_executable(test main.cpp)
# Для Windows
add_executable(snake WIN32 ${sources})
target_link_libraries(snake PRIVATE Qt5::Core Qt5::Widgets ${LINK_FLAGS})
# Для Windows
set_property(TARGET snake PROPERTY WIN32_EXECUTABLE true)

