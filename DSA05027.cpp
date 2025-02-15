//  CÁI TÚI

#include <bits/stdc++.h>
using namespace std;    

/*
    pick = weight_remain >= weight[i] ? dp[i-1][weight_remain - weight[i]] + value[i] : 0;
    skip = dp[i-1][weight_remain - 1]
    dp[i][j] = max(pick, skip) 
*/

void solve(){
    int n, w;
    cin >> n >> w;
    vector<int> values;
    vector<int> weights;
    values.push_back(0);
    weights.push_back(0);

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        weights.push_back(temp);
    }

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        values.push_back(temp);
    }


    vector<vector<int>> dp;
    dp.assign(n+1, vector<int>(w+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            int skip = dp[i-1][j];
            int pick = (j >= weights[i]) ? (dp[i-1][j-weights[i]] + values[i]) : 0;
            dp[i][j] = max(pick, skip);
        }
    }
    cout << dp[n][w];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}