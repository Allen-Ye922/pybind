#include "lynn.h"

#include <functional>
#include <list>

std::list<std::function<void(py::module_ &)>> &initializers() {
    static std::list<std::function<void(py::module_ &)>> inits;
    return inits;
}

test_initializer::test_initializer(Initializer init) { initializers().emplace_back(init); }

test_initializer::test_initializer(const char *submodule_name, Initializer init) {
    initializers().emplace_back([=](py::module_ &parent) {
        auto m = parent.def_submodule(submodule_name);
        init(m);
    });
}



PYBIND11_MODULE(Lynn, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring


    for (const auto &initializer : initializers()) {
        initializer(m);
    }

}
