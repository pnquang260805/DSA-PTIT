// DSA09026 - ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ CÓ HƯỚNG

#include <bits/stdc++.h>
using namespace std;

void bfs(int u, vector<vector<int>> &adj, vector<int> &parent, vector<bool> &visited){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int x : adj[curr]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
                parent[x] = curr;
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
    int v, e, start_point, end_point;
    cin >> v >> e >> start_point >> end_point;
    vector<vector<int>> adj(v+1);
    vector<int> parent(v+1, 0);
    vector<bool> visited(v+1, false);
    vector<int> path;
    for(int i = 1; i <= e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
//        adj[y].push_back(x);
    }
    bfs(start_point, adj, parent, visited);
    if(!visited[end_point]){
        cout << -1;
    }
    else{
        trace(end_point, start_point, parent);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
