using System;

namespace Leetcodes
{
    public class N007ReverseInteger
    {
        public int Reverse(int x) {
            long ans = 0;
            while (x!=0) {
                int p = x % 10;
                x /= 10;
                ans = ans*10 + p;
                if (ans>Int32.MaxValue || ans<Int32.MinValue) return 0;
            }
            return (int)ans;
        }
        
    }
}