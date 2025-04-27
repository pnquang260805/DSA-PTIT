// DSA04010 - DÃY CON LIÊN TIẾP CÓ TỔNG LỚN NHẤT

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n+1, 0), res(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
        res[i] = (res[i-1] + nums[i] > 0 ? res[i-1] + nums[i] : 0);
    }
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++){
        ans = max(ans, res[i]);
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
