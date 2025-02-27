#include <bits/stdc++.h>
// DSA01011 - HOÁN VỊ TIẾP THEO CỦA CHUỖI SỐ

using namespace std;

void solve(){
    int n;
    string temp;
    cin >> n >> temp;
    vector<int> s;
    for(char x : temp){
        s.push_back(x - '0');
    }
    int r = s.size() - 1;
    while(r > 0 && s[r] <= s[r-1]){
        r--;
    }
    if(r == 0){
        cout << n << " BIGGEST";
        return;
    }
    int l = r - 1;
    int r2 = s.size() - 1;
    while(s[l] >= s[r2])
        r2--;
    swap(s[l], s[r2]);
    r2 = s.size() - 1;
    cout << n << " ";
    reverse(s.begin() + r, s.end());
    for(auto x : s)
        cout << x;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}