#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmallar(vector<int>&v){

    stack<int>s;
    s.push(-1);
    vector<int>ans1(v.size());
    
    for(int i=0; i<v.size(); i++){
        while(s.top() != -1 &&  v[s.top()] >= v[i]){
            s.pop();
        }
        
        ans1[i] = s.top();
        s.push(i);
    }
    return ans1;
}

vector<int> nextSmallar(vector<int>& v){
    stack<int>s;
    int n = v.size();
    s.push(-1);
    vector<int>ans2(v.size());

    for(int i=v.size()-1; i>=0; i--){
   
        while(s.top() != -1 && v[s.top()] >= v[i]){
            s.pop();
        }
             if(ans2[i] == -1){
            ans2[i] = n;
        }
        ans2[i] = s.top();
        s.push(i);
    }

    return ans2;
}

int getReactangularAreaHistogram(vector<int>& height){
    vector<int>prev = prevSmallar(height);
    vector<int>next = nextSmallar(height);

    int maxArea = INT16_MIN;
    for(int i=0; i<height.size(); i++){
        int len = height[i];
        int width = next[i] - prev[i] - 1;

        int area = len * width;

        maxArea = max(maxArea,area);
    }
    return maxArea;
}

int main(){
    vector<int>v{2,1,5,6,3};

    cout<<"MaxArea :"<<endl;
    cout<<getReactangularAreaHistogram(v);
    return 0;
}