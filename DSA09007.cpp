// DSA09007 - ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ VÔ HƯỚNG

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &parent){
    visited[u] = true;
    for(int x : adj[u]){
        if(!visited[x]){
            visited[x] = true;
            parent[x] = u;
            dfs(x, adj, visited, parent);
        }
    }
}

void bfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &parent){
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int v : adj[curr]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = curr;
                q.push(v);
            }
        }
    }
}

void trace(int curr, int target, vector<int> &parent){
    vector<int> path;
    while(curr != target){
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(target);
    reverse(path.begin(), path.end());
    for(int x : path)
        cout << x << " ";
}

void solve(){
    int m, n, s, e;
    cin >> m >> n >> s >> e;
    vector<vector<int>> adj(m+1);
    vector<bool> visited(m+1);
    vector<int> parent(m+1, 0);
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(s, adj, visited, parent);
    if(!visited[e]){
        cout << -1;
    }
    else{
        trace(e, s, parent);
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
