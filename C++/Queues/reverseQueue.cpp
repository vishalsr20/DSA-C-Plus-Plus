#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// void reverseQueue(queue<int>&q){
//     stack<int>st;
//     while(!q.empty()){
//         st.push(q.front());
//         q.pop();
//     }
//     while(!st.empty()){
//         q.push(st.top());
//         st.pop();
//     }
    
// }

void reverseQueue(queue<int>&q){
    if(q.empty()){
        return;
    }

    int element = q.front();
    q.pop();
    reverseQueue(q);
    q.push(element);
}

int main(){
    queue<int>q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;

    return 0;

}