// DSA06027 - SẮP XẾP ĐỔI CHỖ TRỰC TIẾP - LIỆT KÊ NGƯỢC

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int &num : nums)
        cin >> num;
    vector<vector<int>> steps;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(nums[j] < nums[i]){
                swap(nums[i], nums[j]);
            }
        }
        steps.push_back(nums);
    }
    for(int j = steps.size() - 1; j >= 0; j--){
        cout << "Buoc " << j+1 << ": ";
        for(int x : steps[j]){
            cout << x << " ";
        }
        cout << endl;
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
