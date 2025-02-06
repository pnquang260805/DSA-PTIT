// Đặt tên 1

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> words;
vector<vector<string>> ans;
vector<string> process;


void init(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        if(find(words.begin(),words.end(),temp) == words.end()){
            words.push_back(temp);
        }
        sort(words.begin(), words.end());
    }
}

void BackTrack(int pos){
    if(process.size() == k){
        ans.push_back(process);
        return;
    }
    for(int i = pos; i < words.size(); i++){
        process.push_back(words[i]);
        BackTrack(i+1);
        process.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    BackTrack(0);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
