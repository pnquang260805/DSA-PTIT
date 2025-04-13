// DSA09024 - BFS trên đồ thị có hướng
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited){
    visited[u] = true;
    cout << u << " ";
    for(int x : adj[u]){
        if(!visited[x]){
            dfs(x, adj, visited);
        }
    }
}

void bfs(int u, vector<vector<int>> &adj, vector<bool> &visited){
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for(int x : adj[curr]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
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
    }
    queue<int> q;
    vector<bool> visited(v+1, false);
    bfs(u, adj, visited);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
