#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = {};
        if (n<3) return ans;
        for (int i=0;i<n-2;i++) {
            int a = nums[i];
            if (i>0 && nums[i-1]==a) continue;
            int left = i+1, right = n-1;
            while (left<right) {
                int b = nums[left];
                int c = nums[right];
                int sum = a+b+c;
                if (sum == 0) {
                    ans.push_back({a,b,c});
                    while (left<right && nums[left]==b) left++;
                    while (left<right && nums[right]==c) right--;
                } else if (sum<0) {
                    left ++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = s.threeSum(input);
    for(int i=0;i<ans.size(); i++) {
        cout << ans[i][0] << "," << ans[i][1]<< "," << ans[i][2] << endl;
    }
}