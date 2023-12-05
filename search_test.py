import sys
import unittest
import timeit
import random
from utils import get_module_path
sys.path.append(get_module_path())
import search_module


max_element = 20000
data = [random.randint(1, max_element) for _ in range(max_element)]
search_pos = random.randint(1, max_element)

class TestSortModule(unittest.TestCase):
    def run_search_and_measure_time(self, search_function, test_name):
        start_time = timeit.default_timer()
        sort_data = sorted(data)
        search_result = search_function(sort_data, sort_data[search_pos])
        end_time = timeit.default_timer()

        self.assertEqual(sort_data[search_result], sort_data[search_pos], f"{test_name} failed.")
        print(f"{test_name} test passed successfully. Time taken: {end_time - start_time:.6f} seconds.")

    def test_search(self):
        self.run_search_and_measure_time(search_module.linear_search, "Linear search")
        self.run_search_and_measure_time(search_module.binary_search, "Binary search")

if __name__ == "__main__":
    unittest.main(verbosity=0)