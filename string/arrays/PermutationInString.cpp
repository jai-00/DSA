#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
int main()
{
    string str = "ababab";
    string part = "aab";
    int alpPart[26] = {0};
    int alpStr[26] = {0};
    int m = part.length();
    if (str.length() < part.length())
    {
        cout << "Not Possible";
        return 0;
    }
    for (char ch : part)
    {
        int position = tolower(ch) - 'a';
        alpPart[position]++;
    }
    for (int i = 0; i < m; i++)
    {
        alpStr[(tolower(str[i]) - 'a')]++;
    }

    if (equal(begin(alpPart), end(alpPart), begin(alpStr)))
    {
        cout << "Present";
        return 0;
    }

    for (int i = m; i < str.length(); i++)
    {
        alpStr[tolower(str[i]) - 'a']++;

        alpStr[tolower(str[i - m]) - 'a']--;

        if (equal(begin(alpPart), end(alpPart), begin(alpStr)))
        {
            cout << "Present";
            return 0;
        }
    }
    cout << "Not Present";
    return 0;
}