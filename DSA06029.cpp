// DSA06029 - SẮP XẾP CHÈN - LIỆT KÊ NGƯỢC

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int &num : nums)
        cin >> num;
    vector<vector<int>> steps(n);
    steps[0].push_back(nums[0]);
    for(int i = 1; i < n; i++){
        int key = nums[i];
        int j = i-1;
        while(j >= 0 && key < nums[j]){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
        for(int l = 0; l <= i; l++){
            steps[i].push_back(nums[l]);
        }
    }
    for(int i = n-1; i >= 0; i--){
        cout << "Buoc " << i << ": ";
        for(int j : steps[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
