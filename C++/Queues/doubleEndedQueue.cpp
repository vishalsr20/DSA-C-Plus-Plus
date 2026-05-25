#include<iostream>
using namespace std;

class Deque{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        this->size = size;
        arr = new int[size];
         front = -1;
         rear = -1;
    }

    void pushRear(int data){
        if((front == 0 && rear == size - 1) || (front - rear == 1)){
            cout<<"Q is full , cannot insert"<<endl;
            return;
        }else if (front == -1 && rear == -1){
            front = 0;
            rear = 0;
            arr[rear] = data;
        }else if(rear == size -1 && front != 0){
            rear=0;
            arr[rear] = data;
        }else{
            rear++;
            arr[rear] = data;
        }
    }

    void pushFront(int data){
        if((front == 0 && rear == 0) || (front - rear == 1)){
            cout<<"Q is empty cannot inser"<<endl;
            return;
        }else if(front == -1){
            front = 0;
            rear = 0;
        }else if(front == 0 && rear!= size-1){
            front = size-1;
        }else{
            front--;
        }
        arr[front]= data;
    }

    void popFront(){
        if(front == -1  ){
            cout<<"Queue is empty"<<endl;
            return;
        }else if(front == rear){
            arr[front]=-1;
            front=-1;
        }else if(front == size - 1){
               arr[front]=-1;
            front = 0;
        }else{
               arr[front]=-1;
            front++;
        }

    }


    void popRear(){
        if(rear == -1 && front == -1){
            cout<<"Queue is empty "<<endl;
            return;
        }else if(front == rear){
            arr[rear]= -1;
            rear = -1;
            front = -1;
        }else if(rear == 0){
            arr[rear] = -1;
            rear = size - 1;
        }else {
            arr[rear] = -1;
            rear--;
        }
    }

    void print(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }


};

int main(){
    Deque dp(10);
    dp.print();

    dp.pushRear(10);
   
    dp.pushRear(20);
     dp.pushRear(30);
      dp.pushRear(40);
       dp.pushRear(50);
        dp.pushRear(60);
         dp.pushRear(70);
          dp.pushRear(80);
         

           dp.print();

           dp.popRear();
           dp.print();
    
               dp.popRear();
           dp.print();

           dp.popFront();
            dp.print();

  dp.popFront();
            dp.print();

  dp.popFront();
            dp.print();

            dp.pushFront(101);
            dp.print();

            dp.pushFront(102);
            dp.print();
                        dp.pushFront(103);
            dp.print();

                        dp.pushFront(104);
            dp.print();

            dp.popFront();
            dp.print();
               dp.popFront();
            dp.print();

            dp.pushRear(201);
            dp.print();

              dp.pushRear(202);
            dp.print();
              dp.pushRear(203);
            dp.print();
              dp.pushRear(204);
            dp.print();
              dp.pushRear(201);
            dp.print();

                     dp.pushRear(201);
            dp.print();

        ;


    return 0;
}