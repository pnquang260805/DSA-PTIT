// DSA03012 - SẮP ĐẶT XÂU KÝ TỰ 1

#include <bits/stdc++.h>
using namespace std;

/*
Điều kiện đúng phải là: Không có ký tự nào xuất hiện nhiều hơn (n+1)/2 lần (với n là độ dài chuỗi).
Nếu có một ký tự xuất hiện quá nhiều thì dù sắp xếp thế nào cũng sẽ có hai ký tự giống nhau đứng cạnh nhau.
*/

void solve(){
    string s;
    cin >> s;

    int n = s.size();
    bool ans = true;

    map<char, int> mp;
    for(char x : s){
        mp[x]++;
        if(mp[x] > (n+1)/2){
            ans = false;
            break;
        }
    }
    cout << (ans ? 1 : -1);
}

int main(){
    int t=1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
