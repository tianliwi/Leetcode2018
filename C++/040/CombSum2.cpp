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
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        recur(cur, candidates, target, used);
        return ans;
    }

    void recur(vector<int>& cur, vector<int>& cand, int remain, vector<bool>& used) {
        if (remain==0) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0;i<cand.size();i++) {
            if (used[i]) continue;
            int n = cand[i];
            if(!cur.empty() && cur.back()>n) continue;
            if(n <= remain) {
                cur.push_back(n);
                used[i] = true;
                recur(cur, cand, remain - n, used);
                cur.pop_back();
                used[i] = false;
                while(i+1<cand.size() && cand[i]==cand[i+1]) i++;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> cand = {10,1,2,7,6,1,5};
    vector<vector<int>> ans = s.combinationSum(cand, 8);
    for(vector<int> s : ans) {
        for(int i: s) {
            cout << i << ",";
        }
        cout << endl;
    }
}