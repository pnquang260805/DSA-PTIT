// SẮP XẾP CHỮ SỐ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    set<int> se;
    for(char x : s){
        if(x != ' '){
            se.insert(x - '0');
        }
    }
    for(auto it = se.begin(); it != se.end(); it++){
        cout << *it << " ";
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