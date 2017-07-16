//二叉树头结点
#ifndef _TREE_H
#define _TREE_H

#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;


template<class T>
struct BinTreeNode		//二叉树结点类定义
{
	T				data;			//数据域
	BinTreeNode<T>	*leftChild,*rightChild;		//左子女，右子女链域
	BinTreeNode():leftChild(NULL),rightChild(NULL)	//无参构造函数
	{}
	BinTreeNode(T x,BinTreeNode<T> *l = NULL,BinTreeNode<T> *r = NULL):data(x),leftChild(l),rightChild(r)	//带参构造函数
	{}
	friend bool equal(BinTreeNode<T> *a,BinTreeNode<T> *b)
	{	//如果a 和b的子树相等 则返回false 否则返回true
		if(a == NULL && b == NULL)
			return true;
		if(a != NULL && b == NULL && a->data == b->data && equal(a->leftChild,b->leftChild) && equal(a->rightChild,b->rightChild))
			return true;
		else
			return false;
	}
	//BinTreeNode<T>* createBinaryTree(T *VLR,T *LVR,int n);//利用前序和中序序列构造二叉树
};

template<class T>
BinTreeNode<T>* createBinaryTree(T *VLR,T *LVR,int n)
{//根据前序和中序序列构造二叉树
	if(n == 0)
		return NULL;
	int k = 0;
	while(VLR[0] != LVR[k])	//在中序遍历中找根
		++k;
	BinTreeNode<T> *t = new BinTreeNode<T>(VLR[0]);	//创建根结点
	t->leftChild = createBinaryTree(VLR+1,LVR,k);
	//从前序VLR+1开始对中序的0~k-1左子序列的k个元素递归建立左子树
	t->rightChild = createBinaryTree(VLR+k+1,LVR+k+1,n-k-1);
	//从前序VLR+1+k开始对中序的k+!~n-1右子序列的n-k-1个元素建立右子树
	return t;
}


template<class T>
class BinaryTree
{
public:
public:
	BinaryTree():root(NULL)	//构造函数
	{}
	BinaryTree(T value):RefValue(value),root(NULL)
	{
	}
	BinaryTree(BinaryTree<T> &s)		//拷贝构造函数
	{
		root = Copy(s.root);
	}
	~BinaryTree()			//析构函数
	{
		destroy(root);
	}
	void CreateBinTree()
	{
		root - new BinTreeNode<T>;
		CreateBinTree(root);
	}
	bool IsEmpty()		//判二叉树是否为空
	{
		return (root == NULL) ? true : false;
	}
	BinTreeNode<T>* Parent(BinTreeNode<T> *current)	//返回父节点
	{
		return (root == NULL || root == current) ? NULL : Parent(root,current);
	}
	BinTreeNode<T>* LeftChild(BinTreeNode<T> *current)	//返回左子女
	{
		return (current != NULL) ? current->leftChild : NULL;
	}
	BinTreeNode<T>* RightChild(BinTreeNode<T> *current)		//返回右子女
	{
		return (current != NULL) ? current->rightChild : NULL;
	}
	int Height()		//返回树的高度
	{
		return Height(root);
	}
	int Size()		//返回树的结点数
	{
		return Size(root);
	}
	BinTreeNode<T>* getRoot()const	//取根
	{
		return root;
	}
	void preOrder()	//前序遍历
	{
		preOrder(root);
	}
	void inOrder()		//中序遍历
	{
		inOrder(root);
	}
	void postOrder()	//后序遍历
	{
		postOrder(root);
	}
	bool operator==(BinaryTree<T> &t)
	{	//判断两颗二叉树是否相等
		return (equal(this->root,t.root));
	}
	void levelOrder(void (*visit) (BinTreeNode<T> *p));	//层次序遍历
	int Insert(const T& item);		//插入新元素
	BinTreeNode<T>* Find(T &item)const;		//搜索
protected:
	BinTreeNode<T> *root;	//二叉树的根指针
	T RefValue;			//数据停止输入停止标志
	void CreateBinTree(BinTreeNode<char> *& BT);	//从文件读入建树
	bool Insert(BinTreeNode<T> *& subTree,const T &x);		//插入
	void destroy(BinTreeNode<T> *& subTree);	//删除
	bool Find(BinTreeNode<T> *subTree,const T& x)const;		//查找
	BinTreeNode<T>* Copy(BinTreeNode<T> *orignode);			//复制
	int Height(BinTreeNode<T> *subTree);		//返回树高度
	int Size(BinTreeNode<T> *subTree);		//返回结点数
	BinTreeNode<T> *Parent(BinTreeNode<T> *subTree,BinTreeNode<T> *current);	//返回父结点
	BinTreeNode<T> *Find(BinTreeNode<T> *subTree,const T& x);		//搜寻x
	void Traverse(BinTreeNode<T> *subTree,ostream& out);	//前序遍历输出
	void preOrder(BinTreeNode<T>* subTree);	//前序遍历
	void inOrder(BinTreeNode<T>* subTree);	//中序遍历
	void postOrder(BinTreeNode<T>* subTree);	//后序遍历
	friend istream& operator >> (istream& in,BinaryTree<T>& Tree);		//重载操作 输入
	friend ostream& operator << (ostream& out,BinaryTree<T>& Tree);		//重载操作 输出
};

