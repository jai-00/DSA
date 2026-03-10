#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[] = {1,2,3,7,2,3};
    int length = sizeof(arr) / sizeof(int);
    cout<<'['<<" ";
    
    for(int i=0; i<length; i++){
        bool isUnique = true;

        for(int j=0; j<length; j++){
        if(i!=j && arr[i]==arr[j]){
            isUnique = false;
            
        }
        
        }
        if(isUnique == true){
            cout<<arr[i]<<(i == (length-1)?" ": " , ");
       }
       
    }
    cout<<']';
    
    return 0;
}