// DSA07017 - PHẦN TỬ BÊN PHẢI NHỎ HƠN

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n), ans(n, -1);
    for(int &num : nums)
        cin >> num;
    for(int i = 0; i < n; i++){
        int next_greater_idx = 0;
        for(int j = i+1; j < n; j++){
            if(nums[i] < nums[j]){
                next_greater_idx = j;
                break;
            }
        }
        for(int j = next_greater_idx + 1; j < n; j++){
            if(nums[j] < nums[next_greater_idx] && next_greater_idx != 0){
                ans[i] = nums[j];
                break;
            }            
        }
    }
    for(int num : ans)
        cout << num << " ";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}