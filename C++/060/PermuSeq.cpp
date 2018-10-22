#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    public:
    string getPermutation(int n, int k) {
        string ans = "";
        int t[n];
        vector<string> rem;
        for(int i=0;i<n;i++) {
            rem.push_back(to_string(i+1));
        }
        for(int i=0;i<n;i++) {
            if(i==0){
                t[0] = 1;
            } else {
                t[i] = t[i-1] * (i);
            }
        }
        int m = n-1;
        while(k>0) {
            int ind = (k-1)/t[m];
            ans = ans + rem[ind];
            string tmp = rem.back();
            rem.back() = rem[ind];
            rem[ind] = tmp;
            rem.pop_back();
            sort(rem.begin(), rem.end());
            k = k % t[m--];
            cout << k << endl;
        }
        for(string c : rem) {
            ans = ans + c;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(3,2) << endl;
}