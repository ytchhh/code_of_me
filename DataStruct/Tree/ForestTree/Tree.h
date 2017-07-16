//树的子女兄弟表示
#ifndef _TREE_H
#define _TREE_H

#include<iostream>
using namespace std;

template<class T>
struct TreeNode			//树的结点类
{
	T	data;			//结点数据
	TreeNode<T> *firstChild,*nextSibling;		//子女及兄弟结点
	TreeNode(T value = 0,TreeNode<T> *fc = NULL,TreeNode<T> *ns = NULL):data(value),firstChild(fc),nextSibling(ns)	//构造函数
	{}
};

template<class T>
class Tree			//树类
{
private:
	TreeNode<T> *root,*current;				//根指针及当前指针
	bool Find(TreeNode<T> *p,T value);		//在以p为根的树中搜索value
	void RemovesubTree(TreeNode<T> *p);		//删除以p为根的子树
	bool FindParent(TreeNode<T> *t,TreeNode<T> *p);
public:
	Tree() {root = current = NULL;}		//构造函数，建立空树
	bool Root();				//寻找根，使之成为当前结点
	bool IsEmpty()			//判空树
	{
		return root = NULL;
	}
	bool FirstChild();		//寻找当前结点的第一个子女，使之成为当前结点
	bool NextSibling();		//寻找当前结点的下一个结点，使之成为当前结点
	bool Parent();			//寻找当前结点的双亲结点，使之成为当前结点
	bool Find(T target);			//在树中搜索含有target的结点，使之成为当前结点
	void PreOrder(TreeNode<T> *p);		//先根次序遍历并输出以*p为根的树
	void PostOrder(TreeNode<T> *p);		//后根次序遍历并输出以*p为根的树
};

template<class T>
bool Tree<T>::Root()		//让树的当前结点称为树的根结点
{
	if(root == NULL)
	{
		current = NULL;
		return false;
	}
	else
	{
		current = root;
		return true;
	}
}

template<class T>
bool Tree<T>::Parent()		//在树中找当前结点的父结点，使之成为当前结点
{
	TreeNode<T> *p = current;
	if(current == NULL || current == root)
	{	//空树或者根为当前结点，返回0。
		current = NULL;
		return false;
	}
	return FindParent(root,p);		//从根结点开始找*p的父结点
}

template<class T>
bool Tree<T>::FindParent(TreeNode<T> *t,TreeNode<T> *p)	//在跟为*t的树中寻找*p的父结点，并使之成为当前结点
{
	TreeNode<T> *q = t->firstChild;
	bool succ;
	while(q != NULL && q != p)				//循环的长子的兄弟链，搜索
	{
		if((succ = FindParent(q,p)) == true)	//找到
			return succ;
		q = q->nextSibling;
	}
	if(q != NULL && q == p)
	{
		current = t;
		return true;
	}
	else	//未找到父结点
	{
		current = NULL;
		return false;
	}
}

template<class T>
bool Tree<T>::FirstChild()	//在树中寻找当前结点的长子，并使之成为当前结点
{
	if(current != NULL && current->firstChild != NULL)
	{
		current = current->firstChild;
		return true;
	}
	current = NULL;
	return false;
}

template<class T>
bool Tree<T>::NextSibling()		//在树中寻找当前结点的兄弟，并使之成为当前结点
{
	if(current != NULL && current->nextSibling != NULL)
	{
		current = current->nextSibling;
		return true;
	}
	current = NULL;
	return false;
}

template<class T>
bool Tree<T>::Find(T value)
{
	if(IsEmpty())
		return false;
	return Find(root,value);
}

template<class T>
bool Tree<T>::Find(TreeNode<T> *p,T value)		//在根为*p的树中找值为value的结点，找到该结点之后成为当前结点，否则当前结点不变
{												//函数返回成功标志：=true,成功，=false，失败
	bool result = false;
	if(p->data == value)		//搜索成功
	{
		result = true;
		current = p;
	}
	else			//搜索失败
	{
		TreeNode<T> *q = p->firstChild;
		while(q != NULL && !(result - Find(q,value)))
			q = q->nextSibling;
	}
	return result;
}

template<class T>
void Tree<T>::PreOrder(TreeNode<T> *p)
{
	if(p != NULL)		//当树非空时
	{
		cout<<p->data;			//输出根结点数据
		for(p = p->firstChild; p != NULL; p = p ->nextSibling)
			PreOrder(p);
	}
}

template<class T>
void Tree<T>::PostOrder(TreeNode<T> *p)
{
	if(p != NULL)			//当树非空时
	{
		TreeNode<T> *q;
		for(q = p->firstChild; q != NULL; q = q->nextSibling)
			PostOrder(q);
		cout<<p->data;			//最后访问根结点
	}
}

#endif
