#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> check(n,false);
        check[0] = true;
        for(int i=0;i<n;i++) {
            if(check[i]) {
                for(int j=0;j<nums[i];j++) {
                    check[i+j+1] = true;
                }
                if(check[n-1]) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> input = {3,2,1,0,4};
    cout << s.canJump(input) << endl;
}