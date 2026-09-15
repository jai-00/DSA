#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int findRepeating(vector<int> &arr)
{
    int slow = 0;
    int fast = 0;
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = 0;

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}
int main()
{
    vector<int> arr = {1, 2, 4, 3, 4};
    cout << endl
         << "------------------------" << endl;
    int ans = findRepeating(arr);
    cout << "Repeating value = " << ans;
    cout << endl
         << "------------------------" << endl;

    return 0;
}