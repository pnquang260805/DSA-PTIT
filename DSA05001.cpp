// LCS
// https://www.youtube.com/watch?v=sSno9rV8Rhg

#include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b, int aIdx, int bIdx, vector<vector<int>> &mem){
    if(aIdx >= a.length() || bIdx >= b.length()){
        return 0;
    }
    if(mem[aIdx][bIdx] != -1){
        return mem[aIdx][bIdx];
    }

    // match
    if(a[aIdx] == b[bIdx])
        return mem[aIdx][bIdx] = 1 + lcs(a, b, aIdx+1, bIdx+1, mem);
    // not match
    return mem[aIdx][bIdx] = max(lcs(a, b, aIdx, bIdx+1, mem), lcs(a, b, aIdx+1, bIdx, mem));
}

void solve(){
    string a, b;
    cin >> a >> b;
    int m = a.length(), n = b.length();
    vector<vector<int>> mem(m+1, vector<int>(n+1, -1));
    cout << lcs(a, b, 0, 0, mem);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}