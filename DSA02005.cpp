// Hoán vị xâu tự nhiên

#include <bits/stdc++.h>
using namespace std;

string inp_str;
string process;
unordered_map<char, bool> mem;

void init(){
    getline(cin, inp_str);
    process = "";
    for(char x : inp_str){
        mem[x] = false;
    }
}

void BackTrack(){
    if(process.size() == inp_str.size()){
        cout << process << " ";
        return;
    }

    for(int i = 0; i < inp_str.size(); i++){
        if(mem[inp_str[i]] == false){
            mem[inp_str[i]] = true;
            process += inp_str[i];
            BackTrack();
            mem[inp_str[i]] = false;
            process.pop_back();
        }
    }
}

void solve(){
    init();
    BackTrack();
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
