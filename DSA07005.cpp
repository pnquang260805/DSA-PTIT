// DSA07005 - BIỂU THỨC TƯƠNG ĐƯƠNG

#include <bits/stdc++.h>
using namespace std;

string rep(string s){
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '-'){
            s[i] = '+';
        }
        else if(s[i] == '+'){
            s[i] = '-';
        }
    }
    return s;
}

void solve(){
    string s;
    cin >> s;
    stack<string> st;
    for(int i = s.size()-1; i >= 0; i--){
        char c = s[i];
        if(c != '('){
            st.push(string(1, c));
        }
        else{
            string temp = "";
            while(!st.empty() && st.top() != ")"){
                temp += st.top();
                st.pop();
            }
            st.pop();
            if(i-1>=0 && s[i-1] == '-'){
                temp = rep(temp);
            }
            st.push(temp);
        }
    }
    string ans = "";
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout << ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}