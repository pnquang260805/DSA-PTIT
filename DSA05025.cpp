// Con ếch

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<long long> dp(n+1, 0);
    long long temp = 0; // Số bước leo lên bậc trước đó

    // tạo cơ sở
    for(int i = 1; i <= min(3, n); i++){
        dp[i] = temp + 1; // cộng 1 do có 1 bước lên thẳng
        temp += dp[i];
    }

    for(long long stair = 4; stair <= n; stair++){
        for(long long step = 1; step <= 3; step++){
            dp[stair] += dp[stair - step];
        }
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
