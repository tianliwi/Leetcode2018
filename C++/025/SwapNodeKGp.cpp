#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    private:
    ListNode *reverse(ListNode *head, ListNode *tail) {
        ListNode *cur = head, *next = NULL, *prev = tail;
        tail = head;
        while(cur!=prev) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return head;
    }
  public:
    void display(ListNode *head) {
        ListNode *ans = head;
        while(ans){
        cout << ans->val << endl;
        ans = ans->next;
    }}


    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *node = head;
        while(k--) {
            if (!node) return head;
            node = node->next;
        }
        ListNode *next = node->next;
        ListNode *tmp = reverse(head, node);
        display(tmp);
        node->next = reverseKGroup(next, k);
        return tmp;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *ans = s.reverseKGroup(head, 2);

    s.display(ans);
}