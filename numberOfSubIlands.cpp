/*
https://leetcode.com/problems/count-sub-islands/
*/
class Solution {
public:
    bool vis[500][500]; 
    vector<pair<int, int>> childPath={{0,1},{0,-1},{-1,0},{1,0}};
    int r, c; 

   
    bool isValid(int cr, int cc) {
        return cr >= 0 && cr < r && cc >= 0 && cc < c;
    }
    void dfs(int sr, int sc, vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool &isSubIsland) {
        vis[sr][sc] = true;
        if (grid1[sr][sc] == 0) {
            isSubIsland = false;
        }

        for (int i = 0; i < 4; i++) {
            int cr = sr + childPath[i].first;
            int cc = sc + childPath[i].second;
            if (isValid(cr, cc) && !vis[cr][cc] && grid2[cr][cc] == 1) {
                dfs(cr, cc, grid1, grid2, isSubIsland);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        memset(vis, false, sizeof(vis));
        r = grid1.size();
        c = grid1[0].size();
        int ans = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    bool isSubIsland = true;
                    dfs(i, j, grid1, grid2, isSubIsland);
                    if (isSubIsland) ans++;
                }
            }
        }

        return ans;
    }
};
