cmake_minimum_required(VERSION 3.5)                 # Минимальная версия CMake
project(                                            # Информация о проекте
    Matrix                                          # Наименование проекта
    VERSION 0.0.1                                   # Версия проекта
    DESCRIPTION "Matrix class"                      # Описание класса
    LANGUAGES CXX                                   # Указываю, что использую язык C++
)

set(CMAKE_CXX_STANDARD 17)                          # Указыываю, что буду использовать стандарт языка C++ 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)                 # Контроль использования стандарта языка C++ 17 на уровне компилятора
set(CMAKE_BUILD_TYPE Debug)                         # Собирать буду в режиме отладки

add_executable(matrix_class)                        # Собирать буду запускаемый файл matrix_class.exe

set(sources                                         # Перечень исходных файлов, создающих исполняемый файл matrix_class.exe
    src/main.cpp
    
    src/matrix.h
    src/matrix.cpp
)
target_sources(matrix_class PRIVATE ${sources})     # Указываю, что исходные файлы для сборки исполняемого файла matrix_class.exe хранятся в переменной sources

target_include_directories(matrix_class             # Указание, что следует включить текущую дерикторию в директории сборки
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)


# Command Pallete -> CMake: Select a Kit -> Visual Studio Community 2022 Release - amd64 Using compilers for 17.9.0 (x64 architecture)
# Command Pallete -> CMake: Configure