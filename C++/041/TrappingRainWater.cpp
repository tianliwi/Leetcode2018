#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int left[n], right[n];

        int tmp = height[0];
        
        left[0] = 0;
        for(int i = 1; i < n; i++) {
            if(height[i-1]>tmp) {
                tmp = height[i-1];
            }
            left[i] = tmp;
        }

        cout << endl;
        tmp = height.back();
        right[n-1] = 0;
        for(int i = n-2; i >=0;i--) {
            if(height[i+1]>tmp) {
                tmp = height[i+1];
            }
            right[i-1] = tmp;
        }

        for(int i=0;i<n;i++) {
            ans += max(min(left[i],right[i]) - height[i], 0);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(input) << endl;
}