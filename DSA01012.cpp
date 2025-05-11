// DSA01012 - MÃ GRAY 1
/*  
    Gray(n)=n⊕(n>>1)
    Trong đó >> là dịch phải, ^ là XOR.
    Có tổng cộng 2^n mã Gray.
    Duyệt i từ 0 đến 2^n - 1, in i ^ (i >> 1)
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef vector<vector<ll>> vv;

void solve(){
    int n;
    cin >> n;
    int k = pow(2, n);
    for(int i = 0; i < k; i++){
        int gray = i ^ (i >> 1);
        bitset<64> ans(gray);
        cout << ans.to_string().substr(64-n) << " ";
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