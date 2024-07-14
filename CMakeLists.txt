cmake_minimum_required(VERSION 3.5)                 # Минимальная версия CMake
project(                                            # Информация о проекте
    Matrix                                          # Наименование проекта
    VERSION 0.0.1                                   # Версия проекта
    DESCRIPTION "matrixlib"                         # Описание класса
    LANGUAGES CXX                                   # Указываю, что использую язык C++
)

set(CMAKE_CXX_STANDARD 17)                          # Указыываю, что буду использовать стандарт языка C++ 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)                 # Контроль использования стандарта языка C++ 17 на уровне компилятора
set(CMAKE_BUILD_TYPE Debug)                         # Собирать буду в режиме отладки
set(MATH_USE_DOUBLE_PRECISION "Use double precision" ON)
set(sources                                         # Перечень исходных файлов, создающих исполняемый файл matrix_class.exe
    src/matrix.h
    src/matrix.cpp

    src/export.h
    src/c/c_api.h
    src/c/c_api.cpp
)

include(GenerateExportHeader)

add_library(static-matrixlib STATIC ${sources})     # Планирую создать статическую библиотеку static-matrixlib
target_include_directories(static-matrixlib         # Указание, что следует включить текущую дерикторию в директории сборки
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
# В случае сборки статитческой библиотеки передаем компилятору MATH_STATIC_DEFINE
target_compile_definitions(
    static-matrixlib
    PUBLIC
        MATH_STATIC_DEFINE
        "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)
# Что бы компилятор не добавлял префик "lib" к имени библиотеки
set_target_properties(static-matrixlib PROPERTIES PREFIX "")
generate_export_header(
    static-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_static.h"
    BASE_NAME matrixlib
)

# Тест использования статической библиотеки
add_executable(
    test-static-matrix
    src/test/test-static-matrix.cpp
)
target_include_directories(test-static-matrix         # Указание, что следует включить текущую дерикторию в директории сборки
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
target_link_libraries(test-static-matrix PRIVATE static-matrixlib)






add_library(shared-matrixlib SHARED ${sources})     # Планирую создать динамическую библиотеку shared-matrixlib
target_include_directories(shared-matrixlib         # Указание, что следует включить текущую дерикторию в директории сборки
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
target_compile_definitions(
    shared-matrixlib
    PUBLIC
        "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)
# Что бы компилятор не добавлял префик "lib" к имени библиотеки
set_target_properties(shared-matrixlib PROPERTIES PREFIX "")
generate_export_header(
    shared-matrixlib
    EXPORT_FILE_NAME "${PROJECT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrixlib
)

# Тест использования динамической библиотеки
add_executable(
    test-shared-matrix
    src/test/test-shared-matrix.cpp
)
target_include_directories(test-shared-matrix         # Указание, что следует включить текущую дерикторию в директории сборки
    PUBLIC
        "<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)
target_link_libraries(test-shared-matrix PRIVATE shared-matrixlib)



# Command Pallete -> CMake: Select a Kit -> Visual Studio Community 2022 Release - amd64 Using compilers for 17.9.0 (x64 architecture)
# Command Pallete -> CMake: Configure