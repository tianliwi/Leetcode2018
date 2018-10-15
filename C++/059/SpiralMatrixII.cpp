#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        if(n==0) return ans;
        int rowStart = 0;
        int rowEnd = n-1;
        int colStart = 0;
        int colEnd = n-1;
        int cur = 1;
        while(rowStart<=rowEnd && colStart<=colEnd) {
            for(int i=colStart;i<=colEnd;i++) {
                ans[rowStart][i] = cur++;
            }
            rowStart ++;
            for(int i=rowStart;i<=rowEnd;i++) {
                ans[i][colEnd] = cur++;
            }
            colEnd --;
            for(int i=colEnd;i>=colStart;i--) {
                if(rowStart<=rowEnd)
                    ans[rowEnd][i] = cur++;
            }
            rowEnd --;
            for(int i=rowEnd;i>=rowStart;i--) {
                if(colStart<=colEnd) {
                    ans[i][colStart] = cur++;
                }
            }
            colStart++;
        }
        return ans;
    }
};

int main() {
    Solution s;
}