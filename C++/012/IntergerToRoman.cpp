#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> map = {
        {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, //1-9
        {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, //10-90
        {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, //100-900
        {"M", "MM", "MMM"}
    };

public:
    string intToRoman(int num) {
        if (num>=4000 || num <0) return "";
        if (num==0) return "0";
        string ans = "";
        int digit = 0;
        while(num>0) {
            int tail = num % 10;
            num /= 10;
            if (tail>0) ans = map[digit][tail-1] + ans;
            digit ++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(290) << endl;
}