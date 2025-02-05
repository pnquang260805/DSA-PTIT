#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n), dp(n);
    for(int &x : nums){
        cin >> x;
    }
    for(int i = 0; i < n; i++){
        dp[i] = nums[i];
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
        cout << "\n";
    }
    return 0;
}