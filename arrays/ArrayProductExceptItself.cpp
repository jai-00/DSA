#include<iostream>
#include<vector>
using namespace std;
vector<int> findProduct(vector<int> nums, int n){
    vector<int> ans(n);
    ans[0] = 1;
    for(int i=1; i<n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }


    int suffix = 1;
    for(int i=n-1; i>=0; i--){
        ans[i] = ans[i] * suffix;
        suffix = suffix * nums[i];
    }

    return ans;
}
int main(){
    vector<int> nums = {1,2,5,3};
    cout<<"OG : ";
    for(int num: nums){
        cout<<num<<" ";
    }
    cout<<endl;
    vector<int> ans = findProduct(nums, nums.size());


    cout<<"New : ";

    for(int num: ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}