#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int findRotatedArray(const vector<int> &nums, int target)
{
    int i = 0, j = nums.size() - 1;
    while (i <= j)
    {

        int mid = i + ((j - i) / 2);
        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[mid] <= nums[j])
        {
            if (target > nums[mid] && target <= nums[j])
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        else
        {
            if (target < nums[mid] && target >= nums[i])
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {7, 8, 9, 0, 1, 2, 3, 4, 5};

    int target = 3;
    int targetIndex = findRotatedArray(nums, target);
    cout << "------" << endl;
    cout << target
         << " found at index : " << targetIndex << endl;
    cout << "------" << endl;
    return 0;
}