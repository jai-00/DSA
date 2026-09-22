#include <iostream>
#include <vector>
using namespace std;
void printPermutationString(string str, int n)
{
    if (n >= str.size())
    {
        cout << str << " ";
        return;
    }

    for (int i = n; i < str.length(); i++)
    {
        swap(str[i], str[n]);
        printPermutationString(str, n + 1);
        swap(str[i], str[n]);
    }
}
int main()
{
    string str = "abc";

       printPermutationString(str, 0);

    cout << endl;

    return 0;
}