#include <algorithm>
#include <vector>

using std::vector;
using std::swap;

void selectionSort(vector<int> array) {
    int min_index;
    for (int i = 0; i < array.size(); i++) {
        min_index = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        swap(array[i], array[min_index]);
    }
}