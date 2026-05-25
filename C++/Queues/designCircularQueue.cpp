#include<iostream>
using namespace std;
class circularQueue{
    public:
    int *arr;
    int size;
    int front ;
    int rear;


    // constructor
     circularQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }


    void push(int data){
        // queue is full
        // single element case
        // circuler nature
        // normal flow
        //TODO: add one more condition 
        if((front == 0 && rear == size-1) && (rear = front-1)){
            cout<<"Queue is full , cannot insert"<<endl;
        }
        else if(front == -1 ){
            front=0;
            rear=0;
            arr[rear]=data;
        }else  if(rear == size-1 && front != 0){
            rear=0;
            arr[rear] = data;
        }else{
            rear++;
            arr[rear]=data;
        }
    }

    void pop(){
        // empty
        // single element
        // cicular nature
        // normal flow

        if(front == -1 && rear == -1){
            cout<<"Queue is empty cannot pop"<<endl;
        }else if(front == rear){
            arr[front] == -1;
            front = -1;
             rear = -1;
        }else if(front == size - 1){
            front = 0;
        }else{
            front++;
        }

    }
};
int main(){
    circularQueue q(10);
    q.push(10);
    q.push(20);
    
    

    return 0;
}