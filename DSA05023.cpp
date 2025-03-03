// DSA05023 - TỔNG CÁC XÂU CON

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    string s;
    cin >> s;
    ll ans = 0;
    for(int i = 0; i < s.size(); i++){
        string a = "";
        for(int j = i; j < s.size(); j++){
            a += s[j];
            ans += stoll(a);
        }
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