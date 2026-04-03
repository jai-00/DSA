#include <iostream>
#include <vector>
#include <utility>
using namespace std;
void sortArray(vector<int> &nums)
{
    bool hasSwapped = false;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = 0; j < nums.size() - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                hasSwapped = true;
            }
        }
        if (!hasSwapped)
        {
            cout << "Array already sorted" << endl;
            return;
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
    vector<int> nums = {1, 2, 4, 3, 5};
    cout << "Original : ";
    printArray(nums);
    sortArray(nums);
    cout << "Sorted : ";
    printArray(nums);
    return 0;
}