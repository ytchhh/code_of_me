#ifndef _AVLTREE_H
#define _AVLTREE_H

#include<iostream>
#include<stack>
using namespace std;

template<class E,class K>
class AVLTree;

template<class E,class K>
class AVLNode			//AVLNode结点的类定义
{
friend AVLTree<E,K>;
private:
	E data;				//平衡因子					
	AVLNode<E,K> *left,*right;
	int bf;
public:
	AVLNode():left(NULL),right(NULL),bf(0)
	{}
	AVLNode(E d,AVLNode<E,K> *l = NULL,AVLNode<E,K> *r = NULL):data(d),left(l),right(r),bf(0)
	{}
};

template<class E,class K>		//平衡二叉搜索树的类定义
class AVLTree
{
private:
	AVLNode<E,K> *root;	//根结点
	K RefValue;				//结束标志
protected:
	AVLNode<E,K>* Search(K x,AVLNode<E,K> *& ptr)const;
	bool Insert(AVLNode<E,K> *& ptr,E& el);
	bool Remove(AVLNode<E,K> *& ptr,E k);
	void RotateL(AVLNode<E,K> *& ptr);		//左单旋
	void RotateR(AVLNode<E,K> *& ptr);		//右单旋
	void RotateLR(AVLNode<E,K> *& ptr);		//先左后右单旋
	void RotateRL(AVLNode<E,K> *& ptr);		//先右后左单旋
	int Height(AVLNode<E,K> *ptr)const;		//求高度
public:
	AVLTree():root(NULL)		//构造空二叉树
	{}
	AVLTree(K Ref):RefValue(Ref),root(NULL)		//构造函数 构造非空二叉树
	{}
	bool Insert(E& el)
	{
		return Insert(root,el);
	}
	bool Remove(E el)
	{
		return Remove(root,el);
	}
	friend istream& operator >> (istream& in,AVLTree<E,K>& Tree);
	friend ostream& operator >> (ostream* out,AVLTree<E,K>& Tree);
	int Height()const;
};

template<class E,class K>
void AVLTree<E,K>::RotateL(AVLNode<E,K> *& ptr)		//左单旋转算法
{
	AVLNode<E,K> *subL = ptr;			//要左旋的结点
	ptr = subL->right;					//原根的右子女
	subL->right = ptr->left;			//ptr成为新根前卸掉其左边负载
	ptr->left = subL;					//左单旋转，ptr为新根
	ptr->bf = subL->bf = 0;				//新的平衡因子
}

template<class E,class K>
void AVLTree<E,K>::RotateR(AVLNode<E,K> *& ptr)		//右单旋转算法
{
	AVLNode<E,K> *subR = ptr;			//要右旋转的结点
	ptr = subR->left;					//原根的左子女
	subR->left = ptr->right;			//ptr成为新根前卸掉其右边负载
	ptr->right = subR;					//右单旋转，ptr为新根
	ptr->bf = subR->bf = 0;				//改变平衡因子
}

template<class E,class K>
void AVLTree<E,K>::RotateLR(AVLNode<E,K> *& ptr)	//先左后右双旋转
{
	AVLNode<E,K> *subL,*subR;		//
	subL = ptr->left;
	subR = ptr;
	ptr = subL->right;
	subL->right = ptr->left;		//ptr成为新根前甩掉它左边的负载
	ptr->left = subL;				//左单旋转，ptr成为新根
	if(ptr->bf <= 0)		//说明新增结点在左边给了subL
		subL->bf = 0;
	else					//说明新增结点在右边给了subR
		subL->bf = -1;
	subR->left = ptr->right;		//ptr成为新根前甩掉它右边的负载
	ptr->right = subR;				//右单旋转，ptr成为新根
	if(ptr->bf <= 0)		//说明新增结点在左边给了subL
		subR->bf = 1;
	else
		subR->bf = 0;		//说明新增结点在右边给了subR
	ptr->bf = 0;
}

