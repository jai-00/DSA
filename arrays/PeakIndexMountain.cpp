//! running code - g++ PeakIndexMountain.cpp -o a && .\a.exe

#include<iostream>
#include<vector>
using namespace std;
int findPeak(vector<int> nums){
    int start = 1;
    int end = nums.size() - 2;

    while(start <= end){
        int mid = start + ((end - start) / 2);
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
            return mid;
        }else{
            if(nums[mid] > nums[mid-1]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {0, 1,2 ,6,10,2};
    int peakIndex = findPeak(nums);
    cout<<"Peak Index: "<<peakIndex;
    return 0;
}