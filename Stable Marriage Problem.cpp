/*
    https://www.geeksforgeeks.org/stable-marriage-problem/
    Online judge: https://www.geeksforgeeks.org/problems/stable-marriage-problem/1
    Submit just class Solution

    Given n men and n women, where each person ranks all members of the opposite gender in order 
    of preference (men ranks women and women ranks men), the task is to marry the men and women 
    together such that no two persons of opposite gender prefers each other over their current partners. 

    In other words, the task is to pair each man with a woman such that

    Every man is paired with exactly one woman, and vice versa.
    The matching is stable, that is there is no pair  who would both prefer 
    to be matched with each other over their current partners.

    Note: It can be proven that it is always possible to form stable marriages. 
    The input contains two arrays, men[] and women[], such that men[i] 
    stores the preference list of ith man and women[i] stores the preference list of ith woman.

    You should return a list of integers, where the i-th element represents the index of 
    the woman that the i-th man is married to (0-based index). 
*/

/* Algorithm: 
    While number_of_single_man > 0:
        find fist single man (fsm)
        for i: 0->n-1:
            if woman ith of fsm has no partner:
                set partner for ith woman = fsm
                ans[fsm] = ith
                mark fsm is not single now
                decrease number of single man
                BREAK
            else:
                current partner: is man who ith woman has been marrying
                if ith woman fsm than her husband now : =)
                    set new partner for her = fsm
                    mark fsm is not single
                    ans[fsm] = ith woman
                    mark current partner is single
                    ans[current partner] = -1
                    BREAK
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men[0].size();
        map<int,int> mp;
        vector<int> partnerOfW(n, -1);
        vector<bool> mSingle(n, true);
        vector<int> ans(n);
        
        int noSingle = n;
        while(noSingle > 0){
            int freeMan = 0;
            // Find free man
            for(int i = 0; i < n; i++){
                if(mSingle[i]){
                    freeMan = i;
                    break;
                }
            }
            for(int i = 0; i < n; i++){
                int w = men[freeMan][i];
                if(partnerOfW[w] == -1){
                    partnerOfW[w] = freeMan;
                    ans[freeMan] = w;
                    mSingle[freeMan] = false;
                    noSingle--;
                    break; // Người đàn ông đã có bạn đời, dừng vòng lặp
                }
                else{
                    int currentPartner = partnerOfW[w];
                    if(wPreferM1thanM(women, w, freeMan, currentPartner)){
                        mSingle[currentPartner] = true;
                        mSingle[freeMan] = false;
                        ans[currentPartner] = -1;
                        ans[freeMan] = w;
                        partnerOfW[w] = freeMan;
                        break; // Người đàn ông đã có bạn đời, dừng vòng lặp
                    }
                }
            }
        }
        return ans;
    }
private:
    bool wPreferM1thanM(vector<vector<int>> &women, int w, int m1, int m){
        for(int i = 0; i < women.size(); i++){
            if(women[w][i] == m1)
                return true;
            else if(women[w][i] == m)
                return false;
        }
        return false;
    }
};

void solve(){
    Solution sol;
    int n;
    cin >> n;
    vector<vector<int>> men(n, vector<int>(n));
    vector<vector<int>> women(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> men[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> women[i][j];
    vector<int> ans = sol.stableMarriage(men, women);
    for(int x : ans)
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