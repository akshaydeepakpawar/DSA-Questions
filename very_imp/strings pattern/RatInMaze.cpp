#include<iostream>
using namespace std ;

int n;
    vector<string>ans;
    
    void solve(vector<vector<int>>& maze,int row,int col,string str)
    {
        if(row < 0 || col < 0 || row > n || col > n || maze[row][col] == 0) return;
        if(row==n && col==n) {
            ans.push_back(str);
            return ;
        }
        maze[row][col]=0;
        solve(maze,row+1,col,str+"D");
        solve(maze,row,col-1,str+"L");
        solve(maze,row,col+1,str+"R");
        solve(maze,row-1,col,str+"U");
        maze[row][col]=1;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
       n=maze.size()-1;
       solve(maze,0,0,"");
       return ans;
    }

int main()
{   
    vector<vector<int>> maze={
        {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}
    };
    ratInMaze(maze);
    for(string str:ans) cout<<str<<endl;
    return 0;
}