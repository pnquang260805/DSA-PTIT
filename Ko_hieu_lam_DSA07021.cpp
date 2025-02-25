// DÃY NGOẶC ĐÚNG DÀI NHẤT

#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int ans = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i); // Lưu vị trí của '('
        } else {
            st.pop(); // Loại bỏ phần tử trên cùng
            if (!st.empty()) {
                ans = max(ans, i - st.top()); // Cập nhật độ dài dãy ngoặc đúng
            } else {
                st.push(i); // Lưu vị trí ')' bị dư
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