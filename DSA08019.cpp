// DSA08019 - SỐ LỘC PHÁT 3

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    queue<string> q;
    q.push("6");
    q.push("8");
    vector<string> ans = {"6", "8"};
    while(q.front().size() < n){
        string top = q.front();
        q.pop();
        string a = top + "6";
        string b = top + "8";
        q.push(a);
        q.push(b);
        ans.push_back(a);
        ans.push_back(b);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(string s : ans){
        cout << s << " ";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
