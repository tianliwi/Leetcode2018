#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1, ans = -1;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            ans = max(ans, area);
            if (height[left] > height[right]) right--;
            else left++;

        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> input = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(input) << endl;
}