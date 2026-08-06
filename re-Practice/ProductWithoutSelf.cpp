#include <iostream>
#include <vector>
using namespace std;
vector<int> calculateAnswer(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n);

    ans[0] = 1;

    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = nums[i + 1] * ans[i];
        nums[i] = nums[i] * nums[i + 1];
    }

    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = calculateAnswer(nums);

    cout << "-------" << endl;

    for (int num : ans)
    {
        cout << " " << num;
    }

    cout << endl
         << "-------" << endl;
    return 0;
}