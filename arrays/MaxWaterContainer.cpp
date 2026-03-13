#include<iostream>
#include<vector>
using namespace std;
int calculateMaxWater(vector<int> nums){
    int i = 0;
    int j = nums.size()-1;
    int leftWall, rightWall;
    int maxWater = 0;
    while(i<j){
        int height = min(nums[i], nums[j]);
        int width = j - i;
        int currentWater = height * width;

        if(currentWater > maxWater){
            leftWall = nums[i];
            rightWall = nums[j];
        }
        maxWater = max(currentWater, maxWater); 
        
        ( i < j) ? i++: j--;
    }

    cout<<"Left wall : "<<leftWall<<endl<<"Right wall : "<<rightWall<<endl;
    return maxWater;
}

int main(){
    vector<int> wallHeight = {1, 4,2,5,12,4,14,15,36};
    cout<<calculateMaxWater(wallHeight);
    return 0;
}