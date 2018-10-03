#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    public:
    string countAndSay(int n) {
        string s = "1";
        for(int i=0;i<n-1;i++) {
            string t;
            char cur = 'x';
            int cnt = 0;
            for(int j=0;j<s.size();j++) {
                if(s[j]!=cur) {
                    if (cur!='x') {
                        t = t + to_string(cnt) + cur;
                    }
                    cur = s[j];
                    cnt = 1;
                } else cnt ++;
                if(j==s.size()-1) {
                    t = t + to_string(cnt) + cur;
                }
            }
            s = t;
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.countAndSay(3);
}