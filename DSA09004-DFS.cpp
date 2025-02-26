// DFS TRÊN ĐỒ THỊ VÔ HƯỚNG

#include <bits/stdc++.h>
using namespace std;

void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited){
    visited[u] = true;
    cout << u << " ";

    for(int v : adj[u]){
        if(!visited[v]){
            DFS(v, adj, visited);
        }
    }
}

void solve(){
    int v, e, u;
    cin >> v >> e >> u;
    vector<vector<int>> adj(v+1);
    for(int i = 1; i <= e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(v+1, false);
    DFS(u, adj, visited);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}