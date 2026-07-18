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
private:
    unordered_map<int, int> mp;
    int maxFreq = 0;

    int getSubtreeSum(TreeNode* root) {
        if (!root) return 0;

        int leftSum = getSubtreeSum(root->left);
        
        int rightSum = getSubtreeSum(root->right);

        int currentSum = leftSum + rightSum + root->val;

        mp[currentSum]++;
        maxFreq = max(maxFreq, mp[currentSum]);

        return currentSum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        
        getSubtreeSum(root);

        for (auto const& [sum, freq] : mp) {
            if (freq == maxFreq) {
                ans.push_back(sum);
            }
        }

        return ans;
    }
};