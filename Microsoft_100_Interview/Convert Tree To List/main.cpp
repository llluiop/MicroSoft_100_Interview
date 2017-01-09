#include "../common/bst.h"

TreeNode* Convert(TreeNode* root)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	TreeNode* left = Convert(root->left);
	if (left)
	{
		auto tmp = left;
		while (tmp->right) tmp = tmp->right;

		root->left = tmp;
		tmp->right = root;
	}

	TreeNode* right = Convert(root->right);
	if (right)
	{
		root->right = right;
		right->left = root;
	}

	return left == nullptr ? root : left;
	
}



int main()
{
	BSTree b;
	b.Insert(10);
	b.Insert(6);
	b.Insert(14);
	b.Insert(4);
	b.Insert(8);
	b.Insert(12);
	b.Insert(16);
	b.Insert(18);
	b.Insert(17);
	b.Insert(24);
	b.Insert(3);
	b.Insert(7);
	b.Insert(15);

	auto head = Convert(b.Root());
	return 0;
}