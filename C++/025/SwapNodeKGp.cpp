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
    ListNode *reverse(ListNode *head) {
        ListNode *tmp
        while(head) {
            tmp = head->next;
            head->next = 

        }
    }
  public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *node = head;
        while(k--) {
            if (!node) return head;
            node = node->next;
        }
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

    while(ans){
        cout << ans->val << endl;
        ans = ans->next;
    }
}