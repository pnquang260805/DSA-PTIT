// DSA05030 - DI CHUYỂN VỀ GỐC TỌA ĐỘ

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll calc(int n, int m, vector<vector<ll>> &mem){
    if(n < 0 || m < 0)
        return 0;
    if(n == 0 && m == 0)
        return 1;

    if(mem[n][m] != -1)
        return mem[n][m];

    mem[n][m] = calc(n-1, m, mem) + calc(n, m-1, mem);
    return mem[n][m];
}

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mem(n+1, vector<ll>(m+1, -1));
    ll ans = calc(n, m, mem);
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