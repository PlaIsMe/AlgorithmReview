#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>
#include "sort.cpp"
#include "search.cpp"

PYBIND11_MODULE(sort_module, m){
    m.doc() = "sort module";
    m.def("selection_sort", &selectionSort, "Selection sort");
    m.def("bubble_sort", &bubbleSort, "Buble sort");
    m.def("insertion_sort", &insertionSort, "Insertion sort");
    m.def("interchange_sort", &interchangeSort, "Interchange sort");
    m.def("counting_sort", &countingSort, "Counting sort");
    m.def("heap_sort", &heapSort, "Heap sort");
    m.def("quick_sort", &quickSort, "Quick sort");
    m.def("merge_sort", &mergeSort, "Merge sort");
}

PYBIND11_MODULE(search_module, m){
    m.doc() = "search module";
    m.def("linear_search", &linearSearch, "Linear search");
    m.def("binary_search", &binarySearch, "Binary search");
}