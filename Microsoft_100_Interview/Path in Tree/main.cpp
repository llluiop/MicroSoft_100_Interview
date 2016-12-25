#include "../common/bt.h"
#include <vector>

using namespace std;

void path(TreeNode* root, vector<int> v, int sum, vector<vector<int>>& vPaths)
{
	if (root == nullptr)
	{		
		return;
	}

	v.push_back(root->val);
	if (root->left == nullptr && root->right == nullptr && sum == root->val)
	{
		vPaths.push_back(v);
	}

	if (root->left)
		path(root->left, v, sum - root->val, vPaths);

	if (root->right)
		path(root->right, v, sum - root->val, vPaths);

}

vector<vector<int>> Path(TreeNode* root, int sum)
{
	vector<vector<int>> vPaths;
	path(root, {}, sum, vPaths);

	return vPaths;
}



int main()
{
	Tree t;

	string in = "12#3##4#5##";
	t.CreateTree(in);

	auto v = Path(t.Root(), 6);
	return 0;
}