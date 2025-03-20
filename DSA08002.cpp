// DSA08002 - CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 2

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    queue<int> q;
    while(n--){
        string s;
        cin >> s;
        if(s == "PUSH"){
            int x;
            cin >> x;
            q.push(x);
        }
        else if(s == "PRINTFRONT"){
            cout << (q.empty() ? "NONE" : to_string(q.front())) << endl;
        }
        else if(s == "POP"){
            if(!q.empty())
                q.pop();
        }
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
        cout << endl;   
    }
}