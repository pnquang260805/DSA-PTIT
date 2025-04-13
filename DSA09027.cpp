// DSA09027 - KIỂM TRA ĐƯỜNG ĐI
#include <bits/stdc++.h>
using namespace std;

void bfs(int u, vector<vector<int>> &adj, vector<bool> &visited){
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int v : adj[curr]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void solve(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> adj(m+1);
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int no_query;
    cin >> no_query;
    while(no_query--){
        vector<bool> visited(m+1);
        int u, v;
        cin >> u >> v;
        bfs(u, adj, visited);
        cout << (visited[v] ? "YES" : "NO") << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
