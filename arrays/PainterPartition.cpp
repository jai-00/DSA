// code run: g++ PainterPartition.cpp -o a && .\a.exe

#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int> &nums, int numberOfPainters, int maxBlockAllowed)
{
    int requiredNumberOfPainters = 1;
    int blocksAssigned = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (blocksAssigned + nums[i] > maxBlockAllowed)
        {
            requiredNumberOfPainters++;
            if (requiredNumberOfPainters > numberOfPainters)
            {
                return false;
            }
            blocksAssigned = nums[i];
        }
        else
        {
            blocksAssigned += nums[i];
        }
    }
    return true;
}
int findMinimumTime(vector<int> &nums, int numberOfPainters)
{
    int minPossibleTime = 0;
    int maxPossibleTime = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxPossibleTime += nums[i];
        minPossibleTime = max(minPossibleTime, nums[i]);
    }
    int start = minPossibleTime, end = maxPossibleTime;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(nums, numberOfPainters, mid))
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
    vector<int> nums = {10, 20, 10, 40, 10};
    int numberOfPainters = 4;
    int minimumTime = findMinimumTime(nums, numberOfPainters);
    cout << "Minimum Time Taken: " << minimumTime;
    return 0;
}