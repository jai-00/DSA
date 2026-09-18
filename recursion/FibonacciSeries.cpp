#include <iostream>
using namespace std;
void printFibonacci(int sum, int n, int target)
{
    if (sum > target)
    {

        return;
    }

    cout << sum << " ";
    printFibonacci(sum + n, sum, target);
}
int main()
{
    int target = 13;
    cout << endl
         << "------------------------" << endl;

    printFibonacci(0, 1, target);
    cout << endl
         << "------------------------" << endl;

    return 0;
}