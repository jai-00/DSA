//! Running code : g++ SingleElementSorted.cpp -o a && .\a.exe

#include <iostream>
#include <vector>
using namespace std;
int findSingleElement(vector<int> nums)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (mid % 2 != 0)
        {
            mid--;
        }

        if (nums[mid] == nums[mid + 1])
        {
            start = mid + 2;
        }
        else
        {
            end = mid;
        }
    }
    return nums[start];
}
int main()
{
    vector<int> nums = {1, 2, 2, 3, 3, 4, 4, 6, 6};
    int singleElement = findSingleElement(nums);
    cout << "Single Element: " << singleElement;
    return 0;
}