#include <iostream>
#include <vector>
using namespace std;
void mergeArray(vector<int> &nums1, vector<int> &nums2, int size)
{
    int i = size - 1;
    int j = nums2.size() - 1;
    int currIndex = nums1.size() - 1;
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[currIndex] = nums1[i];
            i--;
        }
        else
        {
            nums1[currIndex] = nums2[j];
            j--;
        }
        currIndex--;
    }
}
void printArray(vector<int> &nums, string txt, bool space)
{
    cout << txt << " : ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    if (space)
    {
        cout << endl;
    }
}
int main()
{
    vector<int> nums1 = {1, 4, 5, 0, 0, 0, 0};
    vector<int> nums2 = {2, 5, 5, 8};
    printArray(nums1, "Main Array", true);
    printArray(nums2, "Smaller Array", true);
    mergeArray(nums1, nums2, 3);
    printArray(nums1, "Result Array", false);
    return 0;
}