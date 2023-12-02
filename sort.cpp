#include <algorithm>
#include <vector>

using std::vector;
using std::swap;

vector<int> selectionSort(vector<int> array) {
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
    return array;
}

vector<int> bubbleSort(vector<int> array) {
    for (int i = array.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }        
    }
    return array;
}

vector<int> insertionSort(vector<int> array) {
    for (int i = 0; i < array.size(); i++) {
        for (int j = i-1; j >= 0 && array[j] > array[j+1]; j--) {
            swap(array[j], array[j+1]);
        }        
    }
    return array;
}

vector<int> interchangeSort(vector<int> array) {
    for(int i = array.size() - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
    return array;
}

vector<int> countingSort(vector<int> array) {
    auto max_element = std::max_element(array.begin(), array.end());
    vector<int> counting_array(static_cast<int>(*max_element));

    for(int i = 0; i < array.size(); i++) {
        counting_array[array[i] - 1]++;
    }

    int sort_index = 0;
    for (int i = 0; i < counting_array.size(); i++)
    {
        while (counting_array[i] > 0)
        {
            array[sort_index] = i + 1;
            sort_index++;
            counting_array[i]--;
        }
    }

    return array;
}