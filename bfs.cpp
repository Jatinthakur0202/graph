#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define pii vector<int,int>
#define rep(i,a,b) for(int i = a; i<b;i++)
#define ff first
#define ss second
vector<int> bfs;

void bfsOfGraph(int V,vector<int> adj[]){
    vector<int> vis(V+1,0);

    for(int i=1;i<=V;i++){
        if(vis[i]==0){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it:adj[node]){
                    if(vis[it]==0){
                        q.push(it);
                        vis[it]=1;
                    }
                }

            }
        }
    }
}


 int main() {
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfsOfGraph(n,adj);
    
    cout<<endl;
    cout<<"BFS of graph is:";
    for(auto it:bfs){
        cout<<it<<" ";
    }

    return 0;
 }

