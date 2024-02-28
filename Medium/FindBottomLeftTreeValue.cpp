
// Leet URL : https://leetcode.com/problems/find-bottom-left-tree-value/?envType=daily-question&envId=2024-02-28


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:


    void findBottomLeftValueHelper(TreeNode* root, int& answer, int& maxRank, int rank)
    {

        if(root == nullptr)
            return;

        if(rank > maxRank)
        {
            answer = root->val;
            maxRank = rank;
        }

        findBottomLeftValueHelper(root->left, answer, maxRank, rank + 1);
        findBottomLeftValueHelper(root->right, answer, maxRank, rank + 1);

    }

    int findBottomLeftValue(TreeNode* root) {
        
		/*
		
		Given the root of a binary tree, return the leftmost value in the last row of the tree.
		
		Example 1:
		Input: root = [2,1,3]
		Output: 1
		
		Example 2:
		Input: root = [1,2,3,4,null,5,6,null,null,7]
		Output: 7
		
		*/
		
        int answer = 0;
        int rank = 0;
        int maxRank = 0;

        if(root->left == nullptr && root->right == nullptr)
        {
           return root->val;
        }

        findBottomLeftValueHelper(root, answer, maxRank, rank);
        return answer;

        /*

        vector<TreeNode*> curr {root};

        if(root->right == nullptr && root->left == nullptr)
            return root->val;

        while(true)
        {
            vector<TreeNode*> next;
            int n = curr.size();

            for(int i = 0 ; i < n; i++)
            {
                if(curr[i]->left != nullptr)
                    next.push_back(curr[i]->left);

                if(curr[i]->right != nullptr)
                    next.push_back(curr[i]->right);
            }

            if(next.size() == 0)
                return curr[0]->val;

            curr = next;

        */

    }
};