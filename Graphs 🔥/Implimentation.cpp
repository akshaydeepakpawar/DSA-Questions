#include<iostream>
#include <list>
using namespace std ;

// class Graph{
//     public:
//     unordered_map<int,list<int>> adjList;

//     void addEdge(int u, int v,bool directed){
//         if(directed){
//             adjList[u].push_back(v);
//         }else{
//             adjList[u].push_back(v);
//             adjList[v].push_back(u);
//         }
//     }
//     void printGraph(int n){
//         for(int i=0;i<=n;i++){
//             cout<<i <<" : {";
//             for(int i : adjList[i]) cout<<i<<",";
//             cout<<"}";
//             cout<<endl;
//         }
//     }
// };

//GRAPH with weights

// class Graph{
//     public:
//     unordered_map<int,list<pair<int,int>>> adjList;

//     void addEdge(int u, int v,int w, bool directed){
//         if(directed){
//             adjList[u].push_back({v,w});
//         }else{
//             adjList[u].push_back({v,w});
//             adjList[v].push_back({u,w});
//         }
//     }
//     void printGraph(int n){
//         for(int i=0;i<=n;i++){
//             cout<<i<<" : ";
//             for(auto it : adjList[i]){
//                 cout<<"{"<<it.first<<","<<it.second<<"}";
//             }
//             cout<<endl;
//         }
//     }
// };


int main()
{
    // Graph g;
    // g.addEdge(0,1,1);
    // g.addEdge(0,2,1);
    // g.addEdge(1,2,1);
    // g.addEdge(2,3,1);

    // g.printGraph(3);
    // Graph g;
    // g.addEdge(0,1,1,2);
    // g.addEdge(0,2,1,5);
    // g.addEdge(1,2,1,4);
    // g.addEdge(2,3,1,10);

    // g.printGraph(3);

    return 0;
}