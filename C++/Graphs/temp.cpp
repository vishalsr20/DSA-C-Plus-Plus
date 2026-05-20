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

        void print(){
            for(int i=0; i<V; i++){
                cout<<i<<" : ";
                for(auto it:li[i]){
                    cout<<it<<" ";
                }
                cout<<endl;
            }
        }

        void bfs(){
            queue<int>q;
            vector<bool>visited(V,false);
            q.push(0);
            visited[0] = true;

            while(q.size() > 0){
                int u = q.front();
                q.pop();
                cout<<u<<" ";
                for(auto it:li[u]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it]=true;
                    }
                }

            }
        }

        void dfsHelper(int u, vector<bool>&visited){
            cout<<u<<" ";
            visited[u]=true;

            for(auto it:li[u]){
                if(!visited[it]){
                    dfsHelper(it,visited);
                }
            }
        }

        void dfs(){
            vector<bool>visited(V,false);
            
            for(int i=0; i<V; i++){
                if(!visited[i]){
                    dfsHelper(i,visited);
                }
            }
        }

    bool isCycleHelper(int src , int par, vector<bool>&visited){
        visited[src] = true;
        list<int>neigh = li[src];

        for(auto it:neigh){
            if(!visited[it]){
                if(isCycleHelper(it,src,visited)){
                    return true;
                }
            }else if(it != par){
                return true;
            }
        }

        return false;



    }

    bool isCycle(){
        vector<bool>visited(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(isCycleHelper(i,-1,visited)){
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
        g.addEdge(1,2);
        g.addEdge(1,3);
        g.addEdge(2,4);

   

    // g.print();
    // cout<<"BFS : "<<endl;;
    // g.bfs();
    // cout<<endl;
    // cout<<"DFS : "<<endl;
    // g.dfs();
    cout<<endl<<"Cycle Detection using the BFS UNI"<<endl;
    cout<<g.isCycle();


    return 0;
}