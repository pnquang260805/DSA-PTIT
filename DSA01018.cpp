// DSA01018 - TẬP CON LIỀN KỀ PHÍA TRƯỚC

#include <bits/stdc++.h>
using namespace std;

// 123 -> 124 -> 125 -> 134 -> 135

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(k);
    for(int &num : nums)
        cin >> num;
    // n - (k - i)
    int i = k-1;
    while(i >= 0 && nums[i] <= nums[i-1] + 1){
        i--;
    }
    if(i < 0){
        for(int j = 0; j < k; j++){
            cout << (n - k + 1 + j) << ' ';
        }
    }
    else{
        nums[i]--;
        for(int j = i + 1; j < k; j++){
            nums[j] = n - k + 1 + j;
        }
        for(int num : nums)
            cout << num << " ";
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
