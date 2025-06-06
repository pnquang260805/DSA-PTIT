// DSA02031 - GHÉP CHỮ CÁI

#include <bits/stdc++.h>
using namespace std;

char x;
int n;
vector<bool> visited;

bool check(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A' || s[i] == 'E'){
            if(i != 0 && i != s.size()-1 && (s[i-1] != 'A' && s[i-1] != 'E') && (s[i+1] != 'A' && s[i+1] != 'E'))
                return false;
        }
    }
    return true;
}

void backtrack(string temp){
    if(temp.size() == n){
        if(check(temp)){
            cout << temp << endl;
        }
        return;
    }
    for(char i = 'A'; i <= x; i++){
        if(!visited[i-'A']){
            visited[i-'A'] = true;
            backtrack(temp + i);
            visited[i-'A'] = false;
        }
    }
}

int main(){
    cin >> x;
    n = x-'A'+1;
    visited.assign(x, false);
    backtrack("");
}
