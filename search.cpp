#include <algorithm>
#include <vector>
#include <functional>

using std::vector;

int linearSearch(vector<int> array, int x)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> array, int x)
{
    int left = 0, right = array.size() -1, mid;
    while(left <= right)
    {
        mid = (left + right)/2;
        if (array[mid] == x)
        {
            return mid;
        }
        if (array[mid] < x)
        {
            left = mid + 1;
        }
        if (array[mid] > x)
        {
            right = mid - 1;
        }
    }
    return -1;
}