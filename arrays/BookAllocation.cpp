// code run: g++ ./BookAllocation.cpp -o a && .\a.exe

#include <iostream>
#include <vector>
using namespace std;
bool isValid(int maxAllowedPages, vector<int> &nums, int stud)
{
    int requiredStud = 1;
    int allocatedPages = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxAllowedPages)
        {
            return false;
        }
        if (allocatedPages + nums[i] <= maxAllowedPages)
        {
            allocatedPages += nums[i];
        }
        else
        {
            requiredStud++;
            if (requiredStud > stud)
            {
                return false;
            }
            allocatedPages = nums[i];
        }
    }
    return true;
}
int findMinimum(vector<int> &nums, int stud)
{
    int minPossible = 0;
    int maxPossible = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxPossible += nums[i];
        minPossible = max(minPossible, nums[i]);
    }

    int start = minPossible, end = maxPossible;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(mid, nums, stud))
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return start;
}
int main()
{
    vector<int> nums = {10, 20, 30, 40};
    int m = 2;
    int minimumMaxPages = findMinimum(nums, m);
    cout << "Minimum max pages :" << minimumMaxPages;
    return 0;
}