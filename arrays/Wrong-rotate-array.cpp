#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int>& nums, int k) {
        int length = nums.size()-1;
        int tempLocation=-1;
        if(k > length){
            tempLocation = k % length;
        }else{
            tempLocation = k;
        }

        while(tempLocation != 0){
          nums[0] = nums[0] ^ nums[tempLocation];
          nums[tempLocation] = nums[0] ^ nums[tempLocation];
          nums[0] =  nums[0] ^ nums[tempLocation];


            // cout<<tempLocation;
          tempLocation = tempLocation + k > length?((tempLocation + k) % length)-1 :tempLocation + k;

        }
    }

int main(){
    vector<int> vec = {1,2,3,4,5,6};
    for(int num: vec){
        cout<<num<<" ";
    }
    cout<<endl;
    cout<<"after rotation----------------------------------------- "<<endl;
    rotate(vec, 2);
   
    for(int num: vec){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}