// NHÀ KHÔNG KỀ NHAU

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll houseRobber(int pos, int &n, vector<int> &items,vector<ll> &mem){
    // Không có biến total ở trong param
    if(pos < 0)
        return 0;
    if(mem[pos] != -1){
        return mem[pos];
    }
    ll pick = houseRobber(pos-2, n, items, mem) + items[pos];
    ll skip = houseRobber(pos-1, n, items, mem);
    mem[pos] = max(pick, skip);
    return mem[pos];
}

void solve(){
    int n;
    cin >> n;
    vector<int> items;
    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        items.push_back(value);
    }
    vector<ll> mem;
    mem.assign(n+1,-1);
    cout << houseRobber(n-1, n, items, mem);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
