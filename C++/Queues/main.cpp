#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;
    //insertion
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    // size

    cout<<"Size is : "<<q.size()<<endl;
    q.pop();

    cout<<"New size : "<<q.size()<<endl;
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }else{
        cout<<"Queue is not empty"<<endl;
    }

    cout<<"Front element : "<<q.front()<<endl;

    return 0;
}