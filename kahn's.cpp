//tc = O(V+E)
//sc = O(N) + O(N)
#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> in_degree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u])
            in_degree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);
        
    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
        for (int v : adj[u])
            if (--in_degree[v] == 0)
                q.push(v);
    }
    return top_order;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = topoSort(n, adj);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}