#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
     int front;
     int rear;
     int size;

    // constructor
    Queue(int size){
        this->size = size;
        arr = new int [size];
        front = 0; 
        rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout<<"Queue is full"<<endl;
        }else{
            arr[rear] = data;
            rear++;
        }
    }

    void pop(){
        if(front == rear ){
            cout<<"Queue is empty"<<endl;
        }else{
            arr[front] = -1;
            front++;
            if(front  == rear ){
                front =0;
                rear = 0;
            }
        }
    }

    int getFront(){
        if(front == rear){
            cout<<"Q is empty"<<endl;
            return -1;
        }
         return arr[front];
        
    }

    bool iEmpty(){
        if(front == rear){
            return true;
        }else{
            return false;
        }
    }
    
    int getsize(){
        return rear-front;
    }
};

int main(){
    Queue q(10);
    q.push(5);
    q.push(15);
    q.push(55);

    cout<<"size of q is : "<<q.getsize()<<endl;;
    q.pop();

    cout<<"size of q is : "<<q.getsize()<<endl;
    cout<<"front "<<q.getFront()<<endl;
    return 0;
}