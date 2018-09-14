#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
    public:
    bool isValid(string s) {
        stack<char> paren;
        int n = s.length();
        for(int i=0; i<n; i++) {
            char cur = s[i];
            if (cur=='(' || cur=='[' || cur=='{' || paren.empty()){
                paren.push(cur);
            } else {
                char top = paren.top();
                if ((cur==')' && top=='(') || (cur==']' && top=='[') || (cur=='}' && top=='{')) {
                    paren.pop();
                } else {
                    return false;
                }
            }
        }
        return paren.empty();
    }
};

int main() {
    Solution s;
    cout << s.isValid("]");
}