template<class E,class K>
void AVLTree<E,K>::RotateRL(AVLNode<E,K> *& ptr)	//先右旋后左旋
{
	AVLNode<E,K> *subR,*subL;
	subR = ptr->right;
	subL = ptr;
	ptr = subR->left;
	subR->left = ptr->right;	//ptr成为新根前卸掉它右边的负载
	ptr->right = subR;			//右单旋转，ptr成为新根
	if(ptr->bf >= 0)
		subR->bf = 0;
	else
		subR->bf = 1;
	subL->right = ptr->left;	//ptr成为新根前卸掉它的左边的负载
	ptr->left = subL;			//左单旋转，ptr成为新根
	if(ptr->bf >= 0)
		subL->bf = -1;
	else
		subL->bf = 0;
	ptr->bf = 0;
}
template<class E,class K>
bool AVLTree<E,K>::Insert(AVLNode<E,K> *& ptr,E& el)	//在以ptr为根的的树中插入新元素，如果插入成功，函数返回true否则返回false
{
	AVLNode<E,K> *pr = NULL,*p = ptr,*q;
	int d;
	stack<AVLNode<E,K> * > st;
	while(p != NULL)				//寻找插入位置
	{
		if(el == p->data)			//找到等于el的结点，不插入
			return false;
		pr = p;						//pr是待插入结点的父结点
		st.push(pr);				//否则用栈记忆查找路径
		if(el < p->data)
			p = p->left;
		else
			p = p->right;
	}
	p = new AVLNode<E,K>(el);		//创建要插入的新结点
	if(p == NULL)
	{
		cerr<<"out of memory"<<endl;
		exit(1);
	}
	if(pr == NULL)		//空树
	{
		ptr = p;
		return true;
	}
	if(el < pr->data)
		pr->left = p;	//左结点插入
	else
		pr->right = p;	//右结点插入
	while(st.empty() == false)
	{
		pr = st.top();		//重新平衡化
		st.pop();			//从栈中退出父结点
		if(p == pr->left)	//调整父结点的平衡因子
			pr->bf--;
		else
			pr->bf++;
		if(pr->bf == 0)		//第一种情况，平衡退出
			break;
		if(pr->bf == 1 || pr->bf == -1)		//第二种情况，|bf| = 1
			p = pr;							//回朔父结点是否存在
		else								//第三种情况，|bf| = 2
		{
			if(pr->bf == 2)
			{
				if(pr->right->bf > 0)
					RotateL(pr);		//    \
				else
					RotateRL(pr);		//		>
			}
			else
			{
				if(pr->left->bf < 0)
					RotateR(pr);		//	/
				else
					RotateLR(pr);		//	<
			}
			break;
		}
	}
	if(st.empty() == true)		//调整到树的根结点
		ptr = pr;
	else
	{								//中间重新链接
		q = st.top();
		if(q->data > pr->data)
			q->left = pr;
		else
			q->right = pr;
	}
	return true;
}


template<class E,class K>
bool AVLTree<E,K>::Remove(AVLNode<E,K> *& ptr, E k)	//在以ptr为根的AVL树中删除关键码为x的结点。如果删除成功，函数返回true,同时通过参数el返回被删结点元素，如果删除失败则函数返回false
{
	if(ptr == NULL)
		return false;
	AVLNode<E,K> *pr = NULL,*p = ptr,*q;
	int d,dd = 0;
	stack<AVLNode<E,K> * > st;
	while(p != NULL)		//寻找删除位置
	{
		if(k == p->data)	//找到等于k的结点，停止搜索
			break;
		pr = p;			//pr始终是指向父结点
		st.push(pr);	//用栈来存储查找的路径
		if(k < p->data)
			p = p->left;
		else
			p = p->right;
	}
	if(p == NULL)
		return false;
	if(p->left != NULL && p->right != NULL)
	{
		pr = p;
		st.push(pr);
		q = p->left;
		while(q->right != NULL)
		{
			pr = q;			//pr是要删除的结点的父结点
			
			q = q->right;
		}
		p->data = q->data;
		p = q;				//转换要删除的结点
	}
	
	if(p->left != NULL)
		q = p->left;
	else
		q = p->right;
	
	if(pr == NULL)			//要删除的结点为根结点
		ptr = q;
	else
	{
		if(pr->left == p)	//要删除的结点是父结点的左子树
			pr->left = q;
		else
			pr->right = q;
		while(!st.empty() )
		{
			pr = st.top();
			st.pop();

			if(pr->left == q)
				pr->bf++;
			else
				pr->bf--;
			
			if(pr->bf == 1 || pr->bf == -1)
				break;
			else if(pr->bf == 0)
				continue;
			else
			{
				if(pr->bf > 0)
					q = pr->right;
				else
					q = pr->left;
				if(q->bf == 0)		//单旋转
				{
					if(pr->bf > 0)
					{
						RotateL(pr);		// \
						//bf
						pr->left->bf = 1;
						pr->bf = -1;
					}
					else
					{
						RotateR(pr);		// /
						pr->right->bf = -1;
						pr->bf = 1;
					}
				}
				else if(q->bf > 0)
				{
					if(pr->bf > 0)			// \ //
						RotateL(pr);
					else				// <
						RotateLR(pr);
				}
				else
				{
					if(pr->bf < 0)		// /
					{
						RotateR(pr);
					}
					else				// >
					{
						RotateRL(pr);
					}
				}
				break;
			}
		}
		AVLNode<E,K> *ppr = st.top();
		if(ppr->data > pr->data)
			ppr->left = pr;
		else
			ppr->right = pr;
	}
	//2 调整平衡因子
	delete p;
	return true;
}

#endif
