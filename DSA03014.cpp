// DSA03014 - SỐ KHỐI LẬP PHƯƠNG

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
string s;
bool found;
string path;
ull ans = 0;

ull cubicRoot(string str){
    ull n = stoull(str);
    ull low = 0, high = n;
    while(low <= high){
        ull mid = (low + high) / 2;
        if(mid * mid * mid == n)
            return mid;
        if(mid * mid * mid < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

void Try(int pos){
    if(path.size() && cubicRoot(path)){
        ull n = stoull(path);
        found = true;
        ans = max(ans, n);
    }
    for(int i = pos; i < s.size(); i++){
        path += s[i];
        Try(i+1);
        path.pop_back();
    }
}

void solve(){
    path.clear();
    ans = 0;
    found = false;
    cin >> s;

    Try(0);
    if(found)
        cout << ans;
    else
        cout << -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
