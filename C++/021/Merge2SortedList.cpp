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
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode ans(0);
        ListNode *head = &ans;
        while(l1 && l2){
            if(l1->val > l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if (!l1) head->next = l2;
        else head->next = l1;
        return ans.next;
    }
};

int main()
{
    Solution s;
}