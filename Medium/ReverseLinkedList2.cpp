
// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        /*
        Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

        Example 1:


        Input: head = [1,2,3,4,5], left = 2, right = 4
        Output: [1,4,3,2,5]
        Example 2:

        Input: head = [5], left = 1, right = 1
        Output: [5]
 
        */

        ListNode* beforeReverse = nullptr;
        ListNode* startOfReverse = head;
        ListNode* endOfReverse = nullptr;
        ListNode* afterReverse;

        for(int i = 1; i < left; i++)
        {
            beforeReverse = startOfReverse;
            startOfReverse = startOfReverse->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = startOfReverse;

        for(int i = left; i <= right; i++)
        {
            
            ListNode* next = curr->next;
            curr->next = prev;
            // next iteration
            prev = curr;
            curr = next;

        }

        startOfReverse->next = curr;

        if(left == 1)
            return prev;

        beforeReverse->next = prev;

        return head;

    }
};