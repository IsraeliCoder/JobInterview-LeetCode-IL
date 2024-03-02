
 // https://leetcode.com/problems/merge-k-sorted-lists/description/


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

    void removeEmptyList(vector<ListNode*>& lists)
    {
        int n = lists.size();
        for(int i = n-1; i >= 0; i--)
        {
            if(!lists[i])
                lists.erase(lists.begin() + i);
        }

    }

    ListNode* getSmallestNode(vector<ListNode*>& lists)
    {

        ListNode* smallestNode = lists[0];
        int smallestVal = lists[0]->val;
        int index = 0;

        int n = lists.size();
        for(int i = 1; i < n; i++)
        {
            if(lists[i]->val < smallestVal)
            {
                smallestVal = lists[i]->val;
                smallestNode = lists[i];
                index = i;
            }
        }

        lists[index] = lists[index]->next;
        return smallestNode;

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
		/*
		You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

		Merge all the linked-lists into one sorted linked-list and return it.

		 

		Example 1:

		Input: lists = [[1,4,5],[1,3,4],[2,6]]
		Output: [1,1,2,3,4,4,5,6]
		Explanation: The linked-lists are:
		[
		  1->4->5,
		  1->3->4,
		  2->6
		]
		merging them into one sorted list:
		1->1->2->3->4->4->5->6
		Example 2:

		Input: lists = []
		Output: []
		Example 3:

		Input: lists = [[]]
		Output: []
		*/
		
        removeEmptyList(lists);
        if(lists.size() == 0)
            return nullptr;

        ListNode* head = getSmallestNode(lists);

        removeEmptyList(lists);
        if(lists.size() == 0)
            return head;

        ListNode* runner = head;
        while(lists.size() != 0)
        {
            runner->next = getSmallestNode(lists);
            removeEmptyList(lists);
            runner = runner->next;
        }

        return head;

    }

};


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
 /*
class Solution {
public:
   
    ListNode* mergeTwoNodesList(ListNode* one, ListNode* two)
    {

        if(!two && !one)
            return nullptr;

        if(!two)
            return one;

        if(!one)
            return two;

        ListNode* head;

        if(one->val > two->val)
        {
            head = two;
            two = two->next;
        }
        else
        {
            head = one;
            one = one->next;
        }

        ListNode* runner = head;

        while(one && two)
        {
            if(one->val > two->val)
            {
                runner->next = two;
                two = two->next;
            }
            else
            {
                runner->next = one;
                one = one->next;
            }
            runner = runner->next;
        }

        if(one)
        {
            runner->next = one;
            one = one->next;
        }

        if(two)
        {
            runner->next = two;
            two = two->next;
        }

        return head;

    }

    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int i, int j)
    {
        if(i > j)
            return nullptr;

        if(i == j)
            return lists[i];

        if(i + 1 == j)
            return mergeTwoNodesList(lists[i], lists[j]);

        if(!lists[i])
            return mergeKListsHelper(lists, i + 1, j);
            
        if(!lists[j])
            return mergeKListsHelper(lists, i, j - 1);

        int middle = (i + j) / 2;
        ListNode* left = mergeKListsHelper(lists, i, middle);
        ListNode* right = mergeKListsHelper(lists, middle + 1, j);

        return mergeTwoNodesList(left, right);

    }
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        return mergeKListsHelper(lists, 0, lists.size() - 1);

    }

};
*/
