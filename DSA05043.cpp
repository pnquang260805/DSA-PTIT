// SỐ THUẬN NGHỊCH

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        // Max len là lẻ
        int l = i-1, r = i+1;
        while(l >= 0 && r < n && s[r] == s[l]){
            r++;
            l--;
        }
        ans = max(ans, r - l - 1);

        // max len là chẵn
        l = i, r = i+1;
        while(l >= 0 && r < n && s[r] == s[l]){
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