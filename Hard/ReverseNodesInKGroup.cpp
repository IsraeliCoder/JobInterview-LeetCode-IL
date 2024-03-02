
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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

    ListNode* doesListEndInKStep(ListNode* head, int k)
    {

        for(int i = 1; i < k; i++)
        {   
            if(!head)
                break;
            head = head->next;
        }

        if(head)
            return head;

        return nullptr;

    }

    void reverseList(ListNode* head, int k)
    {

        ListNode* prev = nullptr;
        ListNode* runner = head;

        for(int i = 0 ; i < k; i++)
        {
            
            ListNode* next = runner->next;
            runner->next = prev;
            prev = runner;
            runner = next;

        }

    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        /*
        Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

        k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

        You may not alter the values in the list's nodes, only nodes themselves may be changed.

        

        Example 1:


        Input: head = [1,2,3,4,5], k = 2
        Output: [2,1,4,3,5]
        Example 2:


        Input: head = [1,2,3,4,5], k = 3
        Output: [3,2,1,4,5]
        */

        if(k==1)
            return head;

        ListNode* beforeReverse = nullptr;
        ListNode* startReverse = head;
        ListNode* endOfReverse = nullptr;
        ListNode* startAfterReverse = nullptr;

        if(!(endOfReverse = doesListEndInKStep(head, k)))
            return head;

        startAfterReverse = endOfReverse->next;

        reverseList(head, k);

        head = endOfReverse;
        startReverse->next = startAfterReverse;

        while(startAfterReverse)
        {
            beforeReverse = startReverse;
            startReverse = startReverse->next;

            if(!(endOfReverse = doesListEndInKStep(startReverse, k)))
                return head;

            startAfterReverse = endOfReverse->next;

            reverseList(startReverse, k);
            startReverse->next = startAfterReverse;
            beforeReverse->next = endOfReverse;

        }

        return head;

    }
};