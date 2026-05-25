#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int>ll{2,1,7,4,3,5};
    vector<int>ans(ll.size(), 0);
    stack<int>st;
    for(int i=0; i<ll.size(); i++){
        while(!st.empty() && ll[st.top()] < ll[i]){
            int val = st.top();
            st.pop();
            ans[val] = ll[i];
        }
            st.push(i);
        
    }

    for(int i=0; i<ll.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
} 