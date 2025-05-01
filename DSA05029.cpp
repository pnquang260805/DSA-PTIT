// DSA05029 - GIẢI MÃ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    if (s[0] == '0'){
        cout << 0;
        return;
    }
    vector<int> dp(s.size() + 1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= s.size(); i++){
        if(s[i-1] > '0')
            dp[i] = dp[i-1];
        if(s[i-2] == '1' || (s[i-2] == '2' && '0' <= s[i-1] && s[i-1] <= '6'))
            dp[i] += dp[i-2];
    }
    cout << dp[s.size()];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
