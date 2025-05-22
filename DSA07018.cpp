// DSA07018 - TỔNG ĐA THỨC

#include <bits/stdc++.h>
using namespace std;

string nomalizer(string s){
    string res = "";
    for(char x : s){
        if(x != ' ')
            res += x;
    }
    return res;
}


int finder(string s, char c){
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == c){
            return i;
        }
    }
    return -1;
}

void solve(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    a = nomalizer(a);
    b = nomalizer(b);
    string word;
    map<int, int> mp;
    stringstream ss(a);
    while(getline(ss, word, '+')){
        int powIdx = finder(word, '^');
        int mulIdx = finder(word, '*');
        int value = stoi(word.substr(0, mulIdx));
        int key = stoi(word.substr(powIdx+1));
        mp[key] += value;
    }
    stringstream ss2(b);
    while(getline(ss2, word, '+')){
        int powIdx = finder(word, '^');
        int mulIdx = finder(word, '*');
        int value = stoi(word.substr(0, mulIdx));
        int key = stoi(word.substr(powIdx+1));
        mp[key] += value;
    }
    string ans = "";
    vector<pair<int,int>> v(mp.begin(), mp.end());
    for(int i = v.size()-1; i >= 0; i--){
        ans += to_string(v[i].second) + "*x^" + to_string(v[i].first);
        if(i != 0)
            ans += " + ";
    }
    cout << ans;
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        solve();
        cout << endl;
    }
}