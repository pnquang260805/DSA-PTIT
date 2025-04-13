// DSA09025 - ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ CÓ HƯỚNG

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<int> &parrent, vector<bool> &visited){
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            parrent[v] = u;
            dfs(v, adj, parrent, visited);
        }
    }
}

void trace(int curr, int target, vector<int> &parrent, vector<int> &path){
    while(curr != target){
        path.push_back(curr);
        curr = parrent[curr];
    }
    path.push_back(target);
    reverse(path.begin(), path.end());
}

void solve(){
    int v, e, start_point, end_point;
    cin >> v >> e >> start_point >> end_point;
    vector<vector<int>> adj(v+1);
    vector<int> parrent(v+1, 0);
    vector<bool> visited(v+1, false);
    vector<int> path;
    for(int i = 1; i <= e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
//        adj[y].push_back(x);
    }
    dfs(start_point, adj, parrent, visited);
    if(!visited[end_point]){
        cout << -1;
    }
    else{
        trace(end_point, start_point, parrent, path);
        for(int x : path)
            cout << x<< " ";
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
