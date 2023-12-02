import sys
import unittest
import timeit
from utils import get_module_path
sys.path.append(get_module_path())
import sort_module

data = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
expected_result = [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9]

class TestSortModule(unittest.TestCase):
    def run_test_and_measure_time(self, sort_function, test_name):
        start_time = timeit.default_timer()
        sort_data = sort_function(data)
        end_time = timeit.default_timer()

        self.assertEqual(sort_data, expected_result, f"{test_name} failed.")
        print(f"{test_name} test passed successfully. Time taken: {end_time - start_time:.6f} seconds.")

    def test_selection_sort(self):
        self.run_test_and_measure_time(sort_module.selection_sort, "Selection sort")
    
    def test_bubble_sort(self):
        self.run_test_and_measure_time(sort_module.bubble_sort, "Bubble sort")

    def test_insertion_sort(self):
        self.run_test_and_measure_time(sort_module.insertion_sort, "Insertion sort")

    def test_interchange_sort(self):
        self.run_test_and_measure_time(sort_module.interchange_sort, "Interchange sort")

    def test_couting_sort(self):
        self.run_test_and_measure_time(sort_module.counting_sort, "Counting sort")

if __name__ == "__main__":
    unittest.main(verbosity=0)