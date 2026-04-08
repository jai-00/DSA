#include <iostream>

#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s = "   hello   world    this is my name  jai   ";
    string ans;
    int n = s.length();
    cout << endl
         << "Original String :" << '"' << s << '"' << endl;
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++)
    {
        string word;
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if (word.length() > 0)
        {
            ans += " " + word;
        }
    }
    ans = ans.substr(1);
    cout << "Reversed String :" << '"' << ans << '"' << endl;
    return 0;
}