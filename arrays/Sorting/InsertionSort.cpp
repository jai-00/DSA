#include <iostream>
#include <vector>
using namespace std;
void sortArray(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        int curr = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > curr)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = curr;
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
    vector<int> nums = {5, 4, 2, 3, 1};
    cout << "Original: ";
    printArray(nums);
    sortArray(nums);
    cout << "After sorting: ";
    printArray(nums);
    return 0;
}