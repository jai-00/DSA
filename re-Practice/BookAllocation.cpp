#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int findMinimum(const vector<int> &nums, int numberOfStudents)
{
}
int main()
{
    vector<int> nums = {10, 20, 30, 40};
    int k = 2;
    int minimumPossiblePages = findMinimum(nums, k);
    cout << "--------" << endl;
    cout << "Lowest possible page for a single student : " << minimumPossiblePages << endl;
    cout << "--------" << endl;
    return 0;
}