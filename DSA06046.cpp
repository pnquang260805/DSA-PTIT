// DSA06046 - CHÊNH LỆCH NHỎ NHẤT

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll> nums(n);
    for(ll &num : nums)
        cin >> num;
    sort(nums.begin(), nums.end());
    ll ans = LLONG_MAX;
    for(int i = 1; i < n; i++){
        ans = min(ans, abs(nums[i] - nums[i-1]));
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