#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main(){
    string str = "aabc";
    //  string str = "zarcaazrd";
    int freq[26] = {0};
    queue<char>q;

    string ans = "";
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        // increament frequency
        freq[ch - 'a']++;
        q.push(ch);
        
        while(!q.empty()){
            if(freq[q.front() - 'a'] > 1){
                q.pop();
            }else{
                ans.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }

    }
    for(int i=0; i<ans.length(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}