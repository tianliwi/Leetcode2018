#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    private:
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> recursive(string str) {
        vector<string> ans = {};
        if (str.length()==0) {
            return {""};
        }
        int idx = str[0]-'0';
        int n = map[idx].length();
        vector<string> child = recursive(str.substr(1));

        for(int i=0;i<n;i++) {
            string c = map[idx].substr(i,1);
            for(int j=0;j<child.size();j++) {
                // cout << c+child[j] << endl;
                ans.push_back(c+child[j]);
            }
        }
        return ans;
    }

    public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") {
            return {};
        }
        return recursive(digits);
    }
};

int main() {
    Solution s;
    vector<string> ans = s.letterCombinations("23");
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}