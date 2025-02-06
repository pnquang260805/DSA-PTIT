// XÂU NHỊ PHÂN TRƯỚC

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int pointer = s.size() - 1;
    while(pointer >= 0 && s[pointer] == '0'){
        pointer--;
    }
    if(pointer < 0){
        for(int i = 0; i < s.size(); i++)
            cout << "1";
    }
    else{
        s[pointer] = '0';
        pointer++;
        while(pointer < s.size()){
            s[pointer] = '1';
            pointer++;
        }
        cout << s;
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
