// TỔNG LỚN NHẤT CỦA DÃY CON KHÔNG KỀ NHAU

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n), dp(n, 0);
    for(int &num : nums)
        cin >> num;
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    cout << *max_element(dp.begin(), dp.end());
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
