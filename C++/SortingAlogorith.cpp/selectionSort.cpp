#include<iostream>
using namespace std;

int main(){
    int arr[] = {5,4,2,1,3};
    int n = 5;
    for(int i=0; i<n-1; i++){
        int smallIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[smallIndex] > arr[j]){
                smallIndex = j;
            }
        }
        swap(arr[i],arr[smallIndex]);
        
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}