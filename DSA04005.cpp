// DSA04005 - DÃY XÂU FIBONACCI

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
vector<ull> len(94);

void precalc(){
    len[1] = 1;
    len[2] = 1;
    for(int i = 3; i < 94; i++){
        len[i] = len[i-2] + len[i-1];
    }
}

/*
G(n) = G(n-2) + G(n-1), nghĩa là xâu G(n) được ghép từ G(n-2) đứng trước, rồi tới G(n-1) đứng sau.

Nếu k (vị trí cần tìm) nằm trong độ dài của G(n-2) → ký tự đó ở G(n-2) → ta gọi tiếp findChar(n-2, k).

Nếu k > len[n-2] (tức là vượt qua G(n-2)) → ký tự đó nằm trong G(n-1), nhưng:

    Vì G(n-2) đã chiếm hết len[n-2] ký tự ở trước rồi

    Vậy vị trí k trong G(n-1) sẽ phải là k - len[n-2].
*/

char findChar(int n, ull k){
    if(n == 1)
        return 'A';
    if(n == 2)
        return 'B';
    if(k <= len[n-2])
        return findChar(n-2, k);
    else
        return findChar(n-1, k - len[n-2]);
}

void solve(){
    int n;
    ull k;
    cin >> n >> k;
    cout << findChar(n, k);
}

int main(){
    precalc();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
}
