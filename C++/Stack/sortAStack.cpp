#include<iostream>
#include<stack>
using namespace std;

void insertSortedStack(stack<int>&st, int target){
    if(st.empty()){
        st.push(target);
        return;
    }
    if(st.top() >= target){
        st.push(target);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertSortedStack(st,target);
    st.push(topElement);
}

void sortStack(stack<int>&st){
    if(st.empty()){
      
        return;
    }



    int temp = st.top();
    st.pop();
    sortStack(st);
    
    // sorting
    insertSortedStack(st,temp);

}

 

int main(){

    stack<int>st;
    st.push(7);
    st.push(11);
    st.push(3);
    st.push(5);
    st.push(9);
    int target = st.top();

    sortStack(st);
    while(!st.empty()){
        cout<<st.top() <<" ";
        st.pop();
    }
    return 0;
}