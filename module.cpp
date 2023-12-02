// #include <pybind11/pybind11.h>
#include "sort.cpp"


PYBIND11_MODULE(sort_module, m){
    m.doc() = "sort module";
    m.def("selection_sort", &Sort::selectionSort, "Selection sort");
}