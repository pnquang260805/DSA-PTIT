// DSA07010 - BIẾN ĐỐI TIỀN TỐ - HẬU TỐ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());
    stack<string> st;
    for(char x : s){
        if(x == ' ')
            continue;
        if(x != '*' && x != '+' && x != '-' && x !='/'){
            st.push(string(1, x));
        }
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = op1 + op2 + string(1, x);
            st.push(temp);
        }
    }
    cout << st.top();
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