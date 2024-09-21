/*
https://leetcode.com/problems/number-of-closed-islands/
*/
class Solution {
public:
    bool vis[300][300];
    vector<pair<int, int>> childPath={{0,1},{0,-1},{-1,0},{1,0}};
    int r, c;
    
    bool isValid(int cr, int cc) {
        if (cr < 0 || cr >= r || cc < 0 || cc >= c) return false;
        return true;
    }
    bool flag;
    void dfs(int sr, int sc, vector<vector<int>>& grid) {
        vis[sr][sc] = true;
        if(sr==0 || sr==r-1||sc==0||sc==c-1){ //last r, last c
            flag=false;
        }
        for (int i = 0; i < 4; i++) {
            int cr = sr + childPath[i].first;
            int cc = sc + childPath[i].second;
            if (isValid(cr, cc) && !vis[cr][cc] && grid[cr][cc] == 0) {
                dfs(cr, cc, grid);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        memset(vis, false, sizeof(vis));
        r = grid.size();
        c = grid[0].size();
        int ans=0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    flag=true;
                    dfs(i, j, grid);
                    if(flag) ans++;
                }
            }
        }
        
        return ans;
    }
};
