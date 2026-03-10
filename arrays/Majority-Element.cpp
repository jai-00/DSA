#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {2,1,2,3,1,1,1};
    int majorityElement = 0;
    int count = 0;
    for(int num: nums){
        if(count == 0){
            majorityElement = num;
        }
        if(num == majorityElement){
            count++;
        }else{
            count--;
        }

    }

    //re-verifying for edge-cases 
    count = 0;

    for(int num: nums){
        if(num == majorityElement){
            count++;
        }
    }

    if(count > nums.size()/2){
        cout<<"Majority Element: "<<majorityElement;
    }else{
        cout<<"No majority Element Present";
    }


    return 0;
}