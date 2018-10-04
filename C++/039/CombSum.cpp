#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    private:
    vector<vector<int>> ans;
    public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        recur(cur, candidates, target);
        return ans;
    }

    void recur(vector<int>& cur, vector<int>& cand, int remain) {
        // for (int i : cur) {
        //     cout << i << ",";
        // }
        // cout << ":" << remain << endl;
        if (remain==0) {
            ans.push_back(cur);
            return;
        }
        for(int n : cand) {
            if(!cur.empty() && n < cur.back()) continue;
            if(n <= remain) {
                cur.push_back(n);
                recur(cur, cand, remain - n);
                cur.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> cand = {2,3,6,7};
    vector<vector<int>> ans = s.combinationSum(cand, 7);
    cout << ans.size() << endl;
}