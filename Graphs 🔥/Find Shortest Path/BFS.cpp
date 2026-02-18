#include <iostream>
using namespace std;
// ONLY FOR THE SAME WEIGHT AND NON DIRECTED GRAPH FOR DIFFRENT WEIGHT GRAPH WE USE DFS 
class Graph{
    public:
    unordered_map<int,vector<pair<int,int>>>adj;

    void addEdge(int u,int v,int w, int direction){
        if(direction){
            adj[u].push_back({v,w});
        }
        else{
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
    }

    void print(int V){
        for(int i=0;i<=V;i++){
            cout<<i<<": ";
            for(auto node:adj[i]) cout<<node.first<<",";
            cout<<endl;
        }
    }

    void ShortestPathBFS(int src,int dist){
        unordered_map<int,int>parent;
        unordered_map<int,bool>visited;
        queue<int>q;
        visited[src]=true;
        q.push(src);
        parent[src]=-1;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto node : adj[frontNode]){
                if(!visited[node.first]){
                    q.push(node.first);
                    visited[node.first]=true;
                    parent[node.first]=frontNode;
                }
            }
        }
        while(dist!=-1){
            cout<<dist<<"<--";
            dist=parent[dist];
        }
        cout<<endl;
    }
};


int main()
{
    Graph g;
    g.addEdge(0,1,1,0);
    g.addEdge(1,2,1,0);
    g.addEdge(2,3,1,0);
    g.addEdge(2,4,1,0);
    g.addEdge(4,5,1,0);
    g.addEdge(5,3,1,0);

    g.print(5);

    g.ShortestPathBFS(0,3);

    return 0;
}