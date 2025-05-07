// DSA09019 - KIỂM TRA CHU TRÌNH

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vv;

bool bfs(int u, vv adj, vector<bool> &visited, vector<int> &par){
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int v : adj[x]){
            if(!visited[v]){
                visited[v] = true;
                par[v] = x;
                q.push(v);
            }
            else if(v != par[x]){
                return true; // Tồn tại cạnh ngược
            }
        }
    }
    return false;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vv adj(n+1);
    vector<int> par(n+1, 0);
    vector<bool> visited(n+1, false);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool ans = false;
    for(int i = 1; i <= n; i++){
        if(!visited[i])
            ans = (ans || bfs(i, adj, visited, par));
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
