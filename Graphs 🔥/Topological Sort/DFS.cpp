#include<iostream>
using namespace std ;

class Solution {
  public:
  
    void topoDFS(int src,unordered_map<int,vector<int>>&edges,unordered_map<int,bool>&visited,stack<int>&st){
        visited[src]=true;
        for(auto node : edges[src]){
            if(!visited[node]) topoDFS(node,edges,visited,st);
        }
        //backtrack
        st.push(src);
    }
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edge) {
        
        unordered_map<int,vector<int>>edges;
        for(auto it : edge){
            edges[it[0]].push_back(it[1]);
        }
        
       //handling disconnected components
       unordered_map<int,bool>visited;
       stack<int>st;
       for(int i=0;i<V;i++){
           if(!visited[i]) topoDFS(i,edges,visited,st);
       }
       vector<int>ans;
       while(!st.empty()){
           ans.push_back(st.top());
           st.pop();
       }
       return ans;
    }
};

int main()
{
    return 0;
}