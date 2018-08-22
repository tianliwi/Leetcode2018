using System;

namespace No007ReverseInteger
{
    public class Solution {
        public int Reverse(int x) {
            int ans = 0;
            while (x!=0) {
                int p = x % 10;
                x /= 10;
                ans = ans*10 + p;
            }
            return ans;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            Console.WriteLine(s.Reverse(-123));
        }
    }
}
