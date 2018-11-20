#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    
    void recursive(vector<int>& cur, int n, int k, vector<bool>& map) {        
        if(cur.size()==k) {
            res.push_back(cur);
            return;
        }
        for(int i=1;i<=n;i++) {
            if((cur.empty() || i > cur.back()) && !map[i - 1]){
                cur.push_back(i);
                map[i-1] = true;
                recursive(cur, n,k,map);
                map[i-1] = false;
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        vector<bool> map(n, false);
        recursive(cur,n,k,map);
        return res;
    }
};

int main() {
    Solution s;
    s.combine(4,2);
}