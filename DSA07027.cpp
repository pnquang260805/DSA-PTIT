// PHẦN TỬ BÊN PHẢI ĐẦU TIÊN LỚN HƠN

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int &num : nums){
        cin >> num;
    }
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= nums[i]){
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
    }
    for(int i : ans)
        cout << i << " ";
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