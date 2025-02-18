// Đảo từ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    getline(cin ,s);
    stringstream ss(s);
    string word;
    stack<string> st;
    while(ss >> word){
        st.push(word);
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
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