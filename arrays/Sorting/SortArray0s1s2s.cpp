#include <iostream>
#include <vector>
#include <utility>
using namespace std;
void sortArray(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
void printArray(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> nums = {0, 2, 1, 0, 2, 2, 1, 0, 1, 1, 0};
    cout << "Original array: ";
    printArray(nums);
    sortArray(nums);
    cout << "Sorted array: ";
    printArray(nums);
    return 0;
}