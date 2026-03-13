#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    vector<int> nums = {1,2,15,5,5,11,4};
    int bestBuy = INT_MAX;
    int maxProfit = 0;
    for(int num: nums){
        if(num < bestBuy){
            bestBuy = num;
        }
        int profit = num - bestBuy;
        maxProfit = max(maxProfit, profit);

    }

    cout<<maxProfit;
    return 0;
}