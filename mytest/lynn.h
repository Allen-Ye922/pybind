#ifndef LYNN_H_
#define LYNN_H_
#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace pybind11::literals;

class test_initializer {
    using Initializer = void (*)(py::module_ &);

public:
    explicit test_initializer(Initializer init);
    test_initializer(const char *submodule_name, Initializer init);
};

#define TEST_SUBMODULE(name, variable)                                                            \
    void test_submodule_##name(py::module_ &);                                                    \
    test_initializer name(#name, test_submodule_##name);                                          \
    void test_submodule_##name(py::module_ &(variable))


#endif // LYNN_H_
