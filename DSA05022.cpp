// DSA05022 - KÝ TỰ GIỐNG NHAU

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n+1, 0);
    dp[1] = a;
    for(int i = 1; i <= n; i++){
        int ins = dp[i-1] + a;
        int cp = INT_MAX;
        int del = INT_MAX;
        if(i % 2 == 0)
            cp = dp[i / 2] + c;
        else
            del = dp[(i+1)/2] + c + b;
        dp[i] = min({ins, cp, del});
    }
    cout << dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
