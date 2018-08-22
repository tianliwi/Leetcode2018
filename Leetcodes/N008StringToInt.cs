using System;

namespace Leetcodes
{
    public class N008StringToInt
    {        
        public int MyAtoi(string str) {
            long ans = 0;
            int sign = 0;
            foreach(char c in str){
                if (c=='+' && sign == 0){
                    sign = 1;
                } else if (c=='-' && sign == 0) {
                    sign = -1;
                } else if (c>='0' && c<='9') {
                    ans = ans*10 + (int)(c-'0');
                    if (sign==0) {
                        sign = 1;
                    }
                    if (ans*sign>Int32.MaxValue) {
                        return Int32.MaxValue;
                    } else if (ans*sign < Int32.MinValue) {
                        return Int32.MinValue;
                    }
                } else if (c==' ' && sign == 0) {
                    continue;
                } else {
                    break;
                }
            }
            return (int)ans*sign;
        }

        public void run() {
            System.Console.WriteLine(MyAtoi("sd  -123"));
        }
    }
}