using System;

namespace No002
{
    public class ListNode{
        public int val;
        public ListNode next;
        public ListNode(int x) {val = x;}
    }

    public class Solution {
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
            int carry = 0;
            ListNode result = new ListNode(-1);
            ListNode head = result;
            while (l1!=null || l2!=null || carry >0) {
                int sum = (l1!=null?l1.val:0) + (l2!=null?l2.val:0) + carry;
                carry = (int)(sum/10);
                head.next = new ListNode(sum % 10);
                head = head.next;
                l1 = l1?.next;
                l2 = l2?.next;
            }
            return result.next;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var solution = new Solution();
            var l1 = new ListNode(2);
            l1.next = new ListNode(4);
            l1.next.next = new ListNode(3);

            var l2 = new ListNode(5);
            l2.next = new ListNode(6);
            l2.next.next= new ListNode(4);

            var result = solution.AddTwoNumbers(l1,l2);
            while (result!=null){
                System.Console.Write(result.val);
                result = result.next;
            }
        }
    }
}
