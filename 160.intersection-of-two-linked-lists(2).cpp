/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int numA=0;
        int numB=0;
        ListNode *p=headA;
        ListNode *q=headB;
        while (p)
        {
            p=p->next;
            numA++;
        }
         while (q)
        {
            q=q->next;
            numB++;
        }
        p=headA;
        q=headB;
        if(numA>numB){
            for (int i = 0; i < numA-numB; i++)
            {
                p=p->next;
            }
        }
        if(numA<numB){
            for (int i = 0; i < numB-numA; i++)
            {
                q=q->next;
            }
        }
        while (p!=q)
        {
            p=p->next;
            q=q->next;
        }
        return q;
    }
};
// @lc code=end

