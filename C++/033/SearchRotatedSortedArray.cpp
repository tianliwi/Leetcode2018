#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (right<0) return -1;
        while(left<=right) {
            int mid = (left+right)/2;
            cout << mid << "," << left << right << endl;
            if (nums[mid]== target) return mid;
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid -1;
                } else {
                    left = mid + 1;
                }
            }
            if (nums[mid] <= nums[right]) {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid -1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> input{4,5,6,7,0,1,2};
    cout << s.search(input, 0) << endl;
}