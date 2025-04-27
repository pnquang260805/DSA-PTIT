// DSA05033 - XÂU ĐỐI XỨNG 2

#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(int start, int end, string s, vector<vector<int>> &mem){
    if(start > end)
        return 0;
    if(start == end)
        return 1;
    if(mem[start][end] != -1)
        return mem[start][end];
    mem[start][end] = 0;
    if(s[start] == s[end]){
        mem[start][end] = 2 + longestPalindrome(start+1, end-1, s, mem);
    }
    else{
        mem[start][end] = max(longestPalindrome(start+1, end, s, mem), longestPalindrome(start, end-1, s, mem));
    }
    return mem[start][end];
}

void solve(){
    string s;
    cin >> s;
    vector<vector<int>> mem(s.size(), vector<int>(s.size(), -1)); // start - end;
    int lp = longestPalindrome(0, s.size()-1, s, mem);
    cout << s.size() - lp;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
