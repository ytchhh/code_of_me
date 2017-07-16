#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include<iostream>
#include<stdlib.h>
using namespace std;

template<class E,class K>
class BST;

template<class E,class K>
class BSTNode						//二叉树结点类
{
	friend class BST<E,K>;
private:
	E	data;						//数据域
	BSTNode<E,K>	*left,*right;	//左子女和右子女
public:
	BSTNode():left(NULL),right(NULL){}	//构造函数
	BSTNode(const E d,BSTNode<E,K> *L = NULL,BSTNode<E,K> *R = NULL):data(d),left(L),right(R)
	{}				//构造函数
	~BSTNode()		//析构函数
	{}
	void setNode(E d)		//修改
	{
		data = d;
	}
	E getData()				//提取
	{
		return data;
	}
};

template<class E,class K>
class BST				//二叉搜索树定义
{

private:
	BSTNode<E,K> *root;			//二叉搜索树的根指针
	K	RefValue;				//输入停止标志，用于输入
	BSTNode<E,K> *Search(const K x,BSTNode<E,K> *ptr);	//递归:搜索
	void makeEmpty(BSTNode<E,K> *& ptr);			//递归，置空
	void PrintTree(BSTNode<E,K> *ptr)const;			//递归：打印
	BSTNode<E,K>* Copy(const BSTNode<E,K> *ptr);	//递归:复制
	BSTNode<E,K>* Min(BSTNode<E,K> *ptr)const;		//递归:求最小
	BSTNode<E,K>* Max(BSTNode<E,K> *ptr)const;		//递归：求最大
	bool Insert(const E& el,BSTNode<E,K> *& ptr);	//递归:插入
	bool Remove(const K x,BSTNode<E,K> *& ptr);		//递归：删除
public:
	BST():root(NULL)		//构造函数
	{}
	BST(K value);			//构造函数
	~BST()			//析构函数
	{}
	bool Search(const K x)const			//搜索
	{
		return (Search(x,root) != NULL) ? true : false;
	}
	BST<E,K>& operator = (const BST<E,K>& R);		//赋值
	void makeEmpty()				//置空
	{
		makeEmpty(root);
		root = NULL;
	}
	void PrintTree()const			//输出
	{
		PrintTree(root);
	}
	E Min()							//求最小
	{
		return Min(root->data);
	}
	E Max()							//求最大
	{
		return Max(root->data);
	}
	bool Insert(const E& el)		//插入新元素
	{
		return Insert(el,root);
	}
	bool Remove(const K x)			//删除含x的结点
	{
		return Remove(x,root);	
	}
};

////////////////////////////////

template<class E,class K>
bool BST<E,K>::Insert(const E& el,BSTNode<E,K> *& ptr)	//在以ptr为根的二叉搜索树中插入el的结点，若在树中已经含有el的结点，则不插入
{
	if(ptr == NULL)					//不存在结点 新结点作为叶子结点插入
	{
		ptr = new BSTNode<E,K>(el);
		if(ptr == NULL)
		{
			cerr<<"Out of Memory"<<endl;
			exit(1);
		}
		return true;
	}
	else if(el < ptr->data)				//左子树插入
		Insert(el,ptr->left);
	else if(el > ptr->data)				//右子树插入
		Insert(el,ptr->right);
	else
		return false;
}

template<class E,class K>
BST<E,K>::BST(K value)				//输入一个元素序列，建立一棵二叉搜索树
{
	E x;
	root = NULL;				//置空树
	RefValue = value;
	cout<<"Enter nuber:";
	cin>>x;						//输入数据
	while(x != RefValue)
	{
		Insert(x);
		cin>>x;					//插入再输入数据
	}
}

template<class E,class K>
void BST<E,K>::PrintTree(BSTNode<E,K> *ptr)const		//打印二叉树
{
	if(ptr != NULL)
	{
		PrintTree(ptr->left);		//打印左子树
		cout<<ptr->data;			//打印数据
		PrintTree(ptr->right);		//打印右子树
	}
}

template<class E,class K>
BSTNode<E,K>* BST<E,K>::Search(const K x,BSTNode<E,K> *ptr)		//私有递归函数，灾异ptr为根的二叉搜索树中搜索含x的结点，若找到，则函数返回该结点的地址，否则函数返回NULL值
{
	if(ptr == NULL)
		return NULL;
	else if(x < ptr->data)
		return Search(x,ptr->left);			//到左子树中继续寻找
	else if(x > ptr->data)
		return Search(x,ptr->right);		//到右子树中继续寻找
	else
		return ptr;					//搜索成功
}

template<class E,class K>
bool BST<E,K>::Remove(const K x,BSTNode<E,K> *&ptr)	//在以ptr为根的二叉树中删除含根x的结点，若删除成功则新根通过ptr返回
{
	BSTNode<E,K> *temp;
	if(ptr != NULL)
	{
		if(x < ptr->data)
			Remove(x,ptr->left);			//在左子树中执行操作
		else if(x > ptr->data)
			Remove(x,ptr->right);			//在右子树中执行操作
		else if(ptr->left != NULL && ptr->right != NULL)
		{	//要删除的结点有两个子女
			temp = ptr->right;
			while(temp->left != NULL)		//在右子树中找到最左的结点
				temp = temp->left;
			ptr->data = temp->data;			//用其替换掉根结点数据
			Remove(ptr->data,ptr->right);	//删除其结点
		}
		else		//要删除的结点只有一个子女或者没有子女
		{
			temp = ptr;
			if(ptr->left == NULL)
				ptr = ptr->right;
			else
				ptr = ptr->left;
			delete temp;
			return true;
		}
	}
	return false;
}

#endif
