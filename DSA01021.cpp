// TỔ HỢP TIẾP THEO

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    unordered_map<int, bool> mem;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        mem[x] = true;
        nums.push_back(x);
    }
    int i = k - 1;
    while(i >= 0 && nums[i] == n - (k - i -1)){
        i--;
    }
    if(i < 0)
        cout << k;
    else{
        nums[i]++;
        int ans = 0;
        if(mem.find(nums[i]) == mem.end())
            ans++;
        for(int j = i + 1; j < k; j++){
            nums[j] = nums[j-1] + 1;
            if(mem.find(nums[j]) == mem.end())
                ans++;
        }
        cout << ans;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
