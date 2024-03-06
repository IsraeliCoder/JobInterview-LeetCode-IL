
// https://leetcode.com/problems/merge-two-sorted-lists/

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

    ListNode* moveNode(ListNode*& list)
    {
        ListNode* toReturn = list;
        list = list->next;
        return toReturn;
    }

    ListNode* getNextNode(ListNode*& list1, ListNode*& list2)
    {
        
        if(list1 == nullptr && list2 == nullptr)
            return nullptr;
        
        if(list1 == nullptr)
        {
            return moveNode(list2);
        }
        else if(list2 == nullptr)
        {
            return moveNode(list1);
        }
        else
        {
            if(list1->val < list2->val)
            {
                return moveNode(list1);
            }
            return moveNode(list2);
        }


    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        /*
        
        You are given the heads of two sorted linked lists list1 and list2.

        Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

        Return the head of the merged linked list.

        Example 1:


        Input: list1 = [1,2,4], list2 = [1,3,4]
        Output: [1,1,2,3,4,4]
        Example 2:

        Input: list1 = [], list2 = []
        Output: []
        Example 3:

        Input: list1 = [], list2 = [0]
        Output: [0]
        
        
        */

        if(list1 == list2 && list1 == nullptr)
            return nullptr;
        else if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;

        ListNode* toReturn = nullptr;
        if(list1->val < list2->val)
        {
            toReturn = moveNode(list1);
        }
        else
        {
            toReturn = moveNode(list2);
        }

        ListNode* runner = toReturn;
        while(list1 != nullptr && list2 != nullptr)
        {
            runner->next = getNextNode(list1, list2);
            runner = runner->next;
        }

        if(list2)
            runner->next = list2;
        else if(list1)
            runner->next = list1;

        return toReturn;

    }
};