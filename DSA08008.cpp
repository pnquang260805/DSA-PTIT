// DSA08008 - SỐ BDN 2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");
    while(q.front().size() ){
        string top = q.front();
        q.pop();
        q.push(top + "0");
        q.push(top + "1");
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
