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

    bool cyclePresent(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&TrackPath){
        visited[src]=true;
        TrackPath[src]=true;
        for(auto node : adjList[src]){
            if(!visited[node]){
                if(cyclePresent(node,visited,TrackPath)) return true;
            }
            else if(visited[node] && TrackPath[node]) return true;
        }
        TrackPath[src]=false;
        return false;
    }

};
int main()
{
    //undirected graph

    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,6,1);
    g.addEdge(1,4,1);
    g.addEdge(6,3,1);
    g.addEdge(4,3,1);
    g.addEdge(4,2,1);
    g.addEdge(2,5,1);

    g.printGraph(6);

    unordered_map<int,bool>visited,TrackPath;
    //handle disconected components 
    bool ans=false;
    for(int src=0;src<=6;src++)
    {
        if(!visited[src]){
            ans=g.cyclePresent(src,visited,TrackPath);
            if(ans) break;
        }
    }

    ans==1?cout<<"cycle present" : cout<<"cycle not present" ;

    return 0;
}