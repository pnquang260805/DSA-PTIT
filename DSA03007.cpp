// DSA03007 - GIÁ TRỊ NHỎ NHẤT CỦA BIỂU THỨC

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

string mulBigInt(string a, string b){
    int n = a.size();
    int m = b.size();
    vector<int> res(m+n, 0);

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            int mul = (a[i] - '0') * (b[j] - '0');
            int carry = i + j;
            int val = i + j + 1;
            int sum = mul + res[val];
            res[carry] = sum / 10;
            res[val] = sum % 10;
        }
    }
    string ans = "";
    for (int num : res)
        if (!(ans.empty() && num == 0)) // Bỏ số 0 đầu tiên
            ans += to_string(num);

    return ans.empty() ? "0" : ans;
}

string sumBigInt(string a, string b){
    if (a.length() < b.length())
        swap(a, b);

    string res = "";
    int carry = 0;

    // Đảo ngược chuỗi để cộng từ phải sang trái
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < a.length(); i++) {
        int digitA = a[i] - '0';
        int digitB = (i < b.length()) ? (b[i] - '0') : 0;

        int sum = digitA + digitB + carry;
        res += (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) res += carry + '0';

    reverse(res.begin(), res.end());
    return res;
}

void solve(){
//    ull n;
//    cin >> n;
//    vector<string> a(n), b(n);
//    for(string &x : a)
//        cin >> x;
//    for(string &x : b)
//        cin >> x;
//    sort(a.begin(), a.end(), [](string x, string y){
//            if(x.size() == y.size())
//                return x > y;
//            return x.size() > y.size();
//    });
//    sort(b.begin(), b.end(), [](string x, string y){
//            if(x.size() == y.size())
//                return x < y;
//            return x.size() < y.size();
//    });
//    string res = "0";
//    for(int i = 0; i < n; i++){
//        res = sumBigInt(res, mulBigInt(a[i], b[i]));
//    }
//    cout << res;
    ull n;
    cin >> n;
    vector<ull> a(n), b(n);
    for(ull &i : a)
        cin >> i;
    for(ull &i : b)
        cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ull>());
    ull res = 0;
    for(int i = 0; i < n; i++){
        res += b[i] * a[i];
    }
    cout << res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