template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T> *& subTree)
{	//若指针subTree不为空，则删除根为subTree的子树
	if(subTree != NULL)
	{
		destroy(subTree->leftChild);	//递归删除subTree的左子树
		destroy(subTree->rightChild);	//递归删除subTree的右子树
		delete subTree;		//删除subTree
	}
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T> *subTree,BinTreeNode<T> *current)
{	//从节点subTree开始，搜索结点current的父结点。若找到结点current的父结点，咋函数返回父结点地址，否则函数返回NULL
	if(subTree == NULL)
		return NULL;
	if(subTree->leftChild == current || subTree->rightChild == current)
		return subTree;		//找到返回父结点subTree
	BinTreeNode<T> *p;
	if(p = Parent(subTree->leftChild,current) != NULL)
		return p;			//递归在左子树中搜索
	else
		return Parent(subTree->rightChild,current);		//递归在右子树中搜索
}

template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree,ostream& out)
{	//搜索并输出根为subTree的二叉树
	if(subTree != NULL)		//subTree为空则返回 否则
	{
		out<<subTree->data<<" ";	//输出subTree的数据值
		Traverse(subTree->leftChild,out);	//递归搜索并输出subTree的左子树
		Traverse(subTree->rightChild,out);	//递归搜索并输出subTree的右子树
	}
}

template<class T>
istream& operator >> (istream& in,BinaryTree<T>& Tree)
{	//重载操作 输入并建立一颗二叉Tree in是输入流对象
	CreateBinTree(in,Tree.root);		//建立二叉树
	return in;
}

template<class T>
ostream& operator << (ostream& out,BinaryTree<T>& Tree)
{	//重载操作 输出一颗二叉树Tree, out是输出流对象
	out<<"二叉树的前序遍历\n";		//提示：搜索二叉树
	Tree.Traverse(Tree.root,out);	//从根开始输出
	out<<endl;
	return out;
}

template<class T>
void BinaryTree<T>::CreateBinTree(BinTreeNode<char> *&BT)	//*&是对指针的引用
{
	stack<BinTreeNode<char> * > s;
	BT = NULL;		//置空二叉树
	BinTreeNode<char> *p,*t;
	int k;		//用k作为处理左右子树标记
	char ch;
	cin>>ch;			//从in顺序读入一个字符
	while(ch != RefValue)	//逐个字符处理
	{
		switch(ch)
		{
			case '(':s.push(p); k = 1; break;		//进入子树
			case ')':s.pop();break;			//退出子树
			case ',':k = 2;break;
			default:p = new BinTreeNode<T>(ch);
				if(BT == NULL)
					BT = p;
				else if(k == 1)
				{
					t = s.top();
					t->leftChild = p;		//链入*t的左子女
				}
				else
				{
					t = s.top();
					t->rightChild = p;		//链入*t的右子女
				}
		}
		cin>>ch;
	}
}

template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T>* subTree)
{	//递归算法 按照前序次序遍历以subTree为根的二叉树
	if(subTree != NULL)
	{
		cout<<(subTree)->data;		//访问根结点
		preOrder(subTree->leftChild);		//前序遍历根的左子树
		preOrder(subTree->rightChild);	//前序遍历根的右子树
	}
}

template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T>* subTree)
{	//递归函数 按照中序次序遍历以subTree为根的子树
	if(subTree != NULL)
	{
		inOrder(subTree->leftChild);	//中序遍历根的左子树
		cout<<(subTree)->data;			//访问根结点
		inOrder(subTree->rightChild);		//中序遍历根的右子树
	}
}

template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T>* subTree)
{	//递归函数 按照前序次序遍历subTree为根的子树
	if(subTree != NULL)
	{
		postOrder(subTree->leftChild);
		postOrder(subTree->rightChild);
		cout<<(subTree)->data;
	}
}

template<class T>
int BinaryTree<T>::Height(BinTreeNode<T> *subTree)
{	//计算以subTree为根的二叉树的高度或深度
	if(subTree == NULL)
		return 0;	//递归结束 空树高度为0
	else
	{
		int i = Height(subTree->leftChild);
		int j = Height(subTree->rightChild);
		return (i < j) ? j+1 : i+1;
	}
	
}

template<class T>
int BinaryTree<T>::Size(BinTreeNode<T> *subTree)
{	//计算以subTree为根结点的二叉树的结点个数
	if(subTree == NULL)		//递归结束 空树的结点个数为0
		return 0;
	else
		return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T> *orignode)
{	//这个函数返回一个指针，他给出一个以orignode为根的二叉树的副本
	if(orignode == NULL)	//根为空 返回空指针
		return NULL;
	BinTreeNode<T>* temp = new BinTreeNode<T>;	//创建根结点
	temp->data = orignode->data;		//传送数据
	temp->leftChild = Copy(orignode->leftChild);	//拷贝左子树
	temp->rightChild = Copy(orignode->rightChild);		//拷贝右子树
	return temp;		//返回根指针
}



#endif
