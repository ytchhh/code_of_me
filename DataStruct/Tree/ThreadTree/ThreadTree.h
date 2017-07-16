#ifndef _THREADTREE_H
#define _THREADTREE_H

template<class T>
struct ThreadNode		//线索二叉树的结点类
{
	int ltag,rtag;		//线索标志
	THreadNode<T> *leftChild,*rightChild;	//线索或子女指针
	T	data;		//结点中所包含数据
	ThreadNode(const T item):data(item),leftChild(NULL),rightChild(NULL),ltag(0),rtag(0)		//构造函数
	{}
};

template<class T>
class ThreadTree		//线索化二叉树类
{
protected:
	ThreadNode<T>	*root;		//树的根指针
	void createInThread(ThreadNode<T> *current,ThreadNode<T> *&pre);
	//中序遍历建立线索二叉树
	ThreadNode<T>* parent(ThreadNode<T> *t);	//寻找结点t的父结点
public:
	ThreadTree():root(NULL)		//构造函数 构造空树
	{}
	void createInThread();		//建立中序线索二叉树
	//寻找中序下第一个结点
	ThreadNode<T> *First(ThreadNode<T> *current);
	//寻找线索二叉树的最后一个结点
	ThreadNode<T> *Last(ThreadNode<T> *current);
	//寻找结点在中序下的后继结点
	ThreadNode<T> *Next(ThreadNode<T> *current);
	//寻找结点在中序下的前驱结点
	ThreadNode<T> *Prior(ThreadNode<T> *current);
	void Inorder();		//中序遍历
	void preorder();	//前序遍历
	void postorder();	//后序遍历
};

template<class T>
ThreadNode<T>* ThreadTree<T>::First(ThreadNode<T> *current)
{	//函数以返回以*current为根的中序线索二叉树中中序序列下的第一个结点
	ThreadNode<T> *p = current;
	while(p->ltag == 0)
		p = p->leftChild;		//最左下结点
	return p;
}

template<class T>
ThreadNode<T>* ThreadTree<T>::Next(ThreadNode<T> *current)
{	//函数返回在中序线索二叉树中结点Current在中序下的后继结点
	ThreadNode<T> *p = current->rightChild;
	if(current->rtag == 0)
		return First(p);	//在右子树中找中序下第一个结点
	else
		return p;		//rtag == 1 直接返回后继线索
}

template<class T>
ThreadNode<T>* ThreadTree<T>::Last(ThreadNode<T0 *current>)
{	//函数返回以current为根的中序线索二叉树中中序序列下的最后一个结点
	ThreadNode<T> *p = current;
	while(p->rtag == 0)
		p = p->rightChild;		//最右下结点
	return p;
}

template<class T>
ThreadNode<T>* ThreadTree<T>::Prior(ThreadNode<T> *current)
{//函数返回在中序线索二叉树中结点current在中序下的前驱结点
	ThreadNode<T> *p = current->leftChild;
	if(current->ltag == 0)
		return Last(p);			//在左子树中找到中序最后一个结点
	else		
		return p;			//ltag == 1,直接返回前驱线索
}

template<class T>
void ThreadTree<T>::Inorder()	//在线索化二叉树上执行中序遍历的算法
{
	ThreadNode<T> *p;
	for(p = First(root); p != NULL; p = Next(p))
		cout<<p->data;
}

template<class T>
void ThreadTree<T>::createInThread()
{	//利用中序遍历对二叉树进行中序线索化
	ThreadNode<T> *pre = NULL;		//前驱结点指针
	if(root != NULL)		//非空二叉树 线索化
	{
		createInThread(root,pre);	//中序遍历线索化二叉树
		pre->rightChild = NULL;		//后处理中序最后一个结点
		pre->rtag = 1;
	}
}

template<class T>
void ThreadTree<T>::createInThread(ThreadNode<T> *current,ThreadNode<T> *&pre)
{	//通过中序遍历，对二叉树进行线索化
	if(current == NULL)
		return;
	createInThread(current->leftChild,pre);		//递归 左子树线索化
	if(current->leftChild == NULL)		//建立当前结点的前驱线索
	{
		current->leftChild = pre;
		current->ltag = 1;
	}
	if(pre != NULL && pre->rightChild == NULL)		//建立前驱结点的后继线索
	{
		pre->rightChild = current;
		pre->rtag = 1;
	}
	pre = current;			//前驱跟上 当前指针向前遍历
	createInThread(current->rightChild,pre);	//递归，右子树线索化
}

template<class T>
void ThreadTree<T>::preorder()
{//在中序线索二叉树上实现前序遍历的算法
	ThreadNode<T> *p = root;
	while(p != NULL)
	{
		cout<<p->data;			//访问根结点
		if(p->ltag == 0)
			p = p->leftChild;	//有左子女，即为后继
		else if(p->rtag == 0)	//否则有右子女，即后继
			p = p->rightChild;
		else
		{
			while(p != NULL && p->rtag == 1)	//沿后继线索检测
				p = p->rightChild;			//知道有右子女的结点
			if(p != NULL)			//右子女即为后继
				p = p->rightChild;
		}
	}
}

template<class T>
void ThreadTree<T>::postorder()
{	//中序线索二叉树的后序遍历
	ThreadNode<T> *t = root;
	while(t->ltag == 0 || t->rtag == 0)		//寻找后序第一个结点
		if(t->ltag == 0)
			t = t->leftChild;
		else if(t->ltag == 0)
			t = t->rightChild;
	cout<<t->data;			//访问第一个结点
	ThreadNode<T> *p;
	while((p = parent(t)) != NULL)
	{
		if(p->rightChild == t || p->rtag == 1)		//*t是*p的后序后继
			t = p;
		else			//否则
		{
			t = p->rightChild;			//t移到*p的右子树
			while(t->ltag == 0 || t->rtag == 0)
				if(t->ltag == 0)
					t = t->leftChild;
				else if(t->rtag == 0)
					t = t->rightChild;
		}
		cout<<t->data;
	}
}

template<class T>
ThreadNode<T>* ThreadTree<T>::parent(ThreadNode<T> *t)
{
	ThreadNode<T> *p;
	if(t == root)
		return NULL;		//根结点无父结点
	for(p = t; p->ltag == 0; p = p->leftChild)
		;
	if(p->leftChild != NULL)
		for(p = p->leftChild; p != NULL && p->leftChild != t && p->rightChild != t; p = p->rightChild);
	if(p == NULL || p->leftChild == NULL)
	{
		for(p = t; p->rtag == 0; p = p->rightChild);
		for(p = p->rightChild; p != NULL && p->leftChild != t && p->rightChild != t; p = p->leftChild);
	}
	return p;
}
#endif
