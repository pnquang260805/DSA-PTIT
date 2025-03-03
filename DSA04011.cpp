// DSA04011 - TÍCH HAI SỐ NHỊ PHÂN
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    ll n1 = stoll(s1, nullptr, 2); // (string, pointer, hệ cơ số)
    ll n2 = stoll(s2, nullptr, 2);
    cout << n1 * n2;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}