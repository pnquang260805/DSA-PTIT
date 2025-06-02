// DSA01009 - XÂU AB ĐẶC BIỆT
#include<bits/stdc++.h>
using namespace std;

int check(string s, int k){
    int l = 0, r = 0;
    int cnt = 0;
    while(r < (int)s.size()){
        if(s[r] == 'A' && s[l] == 'A'){
            r++;
        }
        else if(s[r] != 'A' && s[l] == 'A'){
            cnt = (r-l == k ? cnt+1 : cnt);
            l = r;
        }
        else{
            r++;
            l++;
        }
    }
    (r-l == k ? cnt++ : cnt);
    return cnt;
}

void solve(){
    int n, k;
    cin >> n >> k;
    set<string> ans;
    function<void(string)> Try = [&](string temp){
        if(temp.size() == n){
            if(check(temp, k) == 1){
                ans.insert(temp);
            }
            return;
        }
        Try(temp + "A");
        Try(temp + "B");
    };
    Try("");
    cout << ans.size() << endl;
    for(auto x : ans)
        cout << x << endl;

}

int main(){
    solve();
}
