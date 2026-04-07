#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string str;
    cout << "Enter a string : ";
    getline(cin, str);
    int start = 0;
    int end = str.length() - 1;
    bool isPalindrome = true;
    while (start < end)
    {
        if (!isalnum(str[start]))
            start++;
        else if (!isalnum(str[end]))
            end--;
        else if (tolower(str[start]) != tolower(str[end]))
        {
            isPalindrome = false;
            break;
        }
        else
        {
            start++;
            end--;
        }
    }
    cout << (isPalindrome ? "It is a palindrome" : "Not a palindrome");
    return 0;
}