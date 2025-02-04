// Thuật toán sinh

#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
int n;

void gen(int l) {
    for (int i = 0; i < 2; i++) {
        ans.push_back(i);
        if (ans.size() == n) {
            if (n % 2 != 0) {
                for (int num : ans) cout << num << " ";
                for (int j = n - 2; j >= 0; j--) cout << ans[j] << " ";
            } else {
                for (int num : ans) cout << num << " ";
                for (int j = n - 1; j >= 0; j--) cout << ans[j] << " ";
            }
            cout << "\n";
        } else {
            gen(l + 1);
        }
        ans.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    n = (t % 2 == 0) ? t / 2 : t / 2 + 1;
    gen(1);
    return 0;
}
