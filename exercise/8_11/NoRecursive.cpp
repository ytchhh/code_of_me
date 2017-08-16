/*
   非递归方式实现二叉树的先序遍历，并将每个结点的值保存在数组中。

 */


struct TreeNode
{
		int value;
		TreeNode* left;
		TreeNode* right;
};

void Traverse TreeInPreOrder(vector<int>& values,const TreeNode* root)
{
		if(root == NULL)
				return;
		stack<TreeNode*> st;
		values.push_back(nodes->value);
		TreeNode* nodes = root;
		while(nodes || !st.empty())
		{
				while(nodes != NULL)
				{
						st.push(nodes);
						values.push_back(nodes->value);
						nodes = nodes->left;
				}

				st.pop();
				nodes = st.top();
				nodes = nodes->right;
		}
}
