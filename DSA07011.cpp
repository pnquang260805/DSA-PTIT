// DSA07011 - BIẾN ĐỔI HẬU TỐ - TIỀN TỐ

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    string s;
    cin >> s;
    stack<string> st;
    for(char x : s){
        if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')){
            st.push(string(1, x));
        }
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push(string(1, x) + op2 + op1);
        }
    }
    string res = "";
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    cout << res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}