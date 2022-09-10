// graph that can be colour with two colours such 
//that no two adjacent vertices have same colour.

//if a graph has odd length cycle then it can't be biparted

// we using bfs to check if a graph is biparted or not

#include<bits/stdc++.h>
using namespace std;

bool isBiparted(vector<int> adj[],vector<int> &color,int src){
  queue<int> q;
  q.push(src);
  color[src]=1;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    for(auto it:adj[node]){
      if(color[it]==-1){
        color[it]=1-color[node];
        q.push(it);
      }
      else if(color[it]==color[node]){
        return false;
      }
    }
  }
    return true;
}
bool checkBiparted(vector<int> adj[],int v){
    vector<int> color(v,-1);
    for(int i=1;i<=v;i++){
        if(color[i]==-1){
            if(!isBiparted(adj,color,i)){
                return false;
            }
        }
    }
    return true;
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