#include<iostream>
#include <list>
using namespace std ;

class Graph{
    public:
    unordered_map<int,list<int>> adjList;

    void addEdge(int u, int v,bool directed){
        if(directed){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    void printGraph(){
        for(auto it : adjList){
            cout<<"Value : "<<it.first<<endl;
            for(auto i : it.second) cout<<i<<" ";
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);

    g.printGraph();

    return 0;
}