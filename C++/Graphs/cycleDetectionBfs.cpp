#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
            li[v].push_back(u);
        }

        bool isCycleUniBFS(int src , vector<bool>&visited){
            queue<pair<int,int>>q;
            q.push({src,-1});
            visited[src]=true;

            while(q.size() > 0){
                int u = q.front().first;
                int par = q.front().second;
                q.pop();
                list<int>neighbors = li[u];

                for(auto it:neighbors){
                    if(!visited[it]){
                        q.push({it,u});
                        visited[it]=true;
                    }else if(it != par){
                        return true;
                    }
                }
            }
            return false;
        }
        bool isCycle(){
            vector<bool>visited(V,false);
            for(int i=0; i<V; i++){
                if(!visited[i]){
                    if(isCycleUniBFS(i,visited)){
                        return true;
                    }
                }
            }
           return false;

        }
    };


int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    cout<<g.isCycle()<<endl;
    return 0;
}