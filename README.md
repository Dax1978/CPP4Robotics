# Практическая работа 1 Сборка первой программы

## Установка IDE и настройка необходимого окружения

1. IDE VSCode у меня уже давно имеется, для написания кода на Python, JavaScript, HTML, CSS  
При этом для работы в C++ создал новый профиль _C++_ в котором и установил соответствующие расширения _(Extensions)_:
* C/C++ Extension Pack (от Microsoft) - который у меня сразу же установил и остальные, которые я перечисляю ни же
* C/C++ Themes (от Microsoft)
* C/C++ (от Microsoft)  
![C/C++](./img/001.png)
* CMake Tools (от Microsoft) - установился с C/C++ Extension Pack
* CMake (от twxs) - установился с C/C++ Extension Pack  
![CMake](./img/002.png)  
Дополнительно были установлены расширения для оформления текста в Markdown  
![Markdown](./img/003.png)  
Для программ микроконтроллеров установил PlatformIO  
![PlatformIO](./img/004.png)  

2. С сайта _cmake.org_ установил CMake с опцией добавления в системные пути для любого пользователя  
![CMake](./img/005.png)  
Проверил его установку WIN+R -> cmd  
![CMake](./img/006.png)  

3. В качестве компилятора предлагалось установить _remote tools for visual studio_, но у меня уже установлен Visual Studio 2022 для написания кода на C++ для Unreal Engine. В связи с чем компилятор в системе уже есть. Не считая ранее установленного MinGW.

## Создание и запуск первой программы

1. Написал код в файле _main.cpp_, выводящий 7 чисел Фибоначи
```C++
#include <iostream>
using namespace std;

long int fibonacchi(int i) {
    int value = 0;
    if(i < 1) return 0;
    if(i == 1) return 1;
    return fibonacchi(i-1) + fibonacchi(i - 2);
}

long int main() {
    int i = 0;

    while(i < 7) {
        cout << "Fibonacchi number " << i + 1 << ": " << fibonacchi(i) << endl;
        i++;
    }

    return 0;
}
```
2. Написал файл сборки CMake _CMakeLists.txt_  
```CMake
# Указание на минимальную версию CMake
cmake_minimum_required(VERSION 3.27)
# Общие сведения о проекте
project(
    pz1                                                 # Название проекта
    VERSION 0.0.0                                       # Номер версии проекта
    DESCRIPTION "Calculate Fibonacchi"                  # Описание проекта
    LANGUAGES CXX                                       # Язык программирования
)
# Указываю версию C++, которую буду использовать. Здесь 17 версия
set(CMAKE_CXX_STANDARD 17)
# Указываю, что хочу вести проверку этого стандарта
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываю сборке, что код надо компилировать в исполняемый файл с наименованием pz1.exe
add_executable(pz1)
# Указываю сборке, что код надо компилировать в статическую библиотеку с наименованием pz1.lib
# add_library(pz1)
# Указываю сборке, что код надо компилировать в дитнамическую библиотеку с наименованием pz1.dll
# add_library(pz1 SHARED)

# Создаю CMake-переменную source, которая содержит список файлов исходного кода (в данном случае main.cpp)
set(sources
    main.cpp
)

# Указываю компилятору, что исполняемый файл будет компилироваться из исходников, перечисленных в моей созданной CMake-переменной sources
target_sources(pz1 PRIVATE ${sources})
```

3. Нажал Build и собрал сборку  

4. Запустил и получил результат  
![Fibonacchi](./img/007.png)  
