using System;

namespace Leetcodes
{
    public class N009ParlinInteger{
        public bool IsPalindrome(int x) {
            if (x<0) return false;

            int temp = x;
            int rev = 0;
            while (x>0) {
                rev = rev*10 + x % 10;
                x /= 10;
            }
            return temp == rev;
        }

        public void run() {
            System.Console.WriteLine(IsPalindrome(10));
        }
    }
}