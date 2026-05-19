#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;


class Graph{
    int V ;
    list<int>*li;

    public:
    Graph(int V){
        this->V = V;
        li = new list<int>[V];
    }

    void addEdge(int u , int v){\
    li[u].push_back(v);
    li[v].push_back(u);
    }

    // bool isCycleUniDFS(int u , int par , vector<bool>&visited){
    //     visited[u] = true;
    //     list<int>neighbour = li[u];

    //     for(auto v:neighbour){
    //         if(!visited[v]){
    //             if(isCycleUniDFS(v,u,visited)){
    //                 return true;
    //             }
    //         }else if(v != par){
    //             return true;
    //         }
    //     }

    //     return false;

    // }

    // bool isCycle(){
    //     vector<bool>visited(V,false);

    //     for(int i=0; i<V; i++){
    //         if(!visited[i]){
    //             if(isCycleUniDFS(i,-1,visited)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;


    // }


     bool isCycleUniHelper(int src , int par, vector<bool>&visited){
        visited[src] = true;

        list<int>neigh = li[src];

        for(auto it:neigh){
            if(!visited[it]){ 
                if(isCycleUniHelper(it,src,visited)){
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
                if(isCycleUniHelper(i,-1,visited)){
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
