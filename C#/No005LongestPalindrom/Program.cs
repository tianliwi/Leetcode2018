using System;

namespace No005LongestPalindrom
{
    public class Solution {
        
        bool DPworker(string s, int i, int j) {
            if (i==j) {
                return true;
            } else if (j==i+1) {
                return s[i]==s[j];
            } else {
                return DPworker(s, i+1, j-1) && (s[i]==s[j]);
            }
        }
        public string LongestPalindrome(string s) {
            string ans = string.Empty;
            int longest = 0;
            int n = s.Length;
            for (int i=0;i<n;i++) {
                for (int j=i;j<n;j++) {
                    string sub = s.Substring(i,j-i+1);
                    if (DPworker(s,i,j)){
                        if (j-i+1>longest){
                            ans = sub;
                            longest = j-i+1;
                        }
                    }
                }
            }
            return ans;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            System.Console.WriteLine(s.LongestPalindrome("33dababadf324a"));
        }
    }
}
