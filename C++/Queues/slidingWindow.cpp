#include<iostream>
#include<queue>
#include<deque>
using namespace std;

void solve(int arr[],int n, int k){
    queue<int>q;
    // process first window
    for(int i=0; i<k ; i++){
        if(arr[i] < 0){
            q.push(i);
        }
    }

    // remaining window
    for(int i=k ; i<n; i++){
        if(q.empty()){
            cout<<"0"<<" ";
        }else{
            cout<<arr[q.front()]<<" ";
        }

        while((!q.empty()) && (i - q.front() >= k  )){
            q.pop();
        }
        if(arr[i] < 0){
            q.push(i); 
        }

    }
    
                if(q.empty()){
            cout<<"0"<<" ";
        }else{
            cout<<arr[q.front()]<<" ";
        }
}

int main(){
    // int arr[] = {12,-1,-7,8,-15,30,16,28};
    int arr[] ={-8,2,3,-6,10};
    int size = 5;
    int k = 2;
    solve(arr,size,k);
    return 0;
}