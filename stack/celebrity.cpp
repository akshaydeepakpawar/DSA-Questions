#include<iostream>
using namespace std ;

int Findcelebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        stack<int> st;
        for(int i=0;i<n;i++) st.push(i);
        while(st.size()!=1)
        {
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            if(mat[a][b])   st.push(b);
            else st.push(a);
        }
        int minghtBeCeleb=st.top();
        for(int i=0;i<n;i++)
        {
            if( (mat[minghtBeCeleb][i]==1 || mat[i][minghtBeCeleb]==0)  && i!=minghtBeCeleb ) return -1;
        }
        return minghtBeCeleb;
    }
int main()
{
    return 0;
}