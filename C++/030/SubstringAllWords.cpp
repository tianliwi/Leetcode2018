#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (s=="" || words.size()==0) {
            return ans;
        }
        unordered_map<string, int> count;
        for(string word : words) {
            count[word]++;
        }
        int n = s.length();
        int num = words.size();
        int len = words[0].length();
        for(int i=0; i<n-len*num+1; i++) {
            unordered_map<string, int> seen;
            int j=0;
            for(; j<num; j++) {
                string cur = s.substr(i+j*len, len);
                if (count.find(cur)!=count.end()){
                    seen[cur]++;
                    if(seen[cur]>count[cur]){
                        break;
                    }
                } else {
                    break;
                }
            }
            if(j==num) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> words = {"foo", "bar"};
    vector<int> ans = s.findSubstring("barfoothefoobarman", words);
    for(int i: ans){
        cout << i << endl;
    }
}