#include <iostream>
#include<set>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{

    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto &it : edges)
    {
        adj[it[0]].push_back({it[2], it[1]});
        adj[it[1]].push_back({it[2], it[0]});
    }

    set<pair<int, int>> st;
    vector<int> result(V, INT_MAX);
    st.insert({0, src});
    result[src] = 0;
    while (!st.empty())
    {
        auto &it = *st.begin();
        int node = it.second;
        int dist = it.first;
        st.erase(it);
        if (dist > result[node])
            continue;
        for (auto &nbr : adj[node])
        {
            int d = nbr.first;
            int adjNode = nbr.second;
            if (d + dist < result[adjNode])
            {
                if (result[adjNode] != INT_MAX)
                {
                    st.erase({result[adjNode], adjNode});
                }
                result[adjNode] = d + dist;
                st.insert({d + dist, adjNode});
            }
        }
    }
    return result;
}

int main()
{
    return 0;

}