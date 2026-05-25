#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int top1;
    int top2;
    int size;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        top1=-1;
        top2=size;
    }

    // function 
    void push1(int data){
        if(top2 - top1 == 1){
            cout<<"Stack Overflow in stack 1"<<endl;
        }else{
            top1++;
            arr[top1] = data;
        }
    }

    void push2(int data){
        if(top2 - top1 == 1){
            cout<<"Stack Overflow in stack 2"<<endl;
        }else{
            top2--;
            arr[top2] = data;

        }
    }

    void pop1(int data){
        if(top1 == -1){
            cout<<"Underflow in stack 1"<<endl;
        }else{
            top1--;
            

        }
    }

    void pop2(int data){
        if(top2 == size){
            cout<<"Stack underfow in stack 2"<<endl;
        }else{
            top2++;
        }
    }

    
};

int main(){
    Stack s(10);
    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push1(50);
    s.push2(60);
    s.push2(70);
    s.push2(80);
    s.push2(90);
    s.push2(100);
 
    return 0;
}