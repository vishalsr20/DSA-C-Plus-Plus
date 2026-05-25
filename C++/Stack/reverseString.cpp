#include<iostream>
#include<stack>
using namespace std;

 int main(){
    string str = "dohtaR";
    stack<char>s;

    for(int i=0; i<str.size(); i++){
        s.push(str[i]);
    }
    int size = s.size();
    int mid = size/2;
    cout<<"Mid is : "<<mid<<endl;

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    return 0;
 }