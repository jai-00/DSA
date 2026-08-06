#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int findSingle(const vector<int> nums)
{
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        int mid = i + ((j - i) / 2);

        if (mid % 2 != 0)
        {
            mid--;
        }

        if (nums[mid] == nums[mid + 1])
        {
            i = mid + 2;
        }
        else
        {
            j = mid;
        }
    }
    return i;
}

int main()
{
    vector<int> nums = {3, 3, 4, 4, 6, 2, 2};
    int singleElementIndex = findSingle(nums);
    cout << "---------" << endl;
    cout << "Single Element : " << nums[singleElementIndex] << " found at index " << singleElementIndex << endl;
    cout << "---------" << endl;

    return 0;
}