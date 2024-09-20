/*
https://leetcode.com/problems/find-if-path-exists-in-graph/
*/
class Solution {
public:
    vector<int> v[200000];
    bool vis[200005];
    void dfs(int s){
        vis[s]=true;
        for(int child:v[s]){
            if(!vis[child]){
                dfs(child);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        for(vector<int> i:edges){
            int a=i[0];
            int b=i[1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(s);
        return vis[d];
    }
};