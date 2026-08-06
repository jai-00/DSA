#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
bool isValidDistance(const vector<int> &nums, int numberOfCows, int possibleMinimumDistance)
{
    int cowsPlaced = 1;
    int cowPlacedDistance = nums[0];

    for (int num : nums)
    {

        if (num - cowPlacedDistance >= possibleMinimumDistance)
        {
            cowsPlaced++;
            cowPlacedDistance = num;
        }
    }

    return cowsPlaced >= numberOfCows;
}
int findMaximumMinimumDistance(vector<int> nums, int numberOfCows)
{
    sort(nums.begin(), nums.end());

    int minimumPossibleDistance = 1;
    int maximumPossibleDistance = nums.back() - nums.front();
    int ans = 1;

    while (minimumPossibleDistance <= maximumPossibleDistance)
    {
        int mid = minimumPossibleDistance + ((maximumPossibleDistance - minimumPossibleDistance) / 2);

        if (isValidDistance(nums, numberOfCows, mid))
        {
            ans = mid;
            minimumPossibleDistance = mid + 1;
        }
        else
        {
            maximumPossibleDistance = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 4, 8, 14};
    int k = 3;

    int maximumMinimumDistance = findMaximumMinimumDistance(nums, k);
    cout << "---------" << endl;
    if (k > nums.size())
    {
        cout << "Number of cows exceed the number of positions";
    }
    else
    {
        cout << "Maximum-minimum distance : " << maximumMinimumDistance << endl;
    }
    cout << "---------" << endl;
    return 0;
}