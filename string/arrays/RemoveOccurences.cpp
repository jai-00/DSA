#include <iostream>
#include <string>
using namespace std;
void removeOccurrence(string &str, string &part)
{
    size_t index;
    while (str.length() > 0 && (index = str.find(part)) != string::npos)
    {
        str.erase(index, part.length());
    }
}
int main()
{
    string str = "daabcbaabcbc";
    string part = "abc";
    removeOccurrence(str, part);
    cout << str;
    return 0;
}