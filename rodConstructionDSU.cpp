#include<bits/stdc++.h>
using namespace std;
/*
https://cses.fi/problemset/task/1676
*/
int n, e;
int cmp; // number of components
int mxComSize; // size of the largest component
int parent[100000];
int groupSize[100000];

void dsuInit(int nn) {
    for(int i = 0; i < nn; i++) {
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
    if(leaderOfn1 == leaderOfn2) return;
    if(groupSize[leaderOfn1] > groupSize[leaderOfn2]) {
        parent[leaderOfn2] = leaderOfn1;
        groupSize[leaderOfn1] += groupSize[leaderOfn2];
        mxComSize = max(groupSize[leaderOfn1], mxComSize);
    } else {
        parent[leaderOfn1] = leaderOfn2;
        groupSize[leaderOfn2] += groupSize[leaderOfn1];
        mxComSize = max(groupSize[leaderOfn2], mxComSize);
    }
    cmp--;
}

int main() {
    cin >> n >> e;
    cmp = n; // Initially, every node is its own component
    mxComSize = 1; // Initially, the largest component has size 1
    dsuInit(n);
    while(e--) {
        int u, v;
        cin >> u >> v;
        dsuUnionBySize(u , v); // Assuming 1-based input, adjust to 0-based
        cout << cmp << " " << mxComSize << endl;
    }
    return 0;
}
