#include <iostream>
using namespace std;
int getFibonacciElement(int n, int curr, int sum)
{
    if (n == 1)
        return curr;

    return getFibonacciElement(n - 1, sum, curr + sum);
}
int main()
{
    int target = 7;
    cout << endl
         << "------------------------" << endl;

    int ans = getFibonacciElement(target, 0, 1);
    cout << ans;
    cout << endl
         << "------------------------" << endl;

    return 0;
}