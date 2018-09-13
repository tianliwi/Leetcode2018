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
    int romanToInt(string s) {
        
    }
};

int main() {
    Solution s;
    cout << s.romanToInt("CCXC") << endl;
}