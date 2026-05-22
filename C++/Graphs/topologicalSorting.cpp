#include<iostream>
#include<list>
#include<stack>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int>*li;

    public:
    Graph(int V){
        this->V = V;
        li = new list<int>[V];
    }

    void addEdge(int u, int v){
        li[u].push_back(v);
    }

    void dfs(int curr, vector<bool>&visited, stack<int>&s){
        visited[curr]=true;

        for(auto v:li[curr]){
            if(!visited[v]){
                dfs(v,visited,s);
            }
        }
        s.push(curr);

    }

    void topoSort(){
        vector<bool>visited(V,false);
        stack<int>s;

        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i,visited,s);
            }
        }

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
            
    
};

int main(){
    Graph g(6);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(4,0);
    g.topoSort();
    return  0;
}