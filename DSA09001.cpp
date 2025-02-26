// CHUYỂN DANH SÁCH CẠNH SANG DANH SÁCH KỀ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int v, e;
    cin >> v >> e;
    map<int,vector<int>> mp;
    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for(int i = 1; i <= v; i++){
        cout << i << ": ";
        sort(mp[i].begin(), mp[i].end());
        for(auto x : mp[i]){
            cout << x << " ";
        }
        cout << endl;
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