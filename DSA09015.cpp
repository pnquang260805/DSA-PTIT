// DSA09015 - KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ CÓ HƯỚNG

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef pair<int,int> ii;

bool bfs(int u, int par, vvi &adj, vector<bool> &visited){
    queue<ii> q; // u - parrent
    q.push({u, 0});
    visited[u] = true;
    while(!q.empty()){
        auto [curr, parent] = q.front();
        q.pop();
        for(int v : adj[curr]){
            if(!visited[v]){
                visited[v] = true;
                q.push({v, curr});
            }
            else if(visited[v] && v != parent){
                return true;
            }
        }
    }
    return false;
}
// Có hướng --> DFS
bool dfs(int u, int par, vvi &adj, vector<bool> &visited, vector<bool> &in_stack){
    visited[u] = true;
    in_stack[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            if(dfs(v, u, adj, visited, in_stack)){
                return true;
            }
        }
        else if(in_stack[v]){ // Tồn tại cạnh ngược
            return true;
        }
    }
    in_stack[u] = false;
    return false;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vvi adj(n+1);
    vector<bool> visited(n+1, false);
    vector<bool> in_stack(n+1, true);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    bool found = false;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(dfs(i, 0, adj, visited, in_stack)){
                found = true;
            }
        }
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
