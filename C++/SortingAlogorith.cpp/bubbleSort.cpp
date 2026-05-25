#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,4,3,5};
    int n = 5;
    for(int i=0; i<n-1; i++){
        bool isSwap = false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap =true;
            }
        }
        if(!isSwap){
            cout<<"Already Sorted "<<endl;
            break;
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}