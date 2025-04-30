// DSA09016 - KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ CÓ HƯỚNG VỚI DFS

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vv;

bool dfs(int u, vv &adj, vector<int> &color){
    color[u] = 1;
    for(int v : adj[u]){
        if(color[v] == 0){
            color[v] = 1;
            if(dfs(v, adj, color))
                return true;
        }
        else if(color[v] == 1){
            return true;
        }
    }
    color[u] = 2;
    return false;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vv adj(n+1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int> color(n+1, 0);
    bool ans = false;
    for(int i = 1; i <= n; i++){
        if(color[i] == 0)
            if(dfs(i, adj, color))
                ans = true;
    }
    cout << (ans ? "YES" : "NO");
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
