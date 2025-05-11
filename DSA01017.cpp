// DSA01017 - MÃ GRAY 3
// https://www.geeksforgeeks.org/gray-to-binary-and-binary-to-gray-conversion/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef vector<vector<ll>> vv;

void solve(){
    string s;
    cin >> s;
    vector<int> v;
    for(char x : s){
        v.push_back(x - '0');
    }
    vector<int> ans(s.size());
    ans[0] = v[0];
    for(int i = 1; i < (int)s.size(); i++){
        ans[i] = v[i-1] ^ v[i];
    }
    for(int i : ans)
        cout << i;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}