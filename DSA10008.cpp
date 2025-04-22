// DSA10008 - DIJKSTRA
// https://www.youtube.com/watch?v=JqOPBodZmLk&list=WL&index=5

/* Note:
    Luôn giữ khoảng cách trong priority queue tăng dần
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int n, m, s;
vector<vector<ii>> adj; // (u, w)

void dijkstra(int k){
    priority_queue<ii, vector<ii>, greater<ii>> q; // q {kc, u}
    vector<int> distance(n+1, INT_MAX);
    distance[k] = 0;
    q.push({distance[k], k});
    while(!q.empty()){
        auto [dist, u] = q.top();
        q.pop();
        if(dist <= distance[u]){
            for(auto it : adj[u]){
                auto [v, w] = it;
                if(distance[v] > distance[u] + w){
                    distance[v] = distance[u] + w;
                    q.push({distance[v], v});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout << distance[i] << " ";
}

void solve(){
    cin >> n >> m >> s;
    adj.clear();
    adj.resize(n+1, vector<ii>(m+1));
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    dijkstra(s);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
