#include<bits/stdc++.h>
using namespace std;
/*
DSU edge niye kaj kore, DSU edge er direction recognized korte pare na. Tai DSU undirected graph e cycle detect korte pare, kintu directed graph e cycle detect korte pare na.


DSU duita node er moddye cycle detect kore na. DSU diye cycle detect korar jonno at least 3 ti node dorkar.

CycleDetection: zodi ekti edge er duiti node er leader same hoy tahole ei edge cycle create korbe.
*/
int n,e;
int parent[100];
int groupSize[100];
void dsuInit(int nn){
    for(int i=0; i<nn; i++){
        parent[i]=-1;
        groupSize[i]=1;
    }
}
int dsuLeaderFinding(int node){
    if(parent[node]==-1) return node;
    int leader=dsuLeaderFinding(parent[node]);
    parent[node]=leader;
    return leader;
}
void dsuUnionBySize(int n1, int n2){
    int leaderOfn1=dsuLeaderFinding(n1);
    int leaderOfn2=dsuLeaderFinding(n2);
    if(groupSize[leaderOfn1]>groupSize[leaderOfn2]){
        parent[leaderOfn2]=leaderOfn1;
        groupSize[leaderOfn1]+=groupSize[leaderOfn2];
    }
    else{
        parent[leaderOfn1]=leaderOfn2;
        groupSize[leaderOfn2]+=groupSize[leaderOfn1];
    }
}
int main(){
    cin>>n>>e;
    dsuInit(n);
    bool cycle=false;
    while(e--){
        int a,b;
        cin>>a>>b;
        int leaderOfa=dsuLeaderFinding(a);
        int leaderOfb=dsuLeaderFinding(b);
        if(leaderOfa==leaderOfb){
            cycle=true;
        }
        else{
            dsuUnionBySize(a,b);
        }
    }
    if(cycle) cout<<"Cycle Founded";
    else cout<<"No cycle";
    return 0;
}