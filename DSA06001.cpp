// SẮP XẾP XEN KẼ

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    sort(a.begin(),a.end(),greater<int>());
    int left = 0, right = n - 1;
    while(left <= right){
        if(left == right)
            cout << a[left];
        else
            cout << a[left] << " " << a[right] << " ";
        left++;
        right--;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
