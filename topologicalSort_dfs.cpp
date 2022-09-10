#include<bits/stdc++.h>
using namespace std;

void topologicalSort(int node,vector<int> &vis,stack<int> &st,vector<int> adj[]){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            topologicalSort(it,vis,st,adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V+1,0);
    stack<int> st;
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            topologicalSort(i,vis,st,adj);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main() {
    int tc;
    cin>>tc;
    while(tc--){
        int v,e;
        cin>>v>>e;
        vector<int> adj[v+1];
        for(int i = 0;i<e;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(checkBiparted(adj,v)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
 }