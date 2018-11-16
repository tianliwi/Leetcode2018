class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0) return false;
        int n = matrix[0].size();
        if (n==0) return false;
        int left = 0;
        int right = m*n-1;
        while(left<=right) {
            int mid = left + (right-left)/2;
            int lv = matrix[left/n][left%n];
            int rv = matrix[right/n][right%n];
            int mv = matrix[mid/n][mid%n];
            // cout << lv << "," << rv <<"," << mv << endl;
            if (mv==target) return true;
            else if(mv<target) {
                left = mid + 1;
            } else right = mid-1;
        }
        return false;
    }
};