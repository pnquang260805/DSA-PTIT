// DSA06043 - ĐIỂM CÂN BẰNG

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n), prefix(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        prefix[i] = (i != 0 ? prefix[i-1] + nums[i] : nums[i]);
    }
    int ans = -1;
    for(int i = 1; i < n-1; i++){
        if(prefix[i] - nums[i] == prefix[i-1] && prefix[n-1] - prefix[i] == prefix[i-1]){
            ans = i+1;
            break;
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