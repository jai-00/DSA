#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<char> vec = {'a', 'b', 'a', 'a', 'a', 'b', 'b', 'c', 'c', 'a'}; // aba3b2c2a
    int n = vec.size();
    int index = 0;
    int i = 0;
    while (i < n)
    {
        char a = vec[i];
        int count = 0;
        while (i < n && vec[i] == a)
        {
            count++;
            i++;
        }
        vec[index++] = a;
        if (count > 1)
        {
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                vec[index++] = ch;
            }
        }
    }
    cout << index;
    return 0;
}