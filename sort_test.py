import sys
import unittest
import timeit
import random
from utils import get_module_path
sys.path.append(get_module_path())
import sort_module


max_element = 10000
data = [random.randint(1, max_element) for _ in range(max_element)]

class TestSortModule(unittest.TestCase):
    def run_sort_and_measure_time(self, sort_function, test_name):
        start_time = timeit.default_timer()
        sort_data = sort_function(data)
        end_time = timeit.default_timer()

        self.assertEqual(sort_data, sorted(data), f"{test_name} failed.")
        print(f"{test_name} test passed successfully. Time taken: {end_time - start_time:.6f} seconds.")

    def test_sort(self):
        self.run_sort_and_measure_time(sort_module.selection_sort, "Selection sort")
        self.run_sort_and_measure_time(sort_module.bubble_sort, "Bubble sort")
        self.run_sort_and_measure_time(sort_module.insertion_sort, "Insertion sort")
        self.run_sort_and_measure_time(sort_module.interchange_sort, "Interchange sort")
        self.run_sort_and_measure_time(sort_module.counting_sort, "Counting sort")
        self.run_sort_and_measure_time(sort_module.heap_sort, "Heap sort")
        self.run_sort_and_measure_time(sort_module.quick_sort, "Quick sort")
        self.run_sort_and_measure_time(sort_module.merge_sort, "Merge sort")

if __name__ == "__main__":
    unittest.main(verbosity=0)