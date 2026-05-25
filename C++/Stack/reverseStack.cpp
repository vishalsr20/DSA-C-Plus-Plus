#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s , int target){
    if(s.empty()){
        s.push(target);
        return ;  
    }
      int topElement  = s.top();
        s.pop();
        insertAtBottom(s,target);
        s.push(topElement);
}

void solve(stack<int>&s){
    if(s.empty()){
        return ;
    }

    int target = s.top();
    s.pop();

    solve(s);


    insertAtBottom(s,target);
}

int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

     cout<<"before solve"<<endl;
        while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
        }
    cout<<endl;

    solve(s);
        // cout<<"After solve"<<endl;
        // while(!s.empty()){
        // cout<<s.top()<<" ";
        // s.pop();
        // }
    cout<<endl;
}

