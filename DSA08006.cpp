// DSA08006 - SỐ 0 VÀ SỐ 9

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n;
    cin >> n;
    queue<string> q;
    q.push("9");
    while(stoll(q.front()) % n != 0){
        string top = q.front();
        q.pop();
        string a = top + "0";
        string b = top + "9";
        q.push(a);
        q.push(b);
    }
    cout << q.front();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
