#ifndef _RBTREE_H
#define _RBTREE_H

#include<iostream>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef enum{RED = 0,BLACK}COLOR;
typedef int Type;

typedef struct RBNode				//结点声明
{
	int value;					//数据域
	COLOR color;					//颜色
	struct RBNode* parent;		//父结点
	struct RBNode* left;			//左右子结点
	struct RBNode* right;
}RBNode;

typedef struct RBTree
{
	RBNode *root;			//根结点
	RBNode *NIL;			//哨兵位置
}RBTree;

RBNode* _Buynode(Type v)		//申请结点函数
{
	RBNode *s = (RBNode*)malloc(sizeof(RBNode));	//申请空间
	assert(s != NULL);
	memset(s,0,sizeof(RBNode));			//初始化
	s->value = v;
	s->color = RED;
	return s;
}

void InitRBTree(RBTree &t)		//初始化函数
{
	t.NIL = _Buynode(0);		//哨兵初始化
	t.root = t.NIL;
	t.NIL->color = BLACK;
}

void RotateL(RBTree &t,RBNode *p)		//左旋
{
	RBNode *s = p->right;			//新的根结点
	p->right = s->left;				//s成为新根前扔掉其左边结点
	if(s->left != NULL)
		s->left->parent = p;
	s->parent = p->parent;			//连接父结点
	if(p->parent == t.NIL)			//p的父亲为空
		t.root = s;					//即根结点
	else if(p == p->parent->left)	//找到其应该存在的结点
		p->parent->left = s;
	else
		p->parent->right = s;
	s->left = p;					//s成为新结点
	p->parent = s;
}

void RotateR(RBTree &t,RBNode *p)	//右旋
{
	RBNode *s = p->left;
	p->left = s->right;
	if(s->right != NULL)
		s->right->parent = p;
	s->parent = p->parent;
	if(p->parent != t.NIL)
		t.root = s;
	else if(p == p->parent->left)
		p->parent->left = s;
	else
		p->parent->right = s;
	s->right = p;
	p->parent = s;
}

void Insert_Fixup(RBTree &t,RBNode *z)	//删除调整函数
{
	RBNode *y;		//伯父结点
	while(z->parent->color == RED)		//其父结点为红色 就需要调整
	{
		if(z->parent == z->parent->parent->left)	//z的父结点是在左子树
		{
			y = z->parent->parent->right;	//伯父结点
			if(y->color == RED)			//伯父结点为红色
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
				continue;		//向上回朔
			}
			else if(z == z->parent->right)		//伯父结点为黑色并且插入的新结点是在外侧
			{
				z = z->parent;
				RotateL(t,z);
			}
			//插入节点是在内测的情况下
			z->parent->parent->color = RED;
			z->parent->color = BLACK;
			RotateR(t,z->parent->parent);
		}
		else			//z的父结点是在右子树
		{
			y = z->parent->parent->left;
			if(y->color == RED)
			{
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
				continue;
			}
			else if(z == z->parent->left)
			{
				z = z->parent;
				RotateR(t,z);
			}
			z->parent->parent->color = RED;
			z->parent->color = BLACK;
			RotateL(t,z->parent->parent);
		}
	}
	t.root->color = BLACK;
}

bool Insert(RBTree &t,Type x)		//插入函数
{
	RBNode *pr = t.NIL;
	RBNode *s = t.root;
	while(s != t.NIL)		//不是根结点 就寻找应该插入的位置
	{
		if(x == s->value)
			return false;
		pr = s;
		if(x < s->value)
			s = s->left;
		else
			s = s->right;
	}

	RBNode *q = _Buynode(x);		//申请结点
	q->parent = pr;					//连接
	q->left = t.NIL;
	q->right = t.NIL;
	q->color = RED;
	
	if(pr == t.NIL)
		t.root = q;
	else if(x < pr->value)
		pr->left = q;
	else
		pr->right = q;

		Insert_Fixup(t,q);
		return true;

}

RBNode* _Next(RBTree &t,RBNode *p)		//找到p结点对应的右边的前驱
{
	if(p != t.NIL && p->right != t.NIL)
	{
		p = p->right;
		while(p->right != t.NIL)
			p = p->left;
	}
	return p;
}

void Delete_Fixup(RBTree &t,RBNode *& x)		//删除调整平衡函数
{
	RBNode *w;
	while(x != t.root && x->color == BLACK)
	{
		if(x == x->parent->left)	//左分支
		{
			w = x->parent->right;		//w是x的兄弟结点
			if(w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RotateL(t,x->parent);
			}
			if(w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else if(w->right->color == BLACK)
			{
				w->left->color = BLACK;
				w->color = RED;
				RotateR(t,w);
				w = x->parent->right;
			}	
			// \  情况
			w->color = x->parent->color;
			x->parent->color = BLACK;
			w->right->color = BLACK;
			RotateL(t,x->parent);		//左转
			x = t.root;
		}
		else					//右分支
		{
			w = x->parent->left;	//w是x的兄弟结点
			if(w->color == RED)
			{
				w->color = BLACK;
				x->parent->color = RED;
				RotateR(t,x->parent);
			}
			if(w->left->color == BLACK && w->right->color == BLACK)
			{
				w->color = RED;
				x = x->parent;
			}
			else if(w->left->color == BLACK)
			{
				w->right->color = BLACK;
				w->color = RED;
				RotateL(t,w);
				w = x->parent->left;
			}
			w->color = x->parent->color;
			x->parent->color = BLACK;
			w->left->color = BLACK;
			RotateR(t,x->parent);
			x = t.root;
		}
	}
	x->color = BLACK;
}

bool Remove(RBTree &t,Type x)		//删除函数
{
	RBNode *p = t.root;
	RBNode *y;
	RBNode *s;
	while(p != t.NIL && p->value != x)
	{
		if(x < p->value)
			p = p->left;
		else
			p = p->right;
	}

	if(p->left != t.NIL && p->right != t.NIL)		//被删除的结点右两个子女结点
		y = _Next(t,p);								//找到内删除的结点的后继
	else
		y = p;
	
	if(y->left != t.NIL)			//如果即将删除的结点有左子女
		s = y->left;
	else							//有右子女
		s = y->right;
	
	s->parent = y->parent;			//连接父结点
	if(y->parent == t.NIL)			//要删除的结点是根结点
		t.root = s;
	else if(y == y->parent->left)
		y->parent->left = s;
	else
		y->parent->right = s;
	
	if(y != p)
		p->parent->value = y->value;			//用替换的结点的值去覆盖前面的结点
	
	if(y->color == BLACK)
		Delete_Fixup(t,s);			//恢复平衡函数
	delete y;
	return true;
}

#endif
