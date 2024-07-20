import pybind11
from distutils.core import setup, Extension

ext_modules = [
    Extension(
        'library',                                              # название нашей либы
        sources = ['./src/vector3d.cpp', './src/main.cpp'],     # файлики которые компилируем
        include_dirs=[pybind11.get_include()],                  # не забываем добавить инклюды pybind11
        language='c++',
        extra_compile_args=['-std=c++17'],                      # используем с++17
    ),
]

setup(
    name='library',
    version='0.0.1',
    author='Dax',
    author_email='John-Xenos@mail.ru',
    description='pybind11 extension for vector3d',
    ext_modules=ext_modules,
    requires=['pybind11']                                       # не забываем указать зависимость от pybind11
)