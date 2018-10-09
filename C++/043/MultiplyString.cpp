#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    public:
    string multiply(string num1, string num2) {
        string ans="";
        int l1 = num1.size();
        int l2 = num2.size();
        string trail = "";
        for(int i = l2 - 1; i >= 0; i--) {
            int multiplier = num2[i] - (int)'0';
            string r = "";
            int carry = 0;
            for(int j = l1 - 1; j >= 0; j--) {
                int cur = num1[j] - '0';
                cur = cur * multiplier + carry;
                r = to_string(cur % 10) + r;
                carry = cur / 10;
            }
            if (carry>0) {
                r = to_string(carry) + r;
            }
            r = r + trail;
            trail = trail + "0";
            ans = add(ans,r);
        }
        return ans;
    }

    string add(string a, string b) {
        int carry = 0;
        string ans = "";
        int l1 = a.size()-1;
        int l2 = b.size()-1;
        while(l1 >= 0 || l2 >= 0) {
            int c1=0, c2=0;
            if(l1>=0) {
                c1 = a[l1--] - '0';
            }
            if(l2>=0) {
                c2 = b[l2--] - '0';
            }
            int s = c1 + c2 + carry;
            ans = to_string(s % 10) + ans;
            carry = s / 10;
        }
        if (carry>0){
            ans = to_string(carry) + ans;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.multiply("123", "456") << endl;
}