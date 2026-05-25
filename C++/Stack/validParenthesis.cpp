#include<iostream>
#include<stack>
#include<string>
using namespace std;



bool  solve(string& s){
    stack<char>st;
    for(int i=0; i<  s.size(); i++){
        char ch = s[i];

        // opening bracket 
        if(ch == '(' || ch == '[' || ch == '{'){
            st.push(ch);
        }else{
            //  closing bracket 
           if(!st.empty()){
            char topCh = st.top();
            // matching bracket
            if(ch == ')' && topCh == '(' ){
            st.pop();     
            }
            if(ch == '}' && topCh == '{'){
                st.pop();
            }
            if(ch == ']' && topCh == '['){
                st.pop();
            }else{
                // bracket not matching
                return false;
            }
        
           }else{
                return false;
           }  
        }
    }

    if(st.empty()){
        return true;
    }
   
}

int main(){
    string s="([])";
    bool ans = solve(s);
    cout<<(ans ? "true" : "false");
    return 0;
}
