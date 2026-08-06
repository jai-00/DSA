#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool isValid(const vector<int> &nums, int maxAllowedPages, int numberOfStudents)
{
    int requiredNumberOfStudents = 1, pageAllocated = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        pageAllocated = pageAllocated + nums[i];
        if (pageAllocated > maxAllowedPages)
        {
            requiredNumberOfStudents++;
            pageAllocated = nums[i];
        }

        if (requiredNumberOfStudents > numberOfStudents)
            return false;
    }

    return true;
}

int findMinimum(const vector<int> &nums, int numberOfStudents)
{
    int maxPossible = 0;
    int minPossible = 0;

    int i = 0, j = nums.size() - 1;

    while (i <= j)
    {
        maxPossible += nums[i];
        minPossible = max(minPossible, nums[i]);
        i++;
    }

    i = minPossible;
    j = maxPossible;
    int ans = 0;

    while (i <= j)
    {
        int mid = i + ((j - i) / 2);

        if (isValid(nums, mid, numberOfStudents))
        {
            j = mid - 1;
            ans = mid;
        }
        else
        {
            i = mid + 1;
        }
    }

    return ans;
}
int main()
{
    vector<int> nums = {10, 20, 30, 40};
    int k = 2;
    int minimumPossiblePages = findMinimum(nums, k);
    cout << "--------" << endl;
    if (k > nums.size())
    {
        cout << "Answer not Possible" << endl;
    }
    else
    {
        cout << "Lowest possible maximum page for a single student : " << minimumPossiblePages << endl;
    }
    cout << "--------" << endl;
    return 0;
}