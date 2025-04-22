// DSA02011 - MÁY ATM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, k;
vector<ll> nums;
vector<ll> v;
ll ans = LLONG_MAX;

void BackTrack(int pos, ll total, ll cnt){
    if(total == k){
        ans = min(ans, cnt);
        return;
    }
    for(int i = pos; i < n; i++){
        v.push_back(nums[i]);
        total += nums[i];
        if(total <= k)
            BackTrack(i+1, total, cnt+1);
        v.pop_back();
        total -= nums[i];
    }
}

void solve(){
    cin >> n >> k;
    nums.resize(n);
    v.clear();
    ans = LLONG_MAX;
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.rbegin(), nums.rend());
    BackTrack(0, 0, 0);
    cout << (ans == LLONG_MAX ? -1 : ans);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
