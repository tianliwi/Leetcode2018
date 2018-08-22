using System;
using System.Collections.Generic;

namespace No003
{
    public class Solution {
        public int LengthOfLongestSubstring(string s) {
            HashSet<char> hash = new HashSet<char>();
            int i=0;
            int j=0;
            int ans = 0;
            int n = s.Length;
            while (i<n && j<n){
                if (!hash.Contains(s[j])){
                    hash.Add(s[j++]);
                    ans = Math.Max(ans, j-i);
                } else {
                    hash.Remove(s[i++]);
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
            Console.WriteLine(s.LengthOfLongestSubstring("abcabcbb"));
        }
    }
}
