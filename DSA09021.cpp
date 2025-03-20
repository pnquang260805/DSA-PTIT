// DSA09021 - CHUYỂN MA TRẬN KỀ SANG DANH SÁCH KỀ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if(x == 1){
                if (x == 1) {  // Chỉ lưu (i, j) khi i < j để tránh trùng lặp
                    adj[i].push_back(j);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
        cout << endl;   
    }
}