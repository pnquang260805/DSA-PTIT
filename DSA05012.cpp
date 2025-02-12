// TỔ HỢP C(n, k)

#include <bits/stdc++.h>
using namespace std;

// C(n, k) = C(n-1, k) + C(n-1, k-1)

const int MOD = 1e9+7;

int calc(int n, int k, vector<vector<int>> &mem){
    if(k > n)
        return 0;
    if(k == 0)
        return 1;
    if(mem[n][k] != -1)
        return mem[n][k];
    mem[n][k] = ((calc(n-1, k, mem) % MOD) + (calc(n-1, k-1, mem) % MOD)) % MOD;
    return mem[n][k];
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> mem;
    mem.assign(n+1, vector<int>(k+1, -1));
    int ans = calc(n,k,mem);
    cout << ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
