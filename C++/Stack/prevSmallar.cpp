#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int main(){
    vector<int>v{2,1,4,3};
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size());
    for(int i=0; i<v.size(); i++){
        while(s.top() > v[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(v[i]);

    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}