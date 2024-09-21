class Solution {
  public:
    int par[100000];
    int siz[100000];
    void dsuInitialize(int s){
        for(int i=0; i<s; i++){
            par[i]=-1;
            siz[i]=1;
        }
    }
    int findingLeader(int n){
        if(par[n]==-1) return n;
        int l=findingLeader(par[n]);
        par[n]=l;
        return l;
    }
    void dsuUnionBySize(int u, int v){
        int leaderOfU=findingLeader(u);
        int leaderOfV=findingLeader(v);
            if(siz[leaderOfU]>siz[leaderOfV]){
                par[leaderOfV]=leaderOfU;
                siz[leaderOfU]+=siz[leaderOfV];
            }else{
                 par[leaderOfU]=leaderOfV;
                siz[leaderOfV]+=siz[leaderOfU];
            }
        
    }
    bool isCycle(int V, vector<int> adj[]) {
      dsuInitialize(V);
      bool cycle=false;
        for(int u=0; u<V; u++){
            for(int v: adj[u]){
                int parOfU=findingLeader(u);
                int parOfV=findingLeader(v);
                if(parOfU==parOfV) cycle=true;
                else{
                    dsuUnionBySize(u,v);
                }
            }
        }
        return cycle;
        
    }
};