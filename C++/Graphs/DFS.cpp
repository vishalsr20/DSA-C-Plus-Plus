#include<iostream>
#include<queue>
#include<list>
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

    void addEdge(int u , int v){
        li[u].push_back(v);
        li[v].push_back(u);
    }

    void bfs(){
            queue<int>Q;
            vector<bool>visited(V,false);
            Q.push(0);
            visited[0] = true;
            
            while(Q.size() > 0){
                int u = Q.front();
                Q.pop();

                cout<< u << " ";
                for(int v : li[u]){
                    if(!visited[v]){
                        visited[v] = true;
                        Q.push(v);
                    }
                }
               
            }
            cout<<endl;  
        }

    void dfsHelper(int u, vector<bool>&visited){
            cout<<u<<" ";
            visited[u] = true;

            for(auto v:li[u]){
                if(!visited[v]){
                    dfsHelper(v,visited);
                }
            }

            

    }

    void dfs(){
        int src = 0;
        vector<bool>visited(V,false);
       


        // if the there are components in the graph ,  use the for loop foe each vertices must be visit

        for(int i=0; i<V; i++){
            if(!visited[i]){
                 dfsHelper(src,visited);
            }
        }

    }
};

int main(){

    Graph g(5);
     g.addEdge(0,1);
        g.addEdge(1,2);
        g.addEdge(1,3);
        g.addEdge(2,4);
        cout<<"DFS : ";
        g.dfs();
        cout<<endl;
        cout<<"BFS : ";
        g.bfs();



    return 0;
}

