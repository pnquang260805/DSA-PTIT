// Tổng gần 0 nhất

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int &num : nums)
        cin >> num;

    int ans = INT_MAX, checker = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            if(checker > abs(nums[i] + nums[j])){
                checker = abs(nums[i] + nums[j]);
                ans = nums[i] + nums[j];
            }
        }
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