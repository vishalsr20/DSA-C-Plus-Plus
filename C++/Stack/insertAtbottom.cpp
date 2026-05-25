#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&s, int target){
    if(s.empty() ){
        s.push(target);
        return ;
    }

    int topElement = s.top();
    s.pop();
    solve(s,target);
    s.push(topElement);
}

void insertAtBottom(stack<int>&s){
    if(s.empty()){
        cout<<"Stack is empty , cant't insert at bottom";
    }

   int target = s.top();
   s.pop();
   solve(s,target);

}

int main(){
    stack<int>s;
    s.push(5);
    s.push(15);
    s.push(27);
    s.push(32);
    s.push(11);
    s.push(1110);

    insertAtBottom(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    

}
