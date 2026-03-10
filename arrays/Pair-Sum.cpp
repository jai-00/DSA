#include<iostream>
#include<vector>
using namespace std;
vector<int> findPair(vector<int> nums, int target){
    vector<int> ans;
    int n =  nums.size();
    int i=0, j=n-1;
    while(i<j){
        if(nums[i]+nums[j] < target){
            i++;
        }else if(nums[i]+ nums[j] > target){
            j--;
        }else{
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            return ans;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {2,7, 11, 15};
    int target = 26;

    vector<int> ans =  findPair(nums, target);

    for(int num: ans){
        cout<<num<<" ";
    }

    return 0;
}