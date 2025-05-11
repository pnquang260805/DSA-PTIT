// DSA09017 - KIỂM TRA ĐỒ THỊ CÓ PHẢI LÀ CÂY HAY KHÔNG

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<int>> vv;

void dfs(int u, vv &adj, vector<bool> &visited){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v, adj, visited);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vv adj(n+1);
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt = 0;
    vector<bool> visited(n+1, false);
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            dfs(i, adj, visited);
        }
    }
    cout << (cnt == 1 ? "YES" : "NO");
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}