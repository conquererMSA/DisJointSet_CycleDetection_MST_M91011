#include<bits/stdc++.h>
using namespace std;
/*
MST ekti graph er multiple path and edge bad diye graph er total cost(weight) komiye ane and graph tike Tree te convert kore.  Zehetu MST multiple edge and path remove kore dey, sehtu kuno cycle create hoy na.

MST graph er sob gulu node ke less cost edge dara interconnect kore, graph er total cost komiye dey. Zodi zodi kuno ekti node e visit korar ekdik path and cots thake tahole Kruskal algo less cost edge-path hisab kore. Beshi cost edge-path bad diye dey.

cost diye edgeList ke sort korte hobe.
check korte hobe edge er node gulu ekoi group er kina...

*/
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
/*
input
5 7
0 1 2
0 2 3
0 3 3
3 4 6
2 4 4
2 1 7
1 4 5

output
12
*/