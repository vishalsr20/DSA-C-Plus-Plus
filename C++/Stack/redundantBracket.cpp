#include<iostream>
#include<stack>
using namespace std;
bool  solve(string &bracket){
    stack<char>st;
    for(int i=0; i<bracket.size(); i++){
       
        char ch = bracket[i];
        if(ch == '(' || ch == '[' || ch == '{' || (ch == '+' || ch == '-' || ch == '*' || ch == '/')){
            st.push(ch); 
        }else if ((ch == ')' || ch == ']' || ch == '}')){
             
             bool hasOperator = false;
            
            while(!st.empty() && st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                char topCh = st.top();
                st.pop();

                    if (topCh == '+' || topCh == '-' || topCh == '*' || topCh == '/') {
                    hasOperator = true;
                }
            }

            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
        
             if (!hasOperator) {
                return false;
            }
        
        }
    }



 return true;
    
    
}

int main(){
    string bracket = "((a+b)) + (c/d)";
    int ans =solve(bracket);

    if(ans){
        cout<<"No redundant bracket"<<endl;
    }else{
        cout<<"Redundant bracket"<<endl;
    }
}