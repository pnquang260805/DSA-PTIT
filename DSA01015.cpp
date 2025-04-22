// DSA01015 - TÌM BỘI SỐ

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll n;
    cin >> n;
    queue<string> q;
    q.push("9");
    while(!q.empty() && stoll(q.front()) % n != 0){
        string curr = q.front();
        q.pop();
        q.push(curr + "0");
        q.push(curr + "9");
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
