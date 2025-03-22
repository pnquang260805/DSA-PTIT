// DSA08005 - SỐ NHỊ PHÂN TỪ 1 ĐẾN N

#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void init(){
    queue<string> q;
    q.push("1");
    res.push_back("1");
    while(res.size() <= 10000){
        string top = q.front();
        q.pop();
        string a = top + "0";
        string b = top + "1";
        q.push(a);
        q.push(b);
        res.push_back(a);
        res.push_back(b);
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}

int main(){
    int t;
    cin >> t;
    init();
    while(t--){
        solve();
        cout << endl;
    }
}
