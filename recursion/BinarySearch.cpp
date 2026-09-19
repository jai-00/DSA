#include <iostream>
#include <vector>

using namespace std;
int search(vector<int> &arr, int st, int end, int target)
{
    if (st > end)
    {
        return -1;
    }

    int mid = st + ((end - st) / 2);
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return search(arr, mid + 1, end, target);
    }
    else
    {
        return search(arr, st, mid - 1, target);
    }
}
int binarySearch(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int position = search(arr, start, end, target);
    return position;
}
int main()
{
    vector<int> arr = {2, 4, 5, 6, 7, 8};
    int target = 7;
    cout << endl
         << "------------------------" << endl;
    int position = binarySearch(arr, target);
    cout << target << " found at : " << position << " index.";
    cout << endl
         << "------------------------" << endl;

    return 0;
}