#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
    public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        stack<pair<char,int>> sta;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if (sta.empty()) {
                sta.push(make_pair(c,i));
            } else if (c=='(') {
                sta.push(make_pair(c, i));
            } else {
                pair<char, int> b = sta.top();
                if(b.first=='(') {
                    sta.pop();
                } else {
                    sta.push(make_pair(c,i));
                }
            }
        }
        if (sta.size()==0) {
            return s.size();
        }
        sta.push(make_pair('e',s.size()));
        int ans = 0;
        if (sta.size()==1) {
            return s.size()-1;
        }
        int prev = sta.top().second;
        sta.pop();
        while(!sta.empty()) {
            int cur = sta.top().second;
            // cout << cur << "," << prev << endl;
            sta.pop();
            if(prev-cur-1 > ans) {
                ans = prev-cur-1;
            }
            prev = cur;
        }
        if (prev > ans) {
            ans = prev;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses("())");
}