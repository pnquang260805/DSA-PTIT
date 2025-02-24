// HAHAHA

#include <bits/stdc++.h>
using namespace std;

int n;
string process;
vector<string> ans;
vector<string> candidates = {"A", "H"};

void init(){
    cin >> n;
    process = "";
    ans.clear();
}

void BackTrack(){
    if(process.size() == n){
        if(process[0] == 'H' && process[n-1] == 'A') // kiểm tra đầu tiên và cuối cùng
            cout << process << endl;
        return;
    }

    // Luôn thử thêm 'A' vào chuỗi trước (vì 'A' < 'H' theo thứ tự từ điển).
    process += "A";
    BackTrack();
    process.pop_back();

    if(process.empty() || process.back() != 'H'){
        process += "H";
        BackTrack();
        process.pop_back();
    }
}

void solve(){
    init();
    BackTrack();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        // cout << endl;
    }
}