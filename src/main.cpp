#include <pybind11/pybind11.h>
#include "vector3d.h"                                           // добавляю инклюд заголовочного файла vector3d.h

namespace py = pybind11;                                        // для сокращения написания namespace

// PYBIND11_PLUGIN(library) {
//     py::module m("library", "pybind11 library plugin");
PYBIND11_MODULE(library, m) {
    // опциональное описание модуля
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: cmake_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";
    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc", py::arg("x") = 3, py::arg("y") = 4);

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

    m.attr("the_answer") = 77;
    py::object world = py::cast("World");
    m.attr("what") = world;

    py::class_<Pet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def_property("name", &Pet::getName, &Pet::setName)
        .def("__repr__",
            [](const Pet &a) {
                // return "<example.Pet named '" + a.getName() + "'>";
                return "<example.Pet named '" + a.getName() + "'>";
            }
        );

    py::class_<Vector3D>(m, "Vector3D")
        .def(py::init<>())
        .def(py::init<Vector3D&>())
        // .def(py::init<Vector3D&&>())
        .def(py::init<double, double, double>())
        .def_property("X", &Vector3D::getX, &Vector3D::setX)
        .def_property("Y", &Vector3D::getY, &Vector3D::setY)
        .def_property("Z", &Vector3D::getZ, &Vector3D::setZ)
        .def("toString", &Vector3D::toString)
        .def("assign", &Vector3D::operator=)
        .def("__eq__", &Vector3D::operator==)
        .def("length", &Vector3D::magnitude)
        .def("__neg__", py::overload_cast<>(&Vector3D::operator-))
        .def("__sub__", &Vector3D::operator-=)
        .def("__add__", &Vector3D::operator+=)
        .def("__mul__", py::overload_cast<double&>(&Vector3D::operator*=))
        .def("__mul__", py::overload_cast<Vector3D&>(&Vector3D::operator*))
        .def("cross", &Vector3D::cross)
        .def("sum", &Vector3D::sum)
        .def("sub", &Vector3D::sub)
        .def("__truediv__", py::overload_cast<double&>(&Vector3D::operator/=))
        .def("norm", &Vector3D::normalize);
        // .def(py::self + py::self);
    // return m.ptr();
};    