 #include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int l = nums.size();
        vector<bool> used(l, false);
        vector<int> cur;
        worker(ans, cur, nums, used);
        return ans;
    }
    void worker(
        vector<vector<int>>& ans, 
        vector<int>& cur,
        vector<int>& nums, 
        vector<bool>& used) 
        {
            if(cur.size()==nums.size()) {
                ans.push_back(cur);
                return;
            }
            for(int i=0;i<nums.size();i++) {
                if(used[i]) continue;
                cur.push_back(nums[i]);
                used[i] = true;
                worker(ans,cur,nums,used);
                cur.pop_back();
                used[i] = false;
                while(i<nums.size() && nums[i+1]==nums[i]) i++;
            }
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,3,0,3};
    vector<vector<int>> ans = s.permute(nums);
    for(vector<int> p : ans) {
        for(int k : p) {
            cout << k << ",";
        }
        cout << endl;
    }
}