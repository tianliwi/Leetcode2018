#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());

        for(int i=0;i<n-2;i++) {
            int a = nums[i];
            int left = i+1, right = n-1;
            while(left < right) {
                int sum = a + nums[left] + nums[right];
                if(sum == target){
                    return target;
                }
                if (abs(sum-target)<abs(ans-target)) {
                    ans = sum;
                }
                if (sum<target) left ++;
                if (sum>target) right --;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> input = {-1, 2, 1, -4};
    cout << s.threeSumClosest(input,1) <<endl;
}