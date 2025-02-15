// SỐ ĐẦU TIÊN BỊ LẶP

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    unordered_map<ll,ll> mp;
    vector<ll> nums;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        nums.push_back(x);
        mp[x]++;
    }
    for(ll i = 0; i < n; i++){
        if(mp[nums[i]] > 1){
            cout << nums[i];
            return;
        }
    }
    cout << "NO";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}