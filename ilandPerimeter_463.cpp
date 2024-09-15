/*
https://leetcode.com/problems/island-perimeter/description/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   int r,c;
   int ans=0;
   bool vis[101][101];
    vector<pair<int, int>> childPath={{0,1},{0,-1},{-1,0},{1,0}};
    bool isValid(int cr,int cc){
        if(cr<0 || cr<=r || cc<0 || cc<=c) return false;
        return true;
    }
    void dfs(int sr, int sc,vector<vector<int>>& grid){
        vis[sr][sc]=true;
        for(auto child:childPath){
            int childR=child.first;
            int childC=child.second;
            if(isValid(childR, childR)){
                if(grid[childR][childC]==0) ans++;
            }
            else{
                ans++;
            }
            if(isValid(childR, childC) && !vis[childR][childC] && grid[childR][childC]==1){
                dfs(childR, childC, grid);
            }
        }
 
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        memset(vis, false, sizeof(vis));
        r=grid.size(); //row
        c=grid[0].size(); //col
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};