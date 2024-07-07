cmake_minimum_required(VERSION 3.5)
project(
    module5
    VERSION 0.0.1
    DESCRIPTION "Car class"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)              # Используется стандарт C++ 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # Проверка использования стандарта. При использовании другого, компилятор матернется
set(CMAKE_BUILD_TYPE Debug)             # Собираю в режиме отладки

# add_executable(${PROJECT_NAME} "src/main.cpp")
# target_include_directories(${PROJECT_NAME} PRIVATE include)
# target_link_libraries()

add_executable(car_class)               # Создавать буду car_class
set(sources                             # Создаю переменную sources
    src/main.cpp

    src/car.h                           # Указываю в переменную файл, входящий в car_class
    src/car.cpp
    src/lorry.h
    src/lorry.cpp
)

# Указываю, что для моего исолняемого файла car_class исходные файлы хранятся в переменной sources
target_sources(car_class PRIVATE ${sources})

target_include_directories(car_class
    PUBLIC
       "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
       "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)