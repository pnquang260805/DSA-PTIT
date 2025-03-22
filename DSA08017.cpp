// DSA08017 - SỐ LỘC PHÁT 1

#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<string> ans = {"6", "8"};
    queue<string> q;
    q.push("6");
    q.push("8");
    while(q.front().size() < n){
        string top = q.front();
        string a = top + "6";
        string b = top + "8";

        q.pop();
        q.push(a);
        q.push(b);
        ans.push_back(a);
        ans.push_back(b);
    }
    reverse(ans.begin(), ans.end());
    for(string s : ans)
        cout << s << " ";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
