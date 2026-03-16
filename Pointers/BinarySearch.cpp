//Running command: g++ BinarySearch.cpp -o a.exe && .\a.exe

#include<iostream>
#include<vector>
using namespace std;
int find(vector<int> nums, int target){
    int start = 0;
    int last = nums.size()-1;

    while(start <= last){
        int mid = start + ((last-start)/2);

        if(nums[mid] < target){
            start = mid+1;
        }else if(nums[mid] > target){
            last = mid - 1;
        }else {
            return mid;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {1, 4,5,6,8,9, 13, 15, 20, 25};
    int target = 25;
    int targetIndex = find(nums, target);
    if(targetIndex == -1){
        cout<<"Target value isn't present";
    }else{
        cout<<"Target found at "<<targetIndex;
    }
    return 0;
}

//Running command: g++ BinarySearch.cpp -o a.exe && .\a.exe