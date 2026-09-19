#include <iostream>
using namespace std;
int getFibonacciElement(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return getFibonacciElement(n - 1) + getFibonacciElement(n - 2);
}
int main()
{
    int target = 5;
    cout << endl
         << "------------------------" << endl;

    int ans = getFibonacciElement(target);
    cout << ans;
    cout << endl
         << "------------------------" << endl;

    return 0;
}