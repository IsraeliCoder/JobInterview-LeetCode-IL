
// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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

    void removeNodeFromList(ListNode* start, ListNode* end, unordered_map<ListNode*, bool>& nodeInList)
    {

        while(start != end)
        {
            nodeInList[start] = false;
            start = start->next;
        }

        nodeInList[end] = false;

    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        
        /*
        
        Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

        After doing so, return the head of the final linked list.  You may return any such answer.

        (Note that in the examples below, all sequences are serializations of ListNode objects.)

        Example 1:

        Input: head = [1,2,-3,3,1]
        Output: [3,1]
        Note: The answer [1,2,1] would also be accepted.
        Example 2:

        Input: head = [1,2,3,-3,4]
        Output: [1,2,4]
        Example 3:

        Input: head = [1,2,3,-3,-2]
        Output: [1]
        
        */

        unordered_map<int, ListNode*> sumToNode;
        unordered_map<ListNode*, bool> nodeInList;
        int sum = 0;

        ListNode* runner = head;

        while(runner)
        {

            nodeInList[runner] = true;

            sum += runner->val;

            if(sum == 0)
            {
                
                removeNodeFromList(head, runner, nodeInList);
                head = runner->next;
                runner = head;
                continue;

            }

            if(sumToNode.count(sum))
            {

                if(nodeInList[sumToNode[sum]])
                {
                    removeNodeFromList(sumToNode[sum]->next, runner, nodeInList);
                    sumToNode[sum]->next = runner->next;
                }
                else
                    sumToNode[sum] = runner;

            }
            else
            {
                sumToNode[sum] = runner;
            }

            runner = runner->next;

        }

        return head;

    }
};