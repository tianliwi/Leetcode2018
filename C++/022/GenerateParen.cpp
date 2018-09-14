#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<string> ans;
    void worker(string one, int left, int right) {
        if (left==0 && right==0) {
            ans.push_back(one);
            return;
        }
        if(left>0) worker(one+"(", left-1, right);
        if(right>left) worker(one+")", left, right-1);
    }
public:
    vector<string> generateParenthesis(int n) {
        
        worker("", n, n);
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    for(int i=0;i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
}