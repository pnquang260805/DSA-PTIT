// XEM PHIM

#include <bits/stdc++.h>
using namespace std;

/*  https://www.youtube.com/watch?v=8JQOOiFVCMk
    key = STT, value = Weight
    skip = dp[i-1][j]
    pick = dp[i-1][j-w[i]] + v[i]
    dp[i][j] = max(pick, skip)
*/

void solve(){
    int w, n;
    cin >> w >> n;
    vector<int> cows;
    cows.push_back(0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cows.push_back(x);
    }
    vector<vector<int>> dp;
    dp.assign(n+1, vector<int>(w+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            int skip = dp[i-1][j];
            int pick = 0;
            if(j >= cows[i])
                pick = dp[i-1][j-cows[i]] + cows[i];
            dp[i][j] = max(pick, skip);
        }
    }
    cout << dp[n][w];
}

int main(){
    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    //     cout << endl;
    // }   
    solve();
    cout << endl;
}