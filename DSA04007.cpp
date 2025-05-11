// DSA04007 - HỆ CƠ SỐ K

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef vector<vector<ll>> vv;

string dec_to_k(ll k, ll n){
    string res = "";
    while(n != 0){
        res = to_string(n % k) + res;
        n /= k;
    }
    return res;
}

ll to_decimal(ll k, string s){
    ll res = 0;
    for(char c : s){
        res = (res * k) + (c - '0');
    }
    return res;
}

void solve(){
    // Chuyển về hệ thập phân rồi cộng. Cộng xong chuyển về hệ K
    ll k;
    string a, b;
    cin >> k >> a >> b;
    ll dec_a = to_decimal(k, a);
    ll dec_b = to_decimal(k, b);
    ll dec_res = dec_a + dec_b;
    cout << dec_to_k(k, dec_res);
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}