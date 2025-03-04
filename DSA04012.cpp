// DSA04012 - TÍCH ĐA THỨC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;
vector<ll> nums;
ll ans;
vector<bool> used;
vector<ll> process;

void BackTrack(int pos, ll total){
    if(total == k){
        ans = min(ans, (ll)process.size());
        return;
    }
    for(int i = pos; i < n; i++){
        process.push_back(nums[i]);
            if(total + nums[i] <= k){
                BackTrack(i + 1, nums[i] + total);
            }
            process.pop_back();
    }
}

void solve(){
    nums.clear();
    used.clear();
    process.clear();
    ans = LLONG_MAX;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    used.assign(n, false);
    BackTrack(0, 0);
    if(ans != LLONG_MAX)
        cout << ans;
    else
        cout << -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}