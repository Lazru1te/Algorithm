#include <bits/stdc++.h>
using namespace std;

#define int long long
const string solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x :a) cin >> x;
    bool turn = merge_sort(a, 0, n) % 2;
    return turn ? "Bob" : "Alice";
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}

int merge_sort(vector<int> &nums, int left, int right){
    if (left <= right) {
        int mid = (left +right) / 2;
        int res = 0;
        res += merge_sort(nums, left, mid);
        res += merge_sort(nums, mid, right);
        vector<int> tmp(right-left);
        int i = left, j = mid, k = 0;

        //合并两个有序数组
        while(i < mid && j <= right){
            if(nums[j] < nums[i]){//逆序对
                tmp[k] = nums[j++];
                res += mid - i; //统计逆序对
            } else{
                tmp[k] = nums[i++];
            }
            k++;
        }
        for(; i < mid; i++, k++) tmp[k] = nums[i];
        for(; j <= right; j++, k++) tmp[k] = nums[j];
        for(int p = 0; p < k; p++){
            nums[left + p] = tmp[p];
        }
        return res;
    }
    return 0;
}