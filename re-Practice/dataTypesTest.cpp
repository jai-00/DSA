#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(67);
    cout << s.size();
    cout << endl;
    return 0;
}