#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findNextPermutation(vector<int> &nums)
{
    int pivot = -1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }
    if (pivot == -1)
    {
        // int start = pivot + 1;
        // int end = nums.size() - 1;
        // while (start < end)
        // {
        //     swap(nums[start], nums[end]);
        //     start++;
        //     end--;
        // }
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = nums.size() - 1; i > pivot; i--)
    {
        if (nums[i] > nums[pivot])
        {
            swap(nums[i], nums[pivot]);
            break;
        }
    }
    // int start = pivot + 1;
    // int end = nums.size() - 1;
    // while (start < end)
    // {
    //     swap(nums[start], nums[end]);
    //     start++;
    //     end--;
    // }
    reverse(nums.begin() + (pivot + 1), nums.end());
}
void printArray(vector<int> &nums, string txt, bool space = false)
{
    cout << txt << " : ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    if (space)
    {
        cout << endl;
    }
}
int main()
{
    vector<int> nums = {3, 1, 2, 4, 5, 3, 2, 1};
    printArray(nums, "Original Array", true);
    findNextPermutation(nums);
    printArray(nums, "Next Permutation");
    return 0;
}