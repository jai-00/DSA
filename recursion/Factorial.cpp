#include <iostream>
using namespace std;
int calculateFactorial(int n)
{

    if (n == 0)
    {
        return 1;
    }

    return n * calculateFactorial(n - 1);
}
int main()
{
    int n = 5;
    int ans = calculateFactorial(n);
    cout << endl
         << "------------------------" << endl;
    cout << "Factorial of " << n << " : " << ans;
    cout << endl
         << "------------------------" << endl;

    return 0;
}