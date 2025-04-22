// DSA05024 - TỔNG BẰNG K

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll const MOD = 1e9+7;

ll sum_mod(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}

ll calc(ll n, vector<ll> nums, vector<ll> &mem){
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
    if(mem[n] != -1)
        return mem[n];
    mem[n] = 0;
    for(ll num : nums){
        if(num <= n){
            mem[n] = sum_mod(mem[n], calc(n-num, nums, mem));
        }
    }
    return mem[n];
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for(ll &num : nums)
        cin >> num;
    vector<ll> mem(k+1, -1);
    calc(k, nums, mem);
    cout << mem[k];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
