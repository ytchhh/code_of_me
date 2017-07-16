#ifndef _RBTREE_H
#define _RBTREE_H

#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;

enum COLOR{RED = 0,BLACK};

template<class T>
class RBTree;

template<class T>
class RBTreeNode				//红黑树结点类
{
	friend class RBTree<T>;
private:
	T				data;		//数据域
	COLOR			color;		//颜色
	RBTreeNode<T>	*parent;	//父结点
	RBTreeNode<T>	*leftChild,*rightChild;		//左右子女指针
public:
	RBTreeNode():data(T(),color(RED),parent(NULL),leftChild(NULL),rightChild(NULL))		//无参构造函数
	{}
	RBTreeNode(T d,COLOR c = RED,RBTreeNode<T> *pr = NULL,RBTreeNode<T> *left = NULL,RBTreeNode<T> *right = NULL):data(d),color(c),parent(pr),leftChild(left),rightChild(right)					//带参构造函数
	{}
	~RBTreeNode()
	{}
};

template<class T>
class RBTree					//红黑树类定义
{
private:
	RBTreeNode<T> *root;		//根结点
public:
	RBTree():root(NULL)			//空树
	{
	}
	bool Insert(const T& x)		//插入函数
	{
		Insert(root,x);
	}
protected:
	bool Insert(RBTreeNode<T> *& t,const T& x)
	{
		RBTreeNode<T> *p = t;
		RBTreeNode<T> *pr = NULL;		//插入位置的父结点
		while(p != NULL)					//找到要插入的位置
		{
			if(x == p->data)
				return false;

			pr = p;

			if(x < p->data)
				p = p ->leftChild;
			else
				p = p->rightChild;
		}

		p = _BuyNode(x);					//申请结点

		if(pr == NULL)						//插入的为根位置
		{
			t = p;
			t->color = BLACK;
			return true;
		}
		
		if(x < pr->data)					//插入的位置为左子树
			pr->leftChild = p;
		else
			pr->rightChild = p;				//插入的位置为右子树
		p->parent = pr;

		_Balance_Tree(t,p);			//调整树的位置 即平衡树
	}
	RBTreeNode<T>* _BuyNode(const T& x)
	{
		RBTreeNode<T> *p = new RBTreeNode<T>(x);
		assert(p != NULL);
		return p;
	}
	void _Balance_Tree(RBTreeNode<T> *& t,RBTreeNode<T> *p)
	{
		RBTreeNode<T> *s;
		while(p->parent != NULL && p->parent->color == RED)			//p插入的父结点的父亲的颜色是否为红色
		{
			if(p->parent == p->parent->parent->leftChild)		//p的父亲是在外侧插入
			{
				s = p->parent->parent->rightChild;				//s为插入结点的父结点的兄弟结点

				if(s != NULL && s->color == RED)			//只要看到有某结点X的两个子节点皆为红色，就把X改为红色，并把两个子节点改为黑色， 但是此时如果X的父结点p亦为红色，就得像状况1一样地做一次单旋转并改变颜色，或是像状况2一样地做一次双旋转并改变颜色。
				{
					p->parent->color = BLACK;
					s->color = BLACK;
					p->parent->parent->color = RED;
					p = p->parent->parent;
					continue;
				}
				else if(p == p->parent->rightChild)			//情况2 <
				{
					p = p->parent;
					RotateL(p);
				}

				p->parent->color = BLACK;					//情况3
				p->parent->parent->color = RED;
				RotateR(p->parent->parent);
			}
			else
			{
				s = p->parent->parent->leftChild;

				if(s != NULL && s->color == RED)
				{
					s->color = BLACK;
					p->parent->color = BLACK;
					p->parent->parent->color = RED;
					p = p->parent->parent;
					continue;
				}
				else if(p == p->parent->leftChild)
				{
					p = p->parent;
					RotateR(p);
				}

				p->parent->color = BLACK;
				p->parent->parent->color = RED;
				RotateL(p->parent->parent);
			}
		}
		t->color = BLACK;
	}

/*
	void _Balance_Tree(RBTreeNode<T> *& t,RBTreeNode<T> *p)
	{
		RBTreeNode<T> *s;
		while(p->parent != NULL &&  p->parent->color == RED)				//插入结点的父结点是红色的 才会调整
		{
			if(p->parent == p->parent->parent->leftChild)	//插入结点的父结点是外结点
			{
				s = p->parent->parent->rightChild;					//s是伯父结点
				if( (p == p->parent->leftChild && s == NULL) || (p == p->parent->leftChild && s != NULL && s->color == BLACK))	//p是在外侧插入并且伯父结点是黑色	/
				{
					//1
					p->parent->color = BLACK;		//改变颜色
					p->parent->parent->color = RED;	//
					RotateR(p->parent->parent);						//右转
				}
				else if( (p == p->parent->rightChild && s == NULL) || (p == p->rightChild && s != NULL && s->color == BLACK))	//p是在内测插入并且伯父结点是黑色	<
				{
					//2
					p->parent->parent->color = RED;	//改变颜色
					p->color = BLACK;
					RotateL(p->parent);		//左旋结点
					RotateR(p->parent);		//右旋结点
				}
				else if(p == p->parent->leftChild && s->color == RED)	//p是在外侧插入并且s是红色
				{
					//3
					p->color = BLACK;
					RotateR(p->parent->parent);		//一次单旋转就可以
					
					if(p->parent->parent != NULL && p->parent->parent->color == RED)
					{
						p = p->parent;		//回朔父结点
						continue;
					}
					else
						break;
				}
				else if(p == p->parent->rightChild && s->color == RED)	//p是在内侧插入并且s是红色
				{
					//4
					p->parent->color = BLACK;
					p->parent->parent->color = BLACK;
					RotateL(p->parent);
					RotateR(p->parent);
					if(p->parent != NULL && p->parent->color == RED)
					{
						continue;
					}
					else
						break;
				}
			}
			else if(p->parent == p->parent->parent->rightChild)
			{
				s = p->parent->parent->leftChild;
				if( (p == p->parent->rightChild && s == NULL) || (p == p->parent->rightChild && s != NULL) && s->color == BLACK)			//p是在外侧插入并且伯父结点是黑色
				{
					p->parent->color = BLACK;
					p->parent->parent->color = RED;
					RotateL(p->parent->parent);
				}
				else if( (p == p->parent->leftChild && s == NULL) || (p == p->leftChild && s != NULL && s->color == BLACK)) 			//p是在内测插入并且伯父结点是黑色
				{
					p->parent->parent->color = RED;
					p->color = BLACK;
					RotateR(p->parent);
					RotateL(p->parent);
				}
				else if(p == p->parent->rightChild && s->color == RED)
				{
					p->color = BLACK;
					RotateL(p->parent->parent);

					if(p->parent->parent != NULL && p->parent->parent->color == RED)
					{
						p = p->parent;
						continue;
					}
					else
						break;
				}
				else if(p == p->parent->leftChild && s->color == RED)
				{
					p->parent->color = BLACK;
					p->parent->parent->color = BLACK;
					RotateR(p->parent);
					RotateL(p->parent);
				}
			}
		}
		t->color = BLACK;
	}
*/
private:
	void RotateR(RBTreeNode<T> * ptr)		//右旋函数
	{
		RBTreeNode<T> *subR = ptr;		//右结点
		ptr = ptr->leftChild;			//新的根结点
		subR->leftChild = ptr->rightChild;	//ptr成为新根前处理其右边的结点
		if(ptr->rightChild != NULL)			//如果ptr的右子女结点存在
			ptr->rightChild->parent = subR;
		if(subR->parent == NULL)
			root = ptr;
		else
		{
			if(subR == subR->parent->leftChild)	//subR为父结点的的左子树
				subR->parent->leftChild = ptr;
			else
				subR->parent->rightChild = ptr;
		}
		ptr->parent = subR->parent;			//将父结点连接起来
		ptr->rightChild = subR;				//ptr成为新结点
		subR->parent = ptr;
	}
	void RotateL(RBTreeNode<T> *ptr)	//左旋函数
	{
		RBTreeNode<T> *subL = ptr;		//左结点
		ptr = ptr->rightChild;			//新到的根节点
		subL->rightChild = ptr->leftChild;	//ptr成为新根前处理其左边的结点
		if(ptr->leftChild != NULL)			//如果ptr的左结点存在 连接其父结点
			ptr->leftChild->parent = subL;
		if(subL->parent == NULL)			//如果到达了根结点
			root = ptr;
		else
		{
			if(subL == subL->parent->leftChild)	//确定新根的位置
				subL->parent->leftChild = ptr;
			else
				subL->parent->rightChild = ptr;
		}
		ptr->parent = subL->parent;		//连接其父结点
		ptr->leftChild = subL;			//连接子女
		subL->parent = ptr;
	}
};



#endif
