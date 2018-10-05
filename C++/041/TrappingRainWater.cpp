#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    int trap(vector<int>& height) {
        stack<int> sta;
        int ans = 0;
        for(int i=0;i<height.size();i++) {
            int h = height[i];
            if (sta.empty() || height[sta.top()] >= h) {
                sta.push(i);
            } else {
                int prev=0;
                while(!sta.empty() && height[sta.top()]<h) {
                    prev = height[sta.top()];
                    // cout << prev << "-";
                    ans += (h - prev)*(i-sta.top());
                    sta.pop();
                }
                if(sta.empty()) {
                    ans -= *(h-prev);
                } 
                sta.push(h);
            }
            cout << ans << "\n" << endl;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> input = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(input) << endl;
}