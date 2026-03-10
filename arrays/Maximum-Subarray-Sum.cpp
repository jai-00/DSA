#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    vector<int> vec = {1,-2,3,6,1,-10,5,4,2};
    int maxSum = INT_MIN; 
    int sum = 0;
    for(int num: vec){
        sum += num;
        maxSum = max(sum, maxSum);

        if(sum < 0){
            sum = 0;
        }
    }

    cout<<"Maximum sum: "<<maxSum;
    return 0;
}