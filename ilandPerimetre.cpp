/*
https://leetcode.com/problems/island-perimeter/
*/

class Solution {
public:
    int ans=0;
    int r,c;
    bool vis[100][100];
    bool isValid(int i, int j){
        if (i < 0 || i >= r || j < 0 || j >= c)
           return false;
        return true;
    }
    vector<pair<int,int>> childPath={{0,1},{0,-1},{-1,0},{1,0}};
    void dfs(int sr, int sc,vector<vector<int>>& grid){
        vis[sr][sc]=true;
        for(int i=0; i<4; i++){
            int cr=sr+childPath[i].first;
            int cc=sc+childPath[i].second;
            if(isValid(cr,cc)){
                if(grid[cr][cc]==0) ans++;
            }
            else ans++;
            if(isValid(cr,cc)&&!vis[cr][cc]&&grid[cr][cc]!=0){
                dfs(cr,cc, grid);
            }
        }
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        memset(vis, false, sizeof(vis));
        r=grid.size();
        c=grid[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};