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

    bool cyclePresent(int src,unordered_map<int,bool>&visited,int parent){
        visited[src]=true;
        for(auto node : adjList[src]){
            if(!visited[node]){
                visited[node]=true;
                if(cyclePresent(node,visited,src)) return true;
            }
            else if(visited[node] && node!=parent) return true;
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
    bool ans=false;
    for(int src=0;src<=6;src++)
    {
        if(!visited[src]){
            ans=g.cyclePresent(src,visited,-1);
            if(ans==1) break;
        }
    }

    ans==1?cout<<"cycle present" : cout<<"cycle not present" ;

    return 0;
}