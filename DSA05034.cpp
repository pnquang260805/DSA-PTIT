// TỔNG SỐ CÁCH DI CHUYỂN

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int calc(int pos, int n, int k, vector<int> &mem){
    if(pos < 0)
        return 0;
    if(pos == 0)
        return 1;
    if(mem[pos] != -1)
        return mem[pos];
    mem[pos] = 0;
    for(int i = 1; i <= k; i++){
            mem[pos] =((mem[pos] % mod) + (calc(pos-i, n, k, mem)%mod)) %mod;
    }
    return mem[pos];
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> mem;
    mem.assign(n+1, -1);
    int ans = calc(n,n,k,mem);
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
