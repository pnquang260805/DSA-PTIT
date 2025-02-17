// PHẦN TỬ LỚN NHẤT

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int &num : nums)
        cin >> num;
    sort(nums.begin(), nums.end(), greater<int>());
    for(int i = 0; i < k; i++){
        cout << nums[i] << " ";
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