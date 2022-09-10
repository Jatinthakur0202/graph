//N will be number of nodes
//M will be number of edges
//N and M will be given in first line of input
//Next M lines will contain two integers u and v denoting an edge from u to v
//first way is to use adjacency matrix
//second way is to use adjacency list
//third way is to use adjacency list with vector
//fourth way is to use adjacency list with set

 #include<bits/stdc++.h>
 using namespace std;
 int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<ilnt,int>> adj[n+1];
    for(int i=0;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        cout<<i<<"->";
        for(auto it:adj[i]){
            cout<<"("<<it.first<<","<<it.second<<")";
        }
        cout<<endl;
    }
    return 0;
 }