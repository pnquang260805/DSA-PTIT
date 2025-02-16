// SẮP XẾP DÃY CON LIÊN TỤC

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> B = A; // Sao chép mảng A để sắp xếp
    sort(B.begin(), B.end());

    int L = 0, R = n - 1;

    // Tìm vị trí L (đầu tiên khác nhau)
    while (L < n && A[L] == B[L]) L++;

    // Tìm vị trí R (cuối cùng khác nhau)
    while (R >= 0 && A[R] == B[R]) R--;

    if (L >= R) {
        cout << "-1 -1"; // Nếu mảng đã sắp xếp sẵn
    } else {
        cout << L + 1 << " " << R + 1; // Đổi sang chỉ số bắt đầu từ 1
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
}
