// CẶP SỐ TỔNG BẰNG K

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    int ans = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] <= m)
            for(int j = nums.size() - 1; j > i; j--){
                if(nums[i] + nums[j] == m){
                    ans++;
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
