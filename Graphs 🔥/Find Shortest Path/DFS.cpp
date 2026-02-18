#include <iostream>
using namespace std;
// ONLY FOR THE SAME WEIGHT AND NON DIRECTED GRAPH FOR DIFFRENT WEIGHT GRAPH WE USE DFS
class Graph
{
public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void addEdge(int u, int v, int w, int direction)
    {
        if (direction)
        {
            adj[u].push_back({v, w});
        }
        else
        {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

    void print(int V)
    {
        for (int i = 0; i <= V; i++)
        {
            cout << i << ": {";
            for (auto node : adj[i])
                cout << node.first << ",";
            cout << "}" << endl;
        }
    }

    void topologicalSort(int src, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[src] = true;
        for (auto node : adj[src])
        {
            if (!visited[node.first])
            {
                topologicalSort(node.first, visited, st);
            }
        }
        st.push(src);
    }

    void shortestDistDFS(stack<int> &path, vector<int> &dist)
    {
        int src=path.top();
        path.pop();
        dist[src]=0;
        for(auto nbr: adj[src]){
            int node=nbr.first,weight=nbr.second;
            if(dist[src]+weight<dist[node]){
                dist[node]=dist[src]+weight;
            }
        }
        while (!path.empty())
        {
            int src = path.top();
            path.pop();
            for (auto nbr : adj[src])
            {
                int node = nbr.first, weight = nbr.second;
                if (dist[src] + weight < dist[node])
                {
                    dist[node] = dist[src] + weight;
                }
            }
        }
        cout<<"printing distance array : "<<endl;
        for(auto i: dist) cout<<i<<" ";
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 13, 1);
    g.addEdge(0, 4, 3, 1);
    g.addEdge(1, 2, 7, 1);
    g.addEdge(1, 4, 1, 1);
    g.addEdge(4, 3, 6, 1);
    g.addEdge(3, 2, 2, 1);

    g.print(4);

    unordered_map<int, bool> visited;
    stack<int> path;

    g.topologicalSort(0, visited, path);

    // cout << "topological order : ";

    // while (!path.empty())
    // {
    //     cout << path.top() << "-->";
    //     path.pop();
    // }
    // cout << endl;

    vector<int> dist(path.size(), INT_MAX);
    g.shortestDistDFS(path, dist);

    return 0;
}