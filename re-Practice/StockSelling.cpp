#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    vector<int> nums = {8, 1, 4, 9, 3, 4, 7};
    int buyingPrice = INT_MAX, maxProfit = INT_MIN;
    for (int num : nums)
    {
        if (buyingPrice > num)
        {
            buyingPrice = num;
        }

        int profit = num - buyingPrice;
        maxProfit = max(profit, maxProfit);
    }

    cout << "\nMax Profit: " << maxProfit << endl
         << endl;
    return 0;
}