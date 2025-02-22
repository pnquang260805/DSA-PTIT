// BỘ BA SỐ BẰNG K

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool calc(vector<ll> &nums, ll k){
    for(int i = 0; i < nums.size() - 2; i++){
        ll l = i+1, r = nums.size() - 1, temp = k - nums[i];
        while(l < r){
            if(nums[l] + nums[r] < temp)
                l++;
            else if(nums[l] + nums[r] > temp)
                r--;
            else
                return true;
        }
    }
    return false;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for(ll &num : nums)
        cin >> num;
    sort(nums.begin(), nums.end());
    cout << (calc(nums, k) ? "YES" : "NO");
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}