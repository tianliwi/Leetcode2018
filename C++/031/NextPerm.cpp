#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return;
        int i=n-1;
        for(; i>=1; i--) {
            if(nums[i]>nums[i-1]){
                break;
            }
        }
        int swap = INT_MAX, swapInd = -1;
        for(int j=i;j<n;j++) {
            if(nums[j]>nums[i-1] && nums[j]<swap) {
                swap = nums[j];
                swapInd = j;
            }
        }
        //cout << i << swapInd;
        if(swapInd>0 && i>0) {
        int tmp = nums[i-1];
        nums[i-1] = swap;
        nums[swapInd] = tmp;
        }
        sort(nums.begin()+i, nums.end());
    }
};

int main() {
    Solution s;
}