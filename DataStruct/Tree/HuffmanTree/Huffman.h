#ifndef _HUFFMAN_H
#define	_HUFFMAN_H

#include"../heap/MinHeap.h"

const int DefaultSize = 20;			//缺省权值集合
struct	HuffmanNode					//树结点的类定义
{
	float			data;					//结点数据
	HuffmanNode		*leftChild,*rightChild,*parent;			//左右子女和父结点指针
	HuffmanNode():leftChild(NULL),rightChild(NULL),parent(NULL)		//构造函数
	{}
	HuffmanNode(float elem,HuffmanNode *left = NULL,HuffmanNode *right = NULL,HuffmanNode *pr = NULL):data(elem),leftChild(left),rightChild(right),parent(pr)			//构造函数
	{}
	bool operator <= (HuffmanNode& R)
	{
		return data <= R.data;
	}
	bool operator > (HuffmanNode& R)
	{
		return data > R.data;
	}
};

class HuffmanTree			//Huffman树类定义
{
public:
	HuffmanTree(float w[],int n);		//构造函数
	~HuffmanTree()						//析构函数
	{
		delete Tree(root);
	}
protected:
	HuffmanNode* root;					//Huffman树的根
	void deletetree(HuffmanNode *t);	//删除以t为根的子树
	void mergeTree(HuffmanNode& ht1,HuffmanNode& ht2,HuffmanNode * &parent)
};

HuffmanTree::HuffmanTree(float w[],int n)		//给出n个权值w[1]~w[n]，构造Huffman树
{
	MinHeap	hp;			//使用最小堆存放森林
	HuffmanNode *parent,first,second,work;
	for(int i = 0; i < n; ++i)	//森林各棵树初始化
	{
		work.data = w[i];
		work.leftChild = NULL;
		work.rightChild = NULL;
		work.parent = NULL;
		hp.Insert(work);		//插入到最小堆中
	}
	for(i = 0; i < n-1; ++i)	//做n-1趟，形成Huffman树
	{
		hp.RemoveMin(first);	//选择根的权值最小的树
		hp.RemoveMin(second);	//选择根的权值次小的树
		mergeTree(first,second,parent);	//合并
		hp.Insert(*parent);			//重新插入到最小数中去
	}
	root = parent;		//建立根结点
}

HuffmanTree::mergeTree(HuffmanNode *bt1,HuffmanNode *bt2,HuffmanNode *& parent)
{
	parent = new HuffmanNode;
	parent->leftChild = &bt1;
	parent->rightChild = &bt2;
	parent->data = bt1.root->data+bt2.root->data;
	bt1.root->parent = bt2.root->parent = parent;
}

#endif
