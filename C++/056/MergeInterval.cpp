#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
    int static comp(Interval t1, Interval t2) {
        int res = (t2.start>t1.start);
        return res;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        
    }
};

int main() {
    Solution s;
}