class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edge)
    {

        unordered_map<int, vector<int>> edges;
        for (auto it : edge)
        {
            edges[it[0]].push_back(it[1]);
        }

        unordered_map<int, int> indegree;
        for (int i = 0; i < V; i++)
        {
            for (auto node : edges[i])
                indegree[node]++;
        }

        queue<int> q;
        vector<int> ans;

        // always start topological sort with 0 indegree (0 dependency)

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // main logic
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for (auto node : edges[frontNode])
            {
                indegree[node]--;
                if (indegree[node] == 0)
                    q.push(node);
            }
        }
        return ans;
    }
};

#include <iostream>
using namespace std;
int main()
{   //if number vertices == size of the ans the cycle not present otherwise present; we used khans algo as it is
    return 0;
}