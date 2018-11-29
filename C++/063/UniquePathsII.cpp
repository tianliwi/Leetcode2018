#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (i==0 && j==0) continue;
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int left = 0, top = 0;
                if (i>0) {
                    left = dp[i-1][j];
                }
                if (j>0) {
                    top = dp[i][j-1];
                }
                dp[i][j] = left+top;
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution s;
    cout << s.uniquePathsWithObstacles(23,12) << endl;
}