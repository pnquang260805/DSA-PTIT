// TÌM MAX

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

void solve(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int num; cin >> num;
        nums.push_back(num);
    }
    int ans = 0;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < n; i++){
        ans = ((ans % mod) + ((nums[i] % mod) * (i % mod) % mod)) % mod;
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
