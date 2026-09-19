#include <iostream>
#include <vector>
using namespace std;
bool helperFunction(vector<int> &arr, int n)
{
    if (n <= 0)
        return true;

    return (arr[n - 1] <= arr[n] && helperFunction(arr, n - 1));
}

bool isSequence(vector<int> &arr)
{
    return helperFunction(arr, arr.size() - 1);
}

int main()
{
    vector<int> arr = {2, 5, 5, 8, 9};
    cout << endl
         << "------------------------" << endl;
    bool isInSequence = isSequence(arr);
    cout << "Is the array in sequence: " << (isInSequence ? "True" : "False");
    cout << endl
         << "------------------------" << endl;

    return 0;
}