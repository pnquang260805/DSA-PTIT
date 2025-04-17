// DSA02045 - TẬP CON CỦA XÂU KÝ TỰ

#include <bits/stdc++.h>
using namespace std;

void BackTrack(int pos, string s, int &n, vector<string> &v, vector<string> &ans, set<string> &appeared){
    if(s.size() <= n&& s.size() > 0 && (appeared.find(s) == appeared.end())){
//        appeared.insert(s);
        ans.push_back(s);
    }
    for(int i = pos; i < n; i++){
        s += v[i];
        BackTrack(i+1, s, n, v, ans, appeared);
        s.pop_back();
    }
}

void solve(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        char x;
        cin >> x;
        v[i] = x;
    }
    sort(v.begin(), v.end());
    set<string> appeared;
    vector<string> ans;
    BackTrack(0, "", n, v, ans, appeared);
    for(string x : ans)
        cout << x << " ";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
