
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
class Solution {
public:

    struct ListNodeBundle
    {
        ListNode* before;
        ListNode* me;

        inline void next()
        {
            before = me;
            me = me->next;
        }

    };

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        /*
        
        Given the head of a linked list, remove the nth node from the end of the list and return its head.

 
        Example 1:


        Input: head = [1,2,3,4,5], n = 2
        Output: [1,2,3,5]
        Example 2:

        Input: head = [1], n = 1
        Output: []
        Example 3:

        Input: head = [1,2], n = 1
        Output: [1]
        
        */

        if(head->next == nullptr)
            return nullptr;

        ListNodeBundle p1 = {nullptr, head};
        ListNodeBundle p2 = p1;

        for(int i = 1; i < n; i++)
            p2.next();

        while(p2.me->next != nullptr)
        {
            p1.next();
            p2.next();
        }

        if(p1.before == nullptr)
            return p1.me->next;

        p1.before->next = p1.me->next;

        return head; 

    }
};
