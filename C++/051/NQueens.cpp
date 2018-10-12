#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    private:
        vector<string> cur;
    public:
    vector<vector<string>> solveNQueens(int n) {
        string e(n,'.');
        vector<vector<string>> ans;
        vector<bool> colUsed(n,false);
        vector<bool> dig1Used(2*n-1,false);
        vector<bool> dig2Used(2*n-1,false);
        for(int i=0;i<n;i++) cur.push_back(e);
        run(n,0,ans,colUsed,dig1Used,dig2Used);
        return ans;
    }

    void run(
        int n,
        int row,
        vector<vector<string>>& ans,
        vector<bool>& cu,
        vector<bool>& du1,
        vector<bool>& du2
    ) {
        if(row==n) {
            ans.push_back(cur);
        }
        for(int col = 0;col<n;col++) {
            if(cu[col]) continue;
            if(du1[n-1+row-col]) continue;
            if(du2[row+col]) continue;
            cur[row][col] = 'Q';
            cu[col] = true;
            du1[n-1+row-col] = true;
            du2[row+col] = true;
            run(n,row+1,ans,cu,du1,du2);
            cur[row][col] = '.';
            cu[col] = false;
            du1[n-1+row-col] = false;
            du2[row+col] = false;
        }
    }
};

int main() {
    Solution s;
    vector<vector<string>> res = s.solveNQueens(4);
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }
}