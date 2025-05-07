// DSA09010 - KIỂM TRA TÍNH LIÊN THÔNG MẠNH

/*  Kosaraju
    Đồ thị liên thông mạnh là đồ thị có hướng có mọi đỉnh đều có đường đi với nhau
    Ví dụ:
    1-->2
    ^   |
    |   v
    4<--3

    B1: DFS trên G -> lưu vào 1 stack
    B2: Xây dựng transposed graph
    B3: pop các đỉnh trong stack và gọi DFS trên TG
*/
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj, tg;
vector<int> topo;
vector<int> color;

void dfs1(int u){
    color[u] = 1;
    for(int v : adj[u]){
        if(color[v] == 0){
            color[v] = 1;
            dfs1(v);
        }
    }
    topo.push_back(u);
    color[u] = 2;
}

void dfs2(int u){
    color[u] = 1;
    for(int v : tg[u]){
        if(color[v] == 0){
            color[v] = 1;
            dfs2(v);
        }
    }
    color[u] = 2;
}

void solve(){
    adj.clear();
    tg.clear();
    topo.clear();
    color.clear();

    cin >> n >> m;
    adj.resize(n+1);
    tg.resize(n+1);
    color.assign(n+1, 0);

    int scc = 0;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        tg[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            dfs1(i);
        }
    }
    color.assign(n+1, 0);
    reverse(topo.begin(), topo.end());
    for(int i : topo){
        if(color[i] == 0){
            scc++;
            dfs2(i);
        }
    }
    cout << (scc == 1 ? "YES" : "NO"); // đồ thị liên thông mạnh khi và chỉ khi scc = 1 (strong connective component)
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
