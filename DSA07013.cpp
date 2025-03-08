// DSA07013 - TÍNH GIÁ TRỊ BIỂU THỨC HẬU TỐ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    getline(cin, s);
    stack<int> st;
    for(char x : s){
        if(x == ' ')
            continue;
        if(x == '+' || x == '-' || x == '*' || x == '/'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int temp;
            if (x == '+') temp = b + a;
            else if (x == '-') temp = b - a;
            else if (x == '*') temp = b * a;
            else if (x == '/') {
                temp = b / a;
            }
            st.push(temp);
        }
        else{
            st.push(x - '0');
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