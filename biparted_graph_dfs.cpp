#include<bits/stdc++.h>
using namespace std;
bool isBiparted(vector<int> adj[],vector<int> &color, int scr){
    color[scr] = 1;
    for(auto it:adj[scr]){
        if(color[it] == -1){
            color[it] = 1-color[scr];
            if(!isBiparted(adj,color,it)){
                return false;
            }
        }
        else if(color[it] == color[scr]){
            return false;
        }
    }
    return true;
}

bool checkBiparted(vector<int> adj[], int v){
    vector<int> color(v+1,-1);
    for(int i=1;i<=v;i++){
        if(color[i] == -1){
           if(!isBiparted(adj,color,i)){
                return false;
            }
        }
    }
    return true;
}

int main(){
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