// Dãy con tăng dài nhất

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& nums) {
        unordered_map<string, int> mem;
        return calc(n, nums, mem, 0, 0);
    }
private:
    int calc(int &n, vector<int> &nums, unordered_map<string, int> &mem, int pos, int prev_val){
        if(pos == n){
            return 0;
        }
        string key = to_string(pos) + " " + to_string(prev_val);
        if(mem.find(key) != mem.end())
            return mem[key];

        int skip = calc(n, nums, mem, pos + 1, prev_val);
        int pick = 0;
        if(nums[pos] > prev_val){
            pick = 1 + calc(n, nums, mem, pos + 1, nums[pos]);
        }
        mem[key] = max(skip, pick);
        return mem[key];
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.solve(n, nums) << endl;
    return 0;
}
