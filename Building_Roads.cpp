#include<bits/stdc++.h>
using namespace std;
/*
https://cses.fi/problemset/task/1676
*/
int n, e;
int parent[100000];
int groupSize[100000];

void dsuInit(int nn) {
    for(int i = 1; i <= nn; i++) {
        parent[i] = -1;
        groupSize[i] = 1;
    }
}

int dsuLeaderFinding(int node) {
    if(parent[node] == -1) return node;
    int leader = dsuLeaderFinding(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsuUnionBySize(int n1, int n2) {
    int leaderOfn1 = dsuLeaderFinding(n1);
    int leaderOfn2 = dsuLeaderFinding(n2);
    if(groupSize[leaderOfn1] > groupSize[leaderOfn2]) {
        parent[leaderOfn2] = leaderOfn1;
        groupSize[leaderOfn1] += groupSize[leaderOfn2];
    } else {
        parent[leaderOfn1] = leaderOfn2;
        groupSize[leaderOfn2] += groupSize[leaderOfn1];
    }
}

int main() {
    cin >> n >> e;
    dsuInit(n);
    while(e--) {
        int u, v;
        cin >> u >> v;
        dsuUnionBySize(u , v);
    }
    //store all component leaders
    vector<int> leaders;
    for(int i=1; i<=n; i++){
        if(parent[i]==-1) leaders.push_back(i);
    }
    //print number of roads thats connect all leaders;
    cout<<leaders.size()-1<<endl;

    //print each two leaders that connect each others by a road
    for(int i=1; i<leaders.size(); i++){
        cout<<leaders[i-1]<<" "<<leaders[i]<<endl;
            // leader 1          leader 2
    }
    return 0;
}
/*
4 2
1 2
3 4

output
1
2 4
*/
