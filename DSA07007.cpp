// DSA07007 - SO SÁNH BIỂU THỨC

#include <bits/stdc++.h>
using namespace std;

string rep(string a){
    for(int i = 0; i < (int)a.size(); i++){
        if(a[i] == '+')
            a[i] = '-';
        else if(a[i] == '-')
            a[i] = '+';
    }
    return a;
}

string convert(string s){
    stack<string> st;
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] != '('){
            st.push(string(1, s[i]));
        }
        else{
            string temp = "";
            while(!st.empty() && st.top() != ")"){
                temp += st.top();
                st.pop();
            }
            st.pop();
            if(i-1 >= 0 && s[i-1] == '-'){
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
    return ans;
}

void solve(){
    string s, target;
    cin >> s >> target;
    
    cout << (convert(s) == convert(target) ? "YES" : "NO");
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}