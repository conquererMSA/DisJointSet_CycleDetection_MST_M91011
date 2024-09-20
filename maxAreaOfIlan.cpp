/*
https://leetcode.com/problems/max-area-of-island/submissions/1396573109/
*/
class Solution {
public:
    bool vis[50][50];
    int ans;
    int mx;
    vector<pair<int, int>> childPath={{0,1},{0,-1},{-1,0},{1,0}};
    int r, c;
    
    bool isValid(int cr, int cc) {
        if (cr < 0 || cr >= r || cc < 0 || cc >= c) return false;
        return true;
    }
    
    void dfs(int sr, int sc, vector<vector<int>>& grid) {
        vis[sr][sc] = true;
        ans++;
        for (int i = 0; i < 4; i++) {
            int cr = sr + childPath[i].first;
            int cc = sc + childPath[i].second;
            if (isValid(cr, cc) && !vis[cr][cc] && grid[cr][cc] == 1) {
                dfs(cr, cc, grid);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // if (grid.empty()) return 0;
        memset(vis, false, sizeof(vis));
        r = grid.size();
        c = grid[0].size();
        mx = 0;
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans = 0;
                    dfs(i, j, grid);
                    mx = max(mx, ans);
                }
            }
        }
        
        return mx;
    }
};
