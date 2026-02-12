#include <iostream>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool directed)
    {
        if (directed)
        {
            adjList[u].push_back(v);
        }
        else
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    void printGraph(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            cout << i << " : {";
            for (int i : adjList[i])
                cout << i << ",";
            cout << "}";
            cout << endl;
        }
    }

    bool cyclePresent(int src,unordered_map<int,bool>&visited){
        unordered_map<int,int>parent;
        queue<int>q;
        q.push(src);
        visited[src]=true;
        parent[src]=-1;
        while(!q.empty())
        {
            int frontNode=q.front();
            q.pop();
            for(auto node : adjList[frontNode]){
                if(!visited[node]){ 
                    q.push(node);
                    parent[node]=frontNode;
                    visited[node]=true;
                }
                else if(visited[node] && parent[frontNode]!=node) return true;
            }
        }
        return false;
    }

};
int main()
{
    //undirected graph

    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,6,0);
    g.addEdge(1,4,0);
    g.addEdge(6,3,0);
    g.addEdge(4,3,0);
    g.addEdge(4,2,0);
    g.addEdge(2,5,0);

    g.printGraph(6);

    unordered_map<int,bool>visited;
    //handle disconected components 
    bool ans=false;
    for(int src=0;src<=6;src++)
    {
        if(!visited[src]){
            ans=g.cyclePresent(src,visited);
        }
    }

    ans==1?cout<<"cycle present" : cout<<"cycle not present" ;

    return 0;
}