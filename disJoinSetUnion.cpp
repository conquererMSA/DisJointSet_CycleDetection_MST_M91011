#include<bits/stdc++.h>
using namespace std;
/*
 DSU directed graph e kaj kore na. Undirected graph e khub sohoje Cycle detect kora zay.
 Duti set er moddye intersaction korle zodi faka/empty set pawya zay sei faka/empty set i hocce disjoin union set. Duita vinno set er intersaction korle faka set pawya zabe.

 Duti set er moddye union korar kkhetre tader moddye kuno common node/element thakte parbe na.
   
 
*/
int parent[100];
int level[100];
int size[100];
void initializeParent(int size){
    for(int i=0; i<=size; i++){
        parent[i]=-1;
        level[i]=0;
        size[i]=1
    }
}
int findParent(int n){ //kuno ekti node er parent return kore, parent assign kore....
    if(parent[n]==-1) return n;
    int leader=findParent(parent[n]);
    parent[n]=leader; //path comprehension
    return leader;
}
//DSU naive version
void dsuUnion(int a, int b){ //parent merge kore and parent assign kore....
    int parA=findParent(a);
    int parB=findParent(b);
    //assign parent
    parent[parB]=parA;

}
void dsuUnionByLevel(int a, int b){ //parent merge kore and parent assign kore....
    int parA=findParent(a);
    int parB=findParent(b);
    // assign parent by checking size
    if(level[parA]>level[parB]){
        parent[parB]=parA;
    }
    else if(level[parA]<level[parB]){
        parent[parA]=parB;
    }
    else{
        parent[parB]=parA;
        level[parA]++;
    }
 }

 void dsuUnionBySize(int a, int b){ //parent merge kore and parent assign kore....
    int parA=findParent(a);
    int parB=findParent(b);
    //assign parent by checking size
    if(size[parA]>size[parB]){
        parent[parB]=parA;
    }
    else if(size[parA]<size[parB]){
        parent[parA]=parB;
    }
    else{
        parent[parB]=parB;
    }
 }
int main(){
    int totalNode;
    cin>>totalNode;
    initializeParent(totalNode);
    // dsuUnion(1,2);
    // dsuUnion(3,4);
    dsuUnionByLevel(1,2);
    dsuUnionByLevel(3,4);
    //find parent from parent[]
    // cout<<parent[1]<<" "<<parent[2]<<endl; //-1 1
    // cout<<parent[3]<<" "<<parent[4]<<endl; //-1 3
    // cout<<findParent(4); //3
   dsuUnionByLevel(2,3); //1 //ekhane 1, 2 er moddye age union kora hoyeche zar parent hoyeche 1. tarpor 3,4 er moddye union korate aprent hoyeche 3. tarpor 2,3 er moddhye union korate 2 er parent 1 and 3 er parent 3 howyay amra 24 no line node 3 er parent hisabe 1 ke assign kore deya hoyeche.
//    cout<<findParent(4);//1
    return 0;
}

/*
sample input output
input


output

*/