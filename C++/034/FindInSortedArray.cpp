#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        int left = 0;
        int right = nums.size() - 1;
        while(left<=right) {
            int mid = left + (right-left)/2;
            cout << left << mid << right << endl;
            if (nums[mid]<target) left = mid + 1;
            else if (nums[mid]>=target) right = mid - 1;
        }
        if (left > nums.size()-1) ans.push_back(-1); 
        else {
            if(nums[left]==target) ans.push_back(left);
            else ans.push_back(-1);
        }

        left = 0;
        right = nums.size() - 1;
        while(left<=right) {
            int mid = left + (right-left)/2;
            cout << left << mid << right << endl;
            if (nums[mid]<=target) left = mid + 1;
            else if (nums[mid]>target) right = mid - 1;
        }
        if (right<0) ans.push_back(-1); 
        else {
            if(nums[right]==target) ans.push_back(right);
            else ans.push_back(-1);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> input = {5,7,7,8,8,10};
    vector<int> ans = s.searchRange(input, 6);
    for(int a:ans) {
        cout << a << endl;
    }
}