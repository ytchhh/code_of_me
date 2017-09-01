#pragma once

/*
	带权无向图
*/
#include<iostream>
using namespace std;

const int DefaultVertices = 30;			//默认最大顶点数(=n)

/*
template<class T,class E>
class Graph;

template<class T,class E>
istream& operator >> (istream& in,Graph<T,E>& G);	//输入

template<class T,class E>
ostream& operator << (ostream& out,Graph<T,E>& G);	//输出
*/

template<class T,class E>
class Graph								//图的类定义
{
	friend istream& operator >> (istream& in,Graph<T,E>& G);	//输入
	friend ostream& operator << (ostream& out,Graph<T,E>& G);	//输出
public:
	const E maxWeight = 200000;			//代表无穷大的值
	Graph(int sz = DefaultVertices)		//构造函数
	{}
	~Graph()							//析构函数
	{}
	bool GraphEmpty()const				//判图空否
	{
		if(numEdges == 0)
			return true;
		else
			return false;
	}
	bool GraphFull()const			//判图满否
	{
		if(numVertices == maxVertices || numEdges == maxVertices*(maxVertices-1)/2)
			return true;
		else
			return false;

	}
	int NumberOfVertices()			//返回当前顶点数
	{
		return numVertices;
	}
	int NumberOfEdges()				//返回当前边数
	{
		return numEdges;
	}

	virtual T getValue(int i) = 0;			//取边(v1,v2)上的权值
	virtual E getWeight(int v1,int v2) = 0;		//返回当前边数
	virtual int getFirstNeighbor(int v)	 = 0;//取顶点v的第一个邻接顶点
	virtual int getNextNeighbor(int v,int w) = 0;		//取顶点w的下一个邻接顶点
	virtual bool insertVertex(const T& vertex) = 0;			//插入一个顶点vertex
	virtual bool insertEdge(int v1,int v2,E cost) = 0;		//插入边(v1,v2)，权为cost
	virtual bool removeVertex(int v) = 0;			//删除顶点v和所有与其相关联边
	virtual bool removeEdge(int v1,int v2) = 0;		//在图中删除边(v1,v2)
protected:
	int maxVertices;						//图中最大顶点数
	int numEdges;							//当前边数
	int numVertices;						//当前顶点数
	virtual int getVertexPos(T vertex) = 0;		//给出顶点vertex在图中的位置
};

