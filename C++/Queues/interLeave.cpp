#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    queue<int>q2;
    int size = q.size();
    int mid = size / 2;
    int i=0;
    while(i < mid){
        int element = q.front();
        q.pop();
        q2.push(element);
        i++;
    }

    while(!q.empty() && !q2.empty()){
        int first = q2.front();
        q2.pop();
        q.push(first);
        int second = q.front();
        q.pop();
        q.push(second);
        

    }
    if(size&1){
        int last = q.front();
        q.pop();
        q.push(last);
    }
 

    cout<<"First One "<<endl;;
        while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}