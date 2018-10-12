#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int d = n/2;
        cout << d << endl;
        for(int i=0;i<d;i++) {
            for(int j=0;j<d;j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
        if(n%2==0) return;
        for(int i=0;i<d;i++) {
            int j = d;
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = tmp;
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> input = {
        {1,2},
        {5,6}
    };
    s.rotate(input);
    for(int i=0;i<input.size();i++) {
        for(int j=0;j<input.size();j++) {
            cout << input[i][j] << ",";
        }
        cout << endl;
    }
}