#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main(){
    queue<int>q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);

    stack<int>st;
    int k = 4;
    int i=0;
    while(i<k && k>=0 ){
        int element = q.front();
        q.pop();
        st.push(element);
        i++;
    }
    while(!st.empty()){
        int temp = st.top();

        st.pop();
        q.push(temp);
    }
    int rem = q.size() - k;
    i = 0;
    while(i < rem && k>=0){
        int element  = q.front();
       
        q.pop();
         q.push(element);
        i++;
    }

        while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
    return 0;
}