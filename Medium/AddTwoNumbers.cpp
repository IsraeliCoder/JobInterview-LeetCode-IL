
// Leet URL : https://leetcode.com/problems/add-two-numbers/description/


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

    bool nextIter(ListNode*& l1, ListNode*& l2)
    {

        if(l1 != nullptr)
            l1 = l1->next;
        if(l2 != nullptr)
            l2 = l2->next;

        return l1 != nullptr || l2 != nullptr;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
	/*

	You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Example 1:


	Input: l1 = [2,4,3], l2 = [5,6,4]
	Output: [7,0,8]
	Explanation: 342 + 465 = 807.
	Example 2:

	Input: l1 = [0], l2 = [0]
	Output: [0]
	Example 3:

	Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
	Output: [8,9,9,9,0,0,0,1]

	*/

        ListNode* result = new ListNode(l1->val + l2->val);

        ListNode* toReturn = result;



        while(nextIter(l1, l2))
        {
            
            int val1 = l1 == nullptr? 0 : l1->val;
            int val2 = l2 == nullptr? 0 : l2->val;

            result->next = new ListNode(val1 + val2 + (result->val / 10));
            result->val = result->val % 10;

            result = result->next;


        }


        if(result->val  > 9)
        {
            result->next = new ListNode(result->val / 10);
            result->val %= 10;
        }

        return toReturn;

    }
};