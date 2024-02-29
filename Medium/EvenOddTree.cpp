
// https://leetcode.com/problems/even-odd-tree/?envType=daily-question&envId=2024-02-29

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

    inline void insertNewNodes(vector<TreeNode*>& vec, TreeNode* right, TreeNode* left, bool toTheLeft)
    {
        if(toTheLeft)
        {

            if(right != nullptr)
                vec.push_back(right);
            if(left != nullptr)
                vec.push_back(left);

        }
        else
        {

            if(left != nullptr)
                vec.push_back(left);
            if(right != nullptr)
                vec.push_back(right);

        }

    }

    bool isEvenOddTree(TreeNode* root) {

        if(root->val % 2 == 0)
            return false;

        vector<TreeNode*> curr;
        insertNewNodes(curr, root->right, root->left, true);
        bool toTheLeft = true;

        while(curr.size() > 0)
        {

            int tempN = curr.size();
            for(int i = 0 ; i < tempN - 1; i++)
            {
                if(toTheLeft ? (curr[i]->val % 2) == 1 : (curr[i]->val % 2) == 0)
                    return false;

                if(curr[i]->val >= curr[i + 1]->val)
                    return false;
            }

            if(toTheLeft ? (curr[tempN - 1]->val % 2) == 1 : (curr[tempN - 1]->val % 2) == 0)
                    return false;

            vector<TreeNode*> next = {};
            for(int i = tempN - 1; i >= 0; i--)
            {

                insertNewNodes(next, curr[i]->left, curr[i]->right, toTheLeft);
            }

            toTheLeft = !toTheLeft;
            curr = next;

        }

        return true;
    }
};