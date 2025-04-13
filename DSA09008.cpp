// DSA09008 - ĐẾM SỐ THÀNH PHẦN LIÊN THÔNG

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
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v+10);
    vector<int> parent(v+10, 0);
    vector<bool> visited(v+10);
    int ans = 0;
    for(int i = 1; i <= e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= v; i++){
        if(!visited[i]){
            ans++;
            bfs(i, adj, visited, parent);
        }
    }
    cout << ans;
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
