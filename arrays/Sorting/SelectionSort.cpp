#include <iostream>
#include <vector>
#include <utility>
using namespace std;
void sortArray(vector<int> &nums)
{

    for (int i = 0; i < nums.size() - 1; i++)
    {
        int temp = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[temp])
            {
                temp = j;
            }
        }
        if (temp != i)
        {
            swap(nums[i], nums[temp]);
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
    vector<int> nums = {5, 2, 1, 3, 4};
    cout << "Original : ";
    printArray(nums);
    sortArray(nums);
    cout << "Sorted : ";
    printArray(nums);
    return 0;
}