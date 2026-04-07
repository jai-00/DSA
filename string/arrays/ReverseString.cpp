#include <iostream>
#include <string>
using namespace std;
void printArray(char chArr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << chArr[i] << " ";
    }
    cout << endl;
}
int main()
{
    char ch[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};
    int start = 0;
    int n = 0;

    for (int i = 0; ch[i] != '\0'; i++)
    {
        n++;
    }
    printArray(ch, n);
    int end = n - 1;
    while (start < end)
    {
        swap(ch[start++], ch[end--]);
    }
    printArray(ch, n);

    return 0;
}