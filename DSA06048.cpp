// DSA06048 - SỐ LẦN QUAY VÒNG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll> nums(n);
    for(ll &num : nums)
        cin >> num;
    cout << (n - nums[0] + 1) % n;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}