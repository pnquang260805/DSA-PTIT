// MUA LƯƠNG THỰC

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m, s;
    cin >> n >> s >> m;
    int total_food_needed = m * s;
    int buying_days = s - (s / 7); // Số ngày cửa hàng mở cửa (trừ Chủ Nhật)
    if (buying_days * n < total_food_needed) {
        cout << -1;
        return;
    }

    // Tìm số ngày tối thiểu phải mua để gom đủ thực phẩm
    int ans = ceil((float)total_food_needed / n);
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