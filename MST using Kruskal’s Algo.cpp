#include<bits/stdc++.h>
bool comp(vector<int>& a,vector<int> &b){
    if(a[2]<=b[2]) return true;
    else           return false;
}
int findPar(int node,vector<int> &parent){
     // Time: O(4α) == O(4) == O(1) => constant time
    if(parent[node] == node)
        return node;
    else
        return parent[node] = findPar(parent[node],parent);
}
void unionn(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findPar(u,parent);
    v = findPar(v,parent);
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    // n, m ==> nodes, edges
	// step 1:
    sort(graph.begin(),graph.end(),comp);
    
    // step 2:
    vector<int> parent(n+1);
    // initially parent of every node is itself
    for(int i=1;i<=n;i++) parent[i] = i;
    vector<int> rank(n+1,0);
    
    // step 3:
    int mstWt = 0;
    for(auto &edg:graph){
        if(findPar(edg[0],parent) != findPar(edg[1],parent)){
            mstWt += edg[2]; // edge included in MST
            unionn(edg[0],edg[1],parent,rank);
        }
    }
    return mstWt;
}

// Time: O(E log E) + O( E )
//
