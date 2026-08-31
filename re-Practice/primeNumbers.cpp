#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
void printAllPrimeNumber(int maxLimit)
{
    vector<int> primeNumberArray(maxLimit + 1, true);

    primeNumberArray[0] = false;
    primeNumberArray[1] = false;

    for (int i = 2; i * i <= maxLimit; i++)
    {
        if (primeNumberArray[i])
        {

            for (int j = i * i; j <= maxLimit; j += i)
            {
                primeNumberArray[j] = false;
            }
        }
    }

    for (int i = 2; i < maxLimit; i++)
    {
        if (primeNumberArray[i])
        {
            cout << i << " ";
        }
    }
}
int main()
{
    int n;
    cout << endl
         << "----------------------" << endl;
    cout << "\nEnter the max range: ";
    cin >> n;
    cout << endl;
    printAllPrimeNumber(n);
    cout << endl
         << "----------------------" << endl;
    return 0;
}