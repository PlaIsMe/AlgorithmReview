#include <algorithm>
#include <vector>
#include <functional>

using std::vector;
using std::swap;

vector<int> selectionSort(vector<int> array)
{
    int min_index;
    for (int i = 0; i < array.size(); i++)
    {
        min_index = i;
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        swap(array[i], array[min_index]);
    }
    return array;
}

vector<int> bubbleSort(vector<int> array)
{
    for (int i = array.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
            }
        }        
    }
    return array;
}

vector<int> insertionSort(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i-1; j >= 0 && array[j] > array[j+1]; j--)
        {
            swap(array[j], array[j+1]);
        }        
    }
    return array;
}

vector<int> interchangeSort(vector<int> array)
{
    for(int i = array.size() - 1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
    return array;
}

vector<int> countingSort(vector<int> array)
{
    auto max_element = std::max_element(array.begin(), array.end());
    vector<int> counting_array(static_cast<int>(*max_element));

    for(int i = 0; i < array.size(); i++)
    {
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

vector<int> heapSort(vector<int> array) {
    std::function<void(int, int)> heapify = [&array, &heapify] (int n, int i)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && array[left] > array[largest])
        {
            largest = left;
        }
        if (right < n && array[right] > array[largest])
        {
            largest = right;
        }
        if (largest != i) {
            swap(array[i], array[largest]);
            heapify(n, largest);
        }
    };

    for(int i = array.size()/2 - 1; i >= 0; i--)
    {
        heapify(array.size(), i);
    }

    for (int i = array.size() - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        heapify(i, 0);
    }

    return array;
}

vector<int> quickSort(vector<int> array) {
    std::function<void(int, int)> quickSortImpl = [&array, &quickSortImpl] (int left, int right) {
        int mid = array[(left + right) / 2];
        int i = left;
        int j = right;
        while(i <= j)
        {
            while (array[i] < mid)
            {
                i++;
            }
            while (array[j] > mid)
            {
                j--;
            }
            if (i <= j)
            {
                swap(array[i], array[j]);
                i++;
                j--;
            }
        }

        if (left < j)
        {
            quickSortImpl(left, j);
        }
        if (i < right)
        {
            quickSortImpl(i, right);
        }
    };

    quickSortImpl(0, array.size() - 1);
    return array;
}

vector<int> mergeSort(vector<int> array)
{
    std::function<void(int, int, int)> merge = [&array] (int left, int mid, int right) {
        int old_left = left;
        //Split the array two 2 arrays
        vector<int> left_array(array.begin() + left, array.begin() + mid + 1);
        vector<int> right_array(array.begin()  + mid + 1, array.begin() + right + 1);
        int step_left = 0, step_right = 0;
        // Merge two array
        while (step_left < left_array.size() && step_right < right_array.size()) {
            // Assign left for the smallest value when compare each elements in two arrays
            if (left_array[step_left] <= right_array[step_right])
            {
                array[left] = left_array[step_left];
                left ++;
                step_left ++;
            } else {
                array[left] = right_array[step_right];
                left++;
                step_right++;
            }
        }
        // Push the remaining elements of left, right array into the main array
        // ONLY IN ONE WHILE LOOP IN TWO WHILE LOOPS BELOW RUN
        while (step_left < left_array.size())
        {
            array[left] = left_array[step_left];
            left ++;
            step_left ++;
        }
        while (step_right < right_array.size())
        {
            array[left] = right_array[step_right];
            left ++;
            step_right ++;
        }
    };

    std::function<void(int, int)> mergeSortImpl = [&array, &mergeSortImpl, merge] (int left, int right) {
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergeSortImpl(left, mid);
        mergeSortImpl(mid + 1, right);
        merge(left, mid, right);
    };

    mergeSortImpl(0, array.size() - 1);
    return array;
}
