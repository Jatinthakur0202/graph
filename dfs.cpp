#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pii vector<int,int>
#define rep(i,a,b) for(int i = a; i<b;i++)
#define ff first
#define ss second
vector<int> ans;
void dfs(int node,vector<int> adj[],vector<int> &vis){
    ans.push_back(node);
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it] == 0){
            dfs(it,adj,vis);
        }
    }
}

void bfsOfGraph(int V, vector<int> adj)
{
    vector<int> vis(V+1,0);
    for(int i=1;i<=V;i++){
        if(vis[i] == 0){
            dfs(i,adj,vis);
        }
    }
}

signed main(){

return 0;
}