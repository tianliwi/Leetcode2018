#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int len = 0;
        ListNode *tmp = head;
        while(tmp->next) {
            len++;
            tmp = tmp->next;
        }
        len++;
        k = k % len;
        ListNode *newhead = head, *prev = NULL;
        if(k==0) return newhead;
        k = len - k;
        while(k-- > 0) {
            prev = newhead;
            newhead = newhead->next;
        }
        prev->next = NULL;
        tmp = newhead;
        while(tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = head;
        return newhead;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *res = s.rotateRight(head,2);

    while(res->next) {
        cout << res->val << "->";
        res = res->next;
    }
    cout <<"NULL"<< endl;
}