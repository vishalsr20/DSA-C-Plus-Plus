#include<iostream>
#include<stack>
using namespace std;

int main(){
    // // creation using stl library
    // stack<int>st;

    // // insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);

    // // remove
    // st.pop();

    // // check the element on the top 
    // cout<<"Element on the top is "<<st.top()<<endl;

    // // size 
    // cout<<"Size of the stack "<<st.size()<<endl;

    // // empty
    // if(st.empty()){
    //     cout<<"The stack is not empty"<<endl;
    // }else{
    //     cout<<"Stack is not empty "<<endl;
    // }

    stack<int>s;

    s.push(10);
    s.push(20);
     s.push(30);
     s.push(40);

     while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
     }
     cout<<endl;
}
