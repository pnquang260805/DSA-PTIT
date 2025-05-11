// DSA05032 - XÂU ĐỐI XỨNG 1
// https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/#using-bottomup-dp-tabulation-on2-time-and-on2-space

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

typedef vector<vector<int>> vv;

int calc(int start, int end, string &s, vv &mem){
    if(start > end)
        return 0;
    if(mem[start][end] != -1)
        return mem[start][end];
    int res = 0;
    if(s[start] == s[end]){
        res = calc(start+1, end-1, s, mem);
    }
    else{
        // Thêm 1 phép chèn
        res = min(calc(start+1, end, s, mem), calc(start, end-1, s, mem)) + 1; 
    }
    mem[start][end] = res;
    return res;
}

void solve(){
    string s;
    cin >> s;
    vv mem(s.size(), vector<int>(s.size(), -1));
    cout << calc(0, s.size()-1, s, mem);
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}