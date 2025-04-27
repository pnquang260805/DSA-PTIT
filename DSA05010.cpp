// DSA05010 - DÃY CON DÀI NHẤT CÓ TỔNG CHIA HẾT CHO K

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> nums;
vector<vector<int>> mem;

int calc(int i, int mod){
    if(i >= n)
        return (mod == 0) ? 0 : INT_MIN;
    if(mem[i][mod] != -1)
        return mem[i][mod];
    int skip = calc(i+1, mod);
    int pick = calc(i+1, (mod + nums[i]) % k) + 1;
    mem[i][mod] = max(pick, skip);
    return mem[i][mod];
}

void solve(){
    cin >> n >> k;
    nums.resize(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    mem.assign(n, vector<int>(k, -1));
    int ans = calc(0, 0);
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
