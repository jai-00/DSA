#include <iostream>
#include <vector>
using namespace std;
int searchTarget(const vector<int> &nums, int target)
{
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)
    {
        int mid = i + ((j - i) / 2);

        if (target < nums[mid])
        {
            j = mid - 1;
        }
        else if (target > nums[mid])
        {
            i = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 9};
    int target = 9;
    int targetIndex = searchTarget(nums, target);

    cout << endl
         << target << " found at index " << targetIndex << endl;
    return 0;
}
