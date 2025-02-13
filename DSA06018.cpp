// BỔ SUNG PHẦN TỬ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums;
    map<int, bool> appear;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
        appear[num] = true;
    }
    sort(nums.begin(), nums.end());
    int left = nums[0], right = nums[nums.size() - 1];
    int ans = 0;
    for(int i = left; i < right; i++){
        if(appear.find(i) == appear.end())
            ans++;
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
