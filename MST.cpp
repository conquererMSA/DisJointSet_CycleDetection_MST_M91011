#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int u,v,w;
    Edge(int w, int u, int v){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

int parent[100];
int groupSize[100];

void dsuInit(int nn){
    for(int i=0; i<nn; i++){
        parent[i] = -1;
        groupSize[i] = 1;
    }
}

int dsuLeaderFinding(int node){
    if(parent[node] == -1) return node;
    return parent[node] = dsuLeaderFinding(parent[node]); // Path compression
}

void dsuUnionBySize(int u, int v){
    int leaderOfu = dsuLeaderFinding(u);
    int leaderOfv = dsuLeaderFinding(v);
    if(leaderOfu != leaderOfv){
        if(groupSize[leaderOfu] > groupSize[leaderOfv]){
            parent[leaderOfv] = leaderOfu;
            groupSize[leaderOfu] += groupSize[leaderOfv];
        } else {
            parent[leaderOfu] = leaderOfv;
            groupSize[leaderOfv] += groupSize[leaderOfu];
        }
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    dsuInit(n);
    vector<Edge> edgeList;
    
    while(e--){
        int u,v,w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(w, u, v));
    }
    
    // Sorting the edges by their weights
    sort(edgeList.begin(), edgeList.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });

    int minimumConnectionCost = 0;

    for(Edge ed : edgeList){
        int leaderOfU = dsuLeaderFinding(ed.u);
        int leaderOfV = dsuLeaderFinding(ed.v);
        //zodi leaderOfU and leaderOfV same hoy tahole ed.u and ed.v ekoi group er. tarmane already tader moddye dsu unnion kora hoyeche.
        if(leaderOfU != leaderOfV){
            dsuUnionBySize(ed.u, ed.v);
            minimumConnectionCost += ed.w;
        }
    }
    
    cout << minimumConnectionCost << endl;
    return 0;
}
