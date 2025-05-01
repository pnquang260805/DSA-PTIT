// DSA05028 - BIẾN ĐỔI XÂU
// https://www.geeksforgeeks.org/edit-distance-dp-5/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
    // Chuỗi 1 rỗng --> cần insert thêm s2.size
    for(int i = 0; i <= s1.size(); i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= s2.size(); i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                int ins = dp[i][j-1];
                int del = dp[i-1][j];
                int cp = dp[i-1][j-1];
                dp[i][j] = min({ins, del, cp}) + 1;
            }
        }
    }
    cout << dp[s1.size()][s2.size()];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
