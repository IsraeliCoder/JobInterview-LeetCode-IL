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
    ListNode* swapPairs(ListNode* head) {
        
        /*
        
        Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

        Example 1:


        Input: head = [1,2,3,4]
        Output: [2,1,4,3]
        Example 2:

        Input: head = []
        Output: []
        Example 3:

        Input: head = [1]
        Output: [1]
        
        */

        if(head == nullptr)
            return nullptr;

        if(head->next == nullptr)
            return head;

        ListNode* toReturn = head->next;
        ListNode* runner = head;
        ListNode* prev = nullptr;
        while(runner != nullptr && runner->next != nullptr)
        {

            ListNode* start = runner;
            ListNode* end = runner->next;
            ListNode* next = end->next;

            end->next = start;
            start->next = next;
            if(prev != nullptr)
                prev->next = end;

            prev = start;
            runner = next;

        }
        
        return toReturn;

    }
};