// DSA_P039 - CHỌN Ô 1

// Dynamic Programing With Bitmask
// https://viblo.asia/p/quy-hoach-dong-bitmask-Yym40r85L91

#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 20;
int dp[1 << maxn]; // dp[1 << max] = dp[2^20]

/*
    Biến mask là một bitmask dùng để lưu trạng thái lựa chọn các cột. 
    Cụ thể, trong bài toán, mỗi bit của mask đại diện cho một cột của ma trận. 
    Nếu bit thứ i được đặt là 1 (tức là mask & (1 << i) khác 0), 
    nghĩa là cột thứ i đã được chọn cho một hàng nào đó; nếu bit đó là 0, cột đó vẫn còn trống và có thể được chọn cho 
    hàng hiện tại. Qua đó, hàm đệ quy có thể biết được đang xét hàng nào dựa trên số lượng bit 1 trong mask 
    (tính bằng __builtin_popcount(mask)), từ đó duyệt và gán giá trị cho từng hàng một cách hợp lệ.

    Khi nào dùng Bitmask DP?

    Bitmask DP (Dynamic Programming với Bitmask) là một kỹ thuật hữu ích khi bài toán có nhiều lựa chọn có thể được biểu diễn bằng tập hợp và cần ghi nhớ trạng thái để tránh lặp lại tính toán.
    1. Điều kiện để dùng Bitmask DP

    Bạn có thể cân nhắc sử dụng Bitmask DP nếu bài toán thỏa mãn các điều kiện sau:

    ✅ Bài toán có nhiều lựa chọn (subset selection)

        Cần xử lý các tập hợp con, ví dụ như chọn một số phần tử từ một danh sách.
        Số lượng phần tử n thường nhỏ (n ≤ 20) do 2^n trạng thái vẫn có thể xử lý được.

    ✅ Cần lưu trạng thái của một tập hợp

        Một trạng thái có thể được biểu diễn bằng một dãy bit (mask), trong đó bit 1 thể hiện phần tử đã chọn, bit 0 là chưa chọn.
        Có thể tránh trùng lặp bằng cách lưu trạng thái vào mảng dp[mask].

    ✅ Bài toán có cấu trúc quy hoạch động

        Bài toán có thể được chia nhỏ thành các bài toán con nhỏ hơn.
        Kết quả của bài toán lớn có thể được xây dựng từ các bài toán con nhỏ hơn.
*/

int calc(int n, int mask, vector<vector<int>> &nums) {
    int row = __builtin_popcount(mask); // số hàng đã gán tương đương với số bit 1 trong mask
    if (row == n) return 0;             // nếu đã gán đủ N hàng thì tổng = 0 (không còn ô nào nữa)

    if(dp[mask] != -1)
        return dp[mask];

    int ans = 0;
    for (int col = 0; col < n; col++) {
        // kiểm tra bit (bit checking), giúp xác định xem bit thứ col trong mask có đang được bật (bằng 1) hay không.
        if (!(mask & (1 << col))){ 
            // Nếu cột col chưa được chọn, tiến hành gán ô ở hàng row, cột col
            /*
                Dùng toán tử OR (|) để "bật" bit thứ col của mask.
                Nếu bit thứ col ban đầu là 0, nó sẽ trở thành 1.
                Nếu bit thứ col đã là 1, nó vẫn giữ nguyên giá trị 1.
            */
            ans = max(ans, nums[row][col] + calc(n, mask | (1 << col), nums));
        }
    }
    return dp[mask] = ans;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> nums[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    calc(n, 0, nums);
    cout << dp[0] << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}