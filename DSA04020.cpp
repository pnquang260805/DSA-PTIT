// TÌM KIẾM NHỊ PHÂN

#include <bits/stdc++.h>
using namespace std;

int binSearch(vector<int> nums, int k, int l, int r){
    if(l > r)
        return -1;
    int mid = (l + r) / 2;
    if(nums[mid] == k)
        return mid;
    if(nums[mid] < k)
        return binSearch(nums, k, mid + 1, r);
    if(nums[mid] > k)
        return binSearch(nums, k, l, mid - 1);
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int &num : nums)
        cin >> num;
    int ans = binSearch(nums, k, 0, n-1);
    if(ans == -1)
        cout << "NO";
    else
        cout << ans + 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}