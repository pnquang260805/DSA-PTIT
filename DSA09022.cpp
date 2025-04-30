// DSA09022 - DFS TRÊN ĐỒ THỊ CÓ HƯỚNG

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vv;

void dfs(int u, vv &adj, vector<int> &color){
    color[u] = 1;
    cout << u << " ";
    for(int v : adj[u]){
        if(color[v] == 0){
            dfs(v, adj, color);
        }
    }
    color[u] = 2;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vv adj(n+1);
    vector<int> color(n+1, 0);
    while(m--){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
//        adj[y].push_back(x);
    }
    dfs(k, adj, color);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
