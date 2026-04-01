#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;
bool isValid(vector<int> &nums, int numberOfCows, int minimumDistanceAllowed)
{
    int currCowCount = 1;
    int lastPlaced = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - lastPlaced >= minimumDistanceAllowed)
        {
            currCowCount++;
            lastPlaced = nums[i];
        }
    }
    return currCowCount >= numberOfCows;
}
int findMaximumMinimumDistance(vector<int> &nums, int numberOfCows)
{
    sort(nums.begin(), nums.end());
    int minPossible = nums[0];
    int highestValue = nums.back();
    int maxPossible = highestValue - minPossible;

    int start = 1;
    int end = maxPossible;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isValid(nums, numberOfCows, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {5, 6, 7};
    int numberOfCows = 3;
    int maxMinimumDistance = findMaximumMinimumDistance(nums, numberOfCows);
    cout << "Maximum Minimum Distance: " << maxMinimumDistance;
    return 0;
}