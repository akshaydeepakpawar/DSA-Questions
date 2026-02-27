#include <iostream>
using namespace std;

class Solution {
public:

    vector<int>parent,rank;

    char find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent) return ;
        else if(rank[x_parent]>rank[y_parent])
            parent[y_parent]=x_parent;
        else if(rank[x_parent]<rank[y_parent])
            parent[x_parent]=y_parent;
        else{
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
    }
};

int main()
{
    return 0;
}