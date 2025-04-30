// DSA06035 - DÃY TAM GIÁC DÀI NHẤT

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for(ll &num : nums)
        cin >> num;
    vector<ll> inc(n, 0), dec(n, 0);
    inc[0] = 1;
    dec[0] = 1;
    for(ll i = 1; i < n; i++){
        if(nums[i] > nums[i-1])
            inc[i] = inc[i-1] + 1;
        else
            inc[i] = 1;
    }
    for(ll i = n-1; i >= 0; i--){
        if(nums[i] > nums[i+1])
            dec[i] = dec[i+1] + 1;
        else
            dec[i] = 1;
    }
    ll ans = INT_MIN;
    for(ll i = 0; i < n; i++){
        ans = max(ans, inc[i] + dec[i] - 1);
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
