//command: g++ RotatedArraySearch.cpp -o a.exe && .\a.exe
#include<iostream>
#include<vector>
using namespace std;
int search(vector<int> nums, int target){
    int start = 0;
    int end = nums.size()-1;
    while(start<=end){
        int mid = start + ((end-start)/2);
        if(nums[mid] == target){
            return mid;
        }else{
            if(nums[start]<=nums[mid]){
                if(nums[start] <= target && target < nums[mid]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }

            }else{
                if(nums[mid] < target && target <= nums[end]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {5,6,7,0,1,2,3,4};
    int target = 3;
    int targetIndex = search(nums, target);
    if(targetIndex < 0){
        cout<<"Target not found";
    }else{
        cout<<"Target found at index "<<targetIndex;
    }
    return 0;
}