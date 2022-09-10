//tc : O(V+E)
//sc : O(V+E)
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pii vector<int,int>
#define rep(i,a,b) for(int i = a; i<b;i++)
#define ff first
#define ss second
bool check_cycle(int node,int parent, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it] == 0){
            if(check_cycle(it,node,vis,adj)){
                return true;
            }
        }
        else if(it != parent){
                return true;
            }
        
    }
    return false:
}

bool iscycle(int v, vector<int> adj[]){
    vector<int> vis(v+1,0);
    for(int i = 1;i<=v;i++){
        if(!vis[i]){
            if(check_cycle(i,-1,vis,adj)){
                return true;
            }
        }
    }
    return false;
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
        if(iscycle(v,adj)){
            cout<<"cycle is present"<<endl;
        }
        else{
            cout<<"cycle is not present"<<endl;
        }
    }
    return 0;
 }