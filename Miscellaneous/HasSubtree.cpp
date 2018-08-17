#include "stdafx.h"

/*
	输入两棵二叉树A，B，判断B是不是A的子结构。
*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class HasSubtree {
	bool Has_Subtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL) {
			return false;
		}
		return isSubtree(pRoot1, pRoot2) || Has_Subtree(pRoot1->left, pRoot2) || Has_Subtree(pRoot1->right, pRoot2);
	}
	bool isSubtree(TreeNode* root1, TreeNode* root2) {
		if (root2 == NULL) {
			return true;
		}
		if (root1 == NULL) {
			return false;
		}
		if (root1->val == root2->val) {
			return isSubtree(root1->left, root2->left) && isSubtree(root1->right, root2->right);
		}
		else {
			return false;
		}
	}
};