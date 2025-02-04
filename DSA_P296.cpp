// Dãy con có tổng lớn nhất
// dùng mảng cộng dồn

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for(int &x : nums)
        cin >> x;
    vector<int> prefix(n, 0);
    nums[0] > 0 ? prefix[0] = nums[0] : prefix[0] = 0;
    for(int i = 1; i < n; i++){
        prefix[i] = max(prefix[i-1], prefix[i-1] + nums[i]);
    }
    while(q--){
        int left, right;
        cin >> left >> right;
        left--; right--;
        cout << prefix[right] - prefix[left - 1] << endl;
    }
}
