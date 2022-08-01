/*

 * For every node, we need to check whether making it the uppermost node of a
   univalue path makes the resulting path the longest one.

   To do this, we need to find the longest univalue paths that this node makes
   using the left and the right subtrees.
   If the length of the longest univalue path that this node makes using the
   left subtree plus the length of the longest univalue path that this node
   makes using the right subtree is greater than the length of the currently
   stored longest univalue path, then we update this maximum value.

   To find the length of the longest univalue path that this node makes using
   the left subtree, we need to know the lengths of the longest univalue paths
   that the left child makes using its left and right subtrees.
   Similarly, to find the length of the longest univalue path that this node
   makes using the right subtree, we need to know the lengths of the longest
   univalue paths that the right child makes using its left and right subtrees.

   Thus, for every node, we can return the lengths of the longest univalue paths
   that this node makes using the left and the right subtrees.

 */





class Solution
{

    public:

    std::vector<int> l_r(TreeNode* root, int* ptr_global_max)
    {
        std::vector<int> ret(2);

        std::vector<int> ret_left(2);
        std::vector<int> ret_right(2);

        if (root->left)
            ret_left = l_r(root->left, ptr_global_max);

        if (root->right)
            ret_right = l_r(root->right, ptr_global_max);

        if ((root->left) && (root->val == root->left->val))
            ret[0] = (std::max(ret_left[0], ret_left[1]) + 1);
        else
            ret[0] = 0;

        if ((root->right) && (root->val == root->right->val))
            ret[1] = (std::max(ret_right[0], ret_right[1]) + 1);
        else
            ret[1] = 0;

        if ((ret[0] + ret[1]) > *ptr_global_max)
            *ptr_global_max = (ret[0] + ret[1]);

        return ret;
    }

    int longestUnivaluePath(TreeNode* root)
    {
        int global_max = 0;

        if (root)
            l_r(root, &(global_max));

        return global_max;
    }

};
