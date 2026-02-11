#include<iostream>
#include<list>
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
    void printGraph(int n){
        for(int i=0;i<=n;i++){
            cout<<i <<" : {";
            for(int i : adjList[i]) cout<<i<<",";
            cout<<"}";
            cout<<endl;
        }
    }
    void BFStraversal(int src){
        cout<<"BFS : ";
        unordered_map<int,bool>visited;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int frontNode=q.front();
            cout<<q.front()<<",";
            q.pop();
            for(auto node : adjList[frontNode]){
                if(!visited[node]){ 
                    q.push(node); 
                    visited[node]=true;
                }
            }
        }
    }
    void dfsHelper(int src,unordered_map<int,bool>&visited){
        cout<<src<<",";
        for(int node: adjList[src]){
            if(!visited[node]){
                visited[node]=true;
                dfsHelper(node,visited);
            }
        }
    }
    void DFStraversal(int src){
        cout<<endl;
        unordered_map<int,bool>visited;
        cout<<"DFS : ";
        visited[src]=true;
        dfsHelper(src,visited);
    }
};

int main()
{
    Graph g;
    g.addEdge(0,3,1);
    g.addEdge(0,5,1);
    g.addEdge(0,2,1);
    g.addEdge(3,5,1);
    g.addEdge(2,5,1);
    g.addEdge(5,4,1);
    g.addEdge(5,6,1);
    g.addEdge(4,1,1);
    g.addEdge(6,1,1);

    g.printGraph(6);

    g.BFStraversal(0);
    g.DFStraversal(0);

    return 0;
}