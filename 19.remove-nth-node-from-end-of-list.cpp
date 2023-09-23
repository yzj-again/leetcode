/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *left = dummyHead, *right = dummyHead;
        n++; // 如果n>链表长度，则多走一步会报错
        while (n-- && left != NULL)
        {
            left = left->next;
        }
        // left = left->next; // 多走一步
        while (left != NULL)
        {
            left = left->next;
            right = right->next;
        }
        ListNode *tmp = right->next;
        right->next = right->next->next;
        delete tmp;
        return dummyHead->next;
    }
};
// @lc code=end
