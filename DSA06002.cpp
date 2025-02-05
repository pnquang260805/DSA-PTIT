// SẮP XẾP THEO GIÁ TRỊ TUYỆT ĐỐI

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, X;
    cin >> n >> X;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    stable_sort(a.begin(),a.end(),[X](int l, int k){ // [X] cho phép hàm lambda sử dụng biến X (nhưng là bản coppy)
    // Khi làm bài tập về sắp xếp nếu đề bài có thêm yêu cầu trong trường hợp các phần tử trong mảng, danh sách có cùng giá
    // trị sắp xếp thì cần giữ nguyên thứ tự xuất hiện giữa các phần tử này thì khi đó bạn cần nghĩ ngay tới hàm stable_sort()
            return abs(X-l) < abs(X-k);
    });
    for(auto x : a)
        cout << x << " ";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
