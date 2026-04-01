#include <iostream>
using namespace std;
int main()
{
    int x = 2, n = 5, ans = 1; // ans = x^n
    cout << x << " raised to the power of " << n << " = ";
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = ans * x;
        }
        x = x * x;
        n = n / 2;
    }
    cout << ans;
    return 0;
}
