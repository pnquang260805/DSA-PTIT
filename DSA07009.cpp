// DSA07009 - BIẾN ĐỔI TIỀN TỐ - TRUNG TỐ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());
    stack<string> st;
    for(char x : s){
        if(x == ' ') continue;
        if(x != '+' && x != '-' && x != '*' && x != '/'){
            st.push(string(1, x));
        }
        else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = "(" + op1 + x + op2 + ")";
            st.push(temp);
        }
    }
    cout << st.top();
    /*
        *+AB-CD --> DC-AB+*
        char x:
            x = D --> stack = [D]
            x = C --> stack = [D, C]
            x = - --> stack = [(C-D)]
            x = B --> stack = [(C-D), B]
            x = A --> stack = [(C-D), B, A]
            x = + --> stack = [(C-D), (A-B)]
            x = * --> stack = [((A+B)*(C-D))]
    */
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