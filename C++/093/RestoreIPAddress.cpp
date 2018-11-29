class Solution {
public:
    void recur(string cur, int k, string s, vector<string>& ans) {
        int len = s.length();
        if(k==4 && len==0) {
            ans.push_back(cur);
            return;
        }
        if(len>(4-k)*3) return;
        for(int i=1;i<=len;i++) {
            if(i>3) break;
            if(s[0]=='0' && i>1) break;
            string tmp = cur;
            string d = s.substr(0,i);
            if(stoi(d)>255) continue;
            cur += d;
            if(k<3) cur += ".";
            recur(cur, k+1, s.substr(i), ans);
            cur = tmp;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string cur = "";
        recur(cur,0,s,ans);
        return ans;
    }
};