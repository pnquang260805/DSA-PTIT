// Dãy con có tổng bằng S
// Dùng mảng 2 chiều int tốc độ sẽ nhanh hơn dùng unordered_map 
// --> Nếu dùng mảng 2 chiều cần cho -1 là giá trị chưa xét, 0 là ko có kết quả và sử dụng lại, 1 là có kết quả và sử dụng lại

#include <bits/stdc++.h>
using namespace std;

bool calc(int n, int s,  vector<int> &nums,vector<vector<int>> &mem, int pos, int total){
    if(total == s){
        return 1;
    }

    if(pos >= n || total > s){
        return 0;
    }


    if(mem[pos][total] != -1){
        return mem[pos][total];
    }
    int current = nums[pos];
    bool skip = calc(n,s,nums,mem,pos+1,total);
    bool pick = calc(n,s,nums,mem,pos+1,total+current);
    mem[pos][total] = skip || pick;
    return mem[pos][total];
}

void solve(){
    int n, s;
    cin >> n >> s;
    vector<int> nums(n);
    vector<vector<int>> mem;
    mem.assign(n+1, vector<int>(s+1,-1)); // -1 biểu thị trạng thái chưa xét, 0 là trạng thái ko tìm ra kết quả, 1 là tìm ra kết quả
    /*
        Việc thay giá trị khởi tạo từ -1 thành 0 trong mảng mem khiến chương trình chạy chậm hơn do ảnh hưởng đến cơ chế memoization (lưu trữ kết quả trung gian) trong hàm calc.
        Khi khởi tạo mem với toàn bộ giá trị 0, chương trình không thể phân biệt được đâu là trạng thái đã tính toán và đâu là trạng thái chưa tính.
        Điều này dẫn đến việc hàm calc không sử dụng lại các kết quả đã tính toán trước đó, buộc phải thực hiện lại các phép đệ quy dư thừa, làm tăng thời gian chạy.

        Giả sử bạn có trạng thái mem[2][5] chưa được tính toán:
        Với -1, chương trình biết đây là trạng thái mới, cần tính toán.
        Với 0, chương trình hiểu nhầm rằng đây là trạng thái đã tính và kết quả là false, dù thực tế chưa kiểm tra gì cả.
    */
    for(int &x : nums)
        cin >> x;
    bool ans = calc(n,s,nums,mem,0,0);
    if(ans){
        cout << "YES";
    }
    else
        cout << "NO";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
