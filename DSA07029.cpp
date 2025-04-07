// DSA07029 - GIẢI MÃ XÂU KÝ TỰ
// https://www.youtube.com/watch?v=qB0zZpBJlh8

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    stack<string> st;
    for(char x : s){
        if(x != ']'){
            st.push(string(1, x));
        }
        else{
            string substr = "";
            while(st.top() != "["){
                substr = st.top() + substr;
                st.pop();
            }
            st.pop();
            string k = "";
            while(!st.empty() && isdigit(st.top()[0])){
                k = st.top() + k;
                st.pop();
            }
            int n = -1;
            if(k != ""){
                n = stoi(k);
            }
            string expaned = (k == "" ? substr : "");
            for(int i = 0; i < n; i++){
                expaned += substr;
            }

            st.push(expaned);
        }
    }
    /*
        3[a]2[bc]
        -->
        | "aaa" |
        | "bcbc"|

    */
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
    cin.ignore();
    while(t--){
        solve();
        cout << endl;
    }
}
