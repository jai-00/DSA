#include<iostream>
using namespace std;
int calculatePowerOfTwo(int number){
    int power = 0;
    while(number > 1){
        number = number >> 1;
        power++;
    }
    return power;
}


int main(){
    int binaryNumber;
    cout<<"Enter a number : ";
    cin>>binaryNumber;
    int decimalNumber = calculatePowerOfTwo(binaryNumber);
    cout<<"Power of Two closest to your number "<<binaryNumber<<" is : "<<decimalNumber;
    return 0;
}