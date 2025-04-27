// DSA09014 - KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ VÔ HƯỚNG

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;

bool dfs(int u, int par, vvi &adj, vector<bool> &visited){
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u, adj, visited))
                return true;
        }
        else if (v != par) {
            return true;
        }
    }
    return false;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj(n+1);
    bool found = false;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n+1, false);
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            if(dfs(i, 0, adj, visited))
                found = true;
    }
    cout << (found ? "YES" : "NO");
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
