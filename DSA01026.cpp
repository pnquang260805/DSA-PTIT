// DSA01026 - PHÁT LỘC

#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> v = {"8", "6"};
vector<string> ans;

void Try(){
    if(s.size() == n){
        if(s[0] == '8' && s.back() == '6' && s.find("88") == -1 && s.find("6666") == -1){
            ans.push_back(s);
        }
        return;
    }
    for(int i = 0; i < 2; i++){
        s+=v[i];
        Try();
        s.pop_back();
    }
}

void solve(){
    s.clear();
    ans.clear();

    cin >> n;
    Try();
    sort(ans.begin(), ans.end(), [](string a, string b){
        if(a.size() == b.size())
            return a < b;
        return a.size() < b.size();
    });
    for(string b : ans)
        cout << b << endl;
}

int main(){
    int t=1;
//    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
