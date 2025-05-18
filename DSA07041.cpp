// DSA07041 - BIỂU THỨC ĐÚNG DÀI NHẤT
// Tính tổng độ dài của các dãy con (không cần liên tiếp) thỏa mãn

#include <bits/stdc++.h>
using namespace std;

void clear_stack(stack<char> &st){
    while(!st.empty())
        st.pop();
}

void solve(){
    string s;
    cin >> s;
    int ans = 0;
    int cnt = 0;
    stack<char> st;
    for(char x : s){
        if(x == '('){
            st.push(x);
        }
        else{
            if(!st.empty()){
                if(st.top() == '('){
                    cnt+=2;
                    ans = max(ans, cnt);
                    st.pop();
                }
            }
        }
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