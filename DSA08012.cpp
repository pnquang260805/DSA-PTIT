// DSA08012DSA08012 - TÌM SỐ K THỎA MÃN ĐIỀU KIỆN

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll n){
    string s = to_string(n);
    unordered_map<char, int> freq;
    for(char x : s){
        if(x > '5'){
            return false;
        }
        else{
            freq[x]++;
        }
    }
    for(char x : s){
        if(freq[x] > 1)
            return false;
    }
    return true;
}

void solve(){
    ll l, r;
    cin >> l >> r;
    int cnt = 0;
    for(ll i = l; i <= r; i++){
        if(check(i)){
            cnt++;
        }
    }
    cout << cnt;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}