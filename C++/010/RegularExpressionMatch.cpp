#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool isMatch_Recur(string s, string p)
    {
        if (p.empty())
        {
            return s.empty();
        }
        bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
        if (p.length() > 1 && p[1] == '*')
        {
            return (isMatch_Recur(s, p.substr(2)) || (first_match && isMatch_Recur(s.substr(1), p)));
        }
        else
        {
            return first_match && isMatch_Recur(s.substr(1), p.substr(1));
        }
    }

    bool isMatch_DP(string s, string p)
    {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        for (int i=0;i<=m;i++) {
            for (int j=0;j<=n;j++) {
                cout <<  dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    cout << s.isMatch_DP("aa", ".*") << endl;
}