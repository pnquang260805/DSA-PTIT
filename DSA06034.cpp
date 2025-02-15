// CẶP SỐ CÓ TỔNG BẰNG K

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    unordered_map<ll, ll> mp; // Lưu số lần xuất hiện của mỗi phần tử
    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        
        // Nếu K - x đã xuất hiện trước đó, cộng dồn vào kết quả
        ans += mp[k - x];

        // Lưu số lần xuất hiện của x vào map
        mp[x]++;
    }

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