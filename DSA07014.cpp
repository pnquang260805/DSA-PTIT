// DSA07014 -TÍNH GIÁ TRỊ BIỂU THỨC TIỀN TỐ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    stack<int> st;
    reverse(s.begin(), s.end());
    for(char x : s){
        if(x != '+' && x != '-' && x != '*' && x != '/'){
            st.push(x - '0');
        }
        else{
            int num1 = st.top();
            st.pop();
            int num2 = st.top();
            st.pop();
            int num;
            if(x == '+')
                num = num1 + num2;
            else if(x == '-')
                num = num1 - num2;
            else if(x == '*')
                num = num1 * num2;
            else if(x == '/')
                num = num1 / num2;
            st.push(num);
        }
    }
    cout << st.top();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}