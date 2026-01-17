#include<iostream>
#include<vector>    
using namespace std;

int rec(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;

    int left = rec(n-1);
    int right = rec(n-2);

    return left+right;
}

int memo(int n, vector<int>&dp){
    if(n == 1) return 1;
    if(n == 2) return 2;
    
    if(dp[n] != -1){
        return dp[n];

    }

    int left = memo(n-1,dp);
    int right = memo(n-2,dp);

    dp[n] = left+right;
    return dp[n]; 
}

int tab(int n){
    vector<int>dp(n+1,0);
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int space(int n){
    int prev = 2;
    int prev2 = 1;
    int curr;
    for(int i=3; i<=n; i++){
        curr = prev + prev2;
        prev2=prev;
        prev=curr;

    }

    return curr;
}

int main(){
    int n = 45;
    // int ans = rec(n);
    // vector<int>dp(n+1,-1);
    // int ans =memo(n,dp);

    // int ans =tab(n);
    int ans = space(n);
    cout<<"Ans : "<<ans<<endl;
    return 0;
}