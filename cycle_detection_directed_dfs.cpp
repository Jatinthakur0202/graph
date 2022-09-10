#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis) {
    vis[node] = 1;
    dfsVis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(isCyclic(it, adj, vis, dfsVis)) {
                return true;
            }
        } else if(dfsVis[it]) {
            return true;
        }
    }
    dfsVis[node] = 0;
    return false;
}

bool Cyclic(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> dfsVis(V, 0);
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(isCyclic(i, adj, vis, dfsVis)) {
                return true;
            }
        }
    }
    return false;
}
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int V, E;
        cin>>V>>E;
        vector<int> adj[V];
        for(int i=0;i<E;i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        int flag = Cyclic(V, adj);
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}