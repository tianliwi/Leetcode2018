#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n==0) return "";
        if (n==1) return strs[0];
        int curPos = 0;
        string ans = "";
        bool finished = false;
        while(!finished) {
            char currentLetter = strs[0][curPos];
            bool violate = false;
            for(int i=1; i<n;i++) {
                if (strs[i][curPos]!=currentLetter) {
                    violate = true;
                }
            }
            if (violate) {
                finished = true;
            } else {
                ans = ans + currentLetter;
            }
            curPos++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> input = {"floria", "flower", "fly"};
    cout << s.longestCommonPrefix(input) << endl;
}