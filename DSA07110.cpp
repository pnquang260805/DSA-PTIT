// KIỂM TRA DÃY NGOẶC ĐÚNG

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string n;
    cin >> n;
    stack<char> st;
    for(auto x : n){
        if(x == '[' || x == '(' || x == '{'){
            st.push(x);
        }
        else if(x == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                cout << "NO";
                return;
            }
        }
        else if(x == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                cout << "NO";
                return;
            }
        }
        else if(x == ']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
            }
            else{
                cout << "NO";
                return;
            }
        }
    }
    if(st.empty())
        cout << "YES";
    else
        cout << "NO";
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