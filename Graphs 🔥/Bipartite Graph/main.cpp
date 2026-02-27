#include <iostream>
using namespace std;

// bool dfs(int src,vector<vector<int>>& adj,vector<int>&color,int currColor){
    //     color[src]=currColor;
    //     for(auto &node : adj[src]){
    //         if(color[node]==color[src]) return false;
    //         if(color[node]==-1){//never colored
    //             int findColor=1-currColor; //short hand if 0 the 1 if 1 the 0
    //             if(!dfs(node,adj,color,findColor)) return false;
    //         }
    //     }
    //     return true;
    // }

    bool bfs(int src,vector<vector<int>>& adj,vector<int>&color){
        queue<int>q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto &node : adj[frontNode]){
                if(color[frontNode]==color[node]) return false;
                if(color[node]==-1){
                    color[node]=1-color[frontNode];
                    q.push(node);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        // int n=adj.size();
        // vector<int>color(n,-1);
        // for(int i=0;i<n;i++){
        //     if(color[i]==-1){
        //         if(!dfs(i,adj,color,1)) return false;
        //     }
        // }
        int n=adj.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,adj,color)) return false;
            }
        }
        return true;
    }

int main()
{
    return 0;
}