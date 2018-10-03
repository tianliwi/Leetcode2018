using System;
using System.Collections.Generic;

namespace No006ZigzagConversion
{
    public class Solution {
        public string Convert(string s, int numRows) {
            if (numRows==1) return s;
            string ans = string.Empty;
            bool goingDown = true;
            int n = s.Length;
            string[] table = new string[Math.Min(numRows,n)];
            
            int curRow = 0;
            for (int i = 0;i < n;i++) {
                table[curRow] += s[i];
                curRow += goingDown?1:-1;
                if (curRow==table.Length-1) {
                    goingDown = false;
                } else if (curRow==0) {
                    goingDown = true;
                }
            }
            foreach(var str in table){
                ans += str;
            }
            return ans;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            System.Console.WriteLine(s.Convert("ab",1));
        }
    }
}
