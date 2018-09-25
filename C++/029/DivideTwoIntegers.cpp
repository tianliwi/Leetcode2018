#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        bool negative = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        int ans = 0;
        while (dvd>=dvs) {
            long temp = dvs, m = 1;
            while (dvd >= (temp<<1)) {
                temp <<= 1;
                m <<= 1;
            }
            ans += m;
            dvd -= temp;
        }
        if (negative) return -ans;
        else return ans;
    }
};

int main() {
    Solution s;
    cout << s.divide(10,3) << endl;
}