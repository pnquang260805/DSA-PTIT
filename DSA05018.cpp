// DSA05018 - XÂU CON ĐỐI XỨNG DÀI NHẤT

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    int ans = 0;

    for(int i = 0; i < s.size(); i++){
        // Odd
        int l = i - 1, r = i + 1;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            r++;
            l--;
        }
        ans = max(ans, r - l - 1);

        // Even
        l = i, r = i + 1;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            r++;
            l--;
        }
        ans = max(ans, r - l - 1);
    }
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