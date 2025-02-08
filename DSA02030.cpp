// LIỆT KÊ XÂU KÝ TỰ

#include <bits/stdc++.h>
using namespace std;

const int A = int('A');

int n, k;
string ans;

void BackTrack(int pos){
    if(ans.size() == k){
        cout << ans << endl;
        return;
    }
    for(int i = pos; i < n; i++){
        ans += char(i + 'A');
        BackTrack(i);
        ans.pop_back();
    }
}

int main(){
    char temp;
    cin >> temp >> k;
    n = temp - 'A' + 1;
    BackTrack(0);
}
