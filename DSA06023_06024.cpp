#include <bits/stdc++.h>
using namespace std;

void show(vector<int> nums, int i){
    cout << "Buoc " << i + 1 << ": ";
        for(int l : nums){
            cout << l << " ";
        }
        cout << endl;
}

void selectionSort(vector<int> nums){
    int n = nums.size();
    for(int i = 0; i < n - 1; i++){
        int idx = i, minn = nums[i];
        for(int j = i + 1; j < n; j++){
            if(nums[j] < minn){
                idx = j;
                minn = nums[j];
            }
        }
        swap(nums[i], nums[idx]);
        show(nums, i);
    }
}

void directSwappingSort(vector<int> nums){
    for(int i = 0; i < nums.size() - 1; i++){
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[j] < nums[i]){
                swap(nums[i], nums[j]);
            }
        }
        show(nums, i);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int &num : nums)
        cin >> num;
    selectionSort(nums);
}