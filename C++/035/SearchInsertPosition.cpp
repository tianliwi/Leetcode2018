#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l<=r) {
            int m = l+(r-l)/2;
            if(nums[m]<target) l=m+1;
            else if(nums[m]>=target) r = m-1;
        }
        
        return l;
    }
};

int main() {
    Solution s;
}