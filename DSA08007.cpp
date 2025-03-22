// DSA08007 - SỐ BDN 1

#include <bits/stdc++.h>
using namespace std;

bool cdt(string a, string b){
    if(a.size() == b.size())
        return a <= b;
    return a.size() < b.size();
}

void solve(){
    string n;
    cin >> n;
    queue<string> q;
    q.push("1");
    int res = 0;
    while(!q.empty()){
        string top = q.front();
        q.pop();
        res++;
        string a = top + "0";
        string b = top + "1";
        if(!cdt(a, n))
            break;
        q.push(a);

        if(!cdt(b, n))
            break;
        q.push(b);
    }
    cout << res + q.size();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
