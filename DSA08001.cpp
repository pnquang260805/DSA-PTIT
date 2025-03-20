// DSA08001 - CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 1

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    queue<int> q;
    while(n--){
        int x;
        cin >> x;
        switch(x){
        case(1):
            cout << q.size() << endl;
            break;
        case(2):
            cout << (q.empty() ? "YES" : "NO") << endl;
            break;
        case(3):
            int l;
            cin >> l;
            q.push(l);
            break;
        case(4):
            if(!q.empty())
                q.pop();
            break;
        case(5):
            cout << (q.empty() ? -1 : q.front()) << endl;
            break;
        case(6):
            cout << (q.empty() ? -1 : q.back()) << endl;
        }
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