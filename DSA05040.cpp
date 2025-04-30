// DSA05040 - DÃY TAM GIÁC DÀI NHẤT

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef vector<vector<ll>> vv;

void solve(){
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for(ll &num : nums)
        cin >> num;
    vector<int> l(n+1, 0), r(n+1, 0);
    l[0] = 1;
    r[0] = 1;
    for(int i = 1; i < n; i++){
        if(nums[i] > nums[i-1]){
            l[i] = l[i-1] + 1;
        }
        else
            l[i] = 1;
    }
    for(int i = n-1; i >= 0; i--){
        if(nums[i] > nums[i+1])
            r[i] = r[i+1] + 1;
        else
            r[i] = 1;
    }
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        ans = max(ans, l[i] + r[i] - 1);
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
