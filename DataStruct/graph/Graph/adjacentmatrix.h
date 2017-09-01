#pragma once


#include "./graph.h"

template<class T,class E>
class Graphmatrix;

template<class T,class E>
istream& operator >> (istream& in,Graphmatrix<T,E>& G);	//输入

template<class T,class E>
ostream& operator << (ostream& out,Graphmatrix<T,E>& G);	//输出


template<class T,class E>
class Graphmatrix:public Graph<T,E>		//图的邻接矩阵定义
{
	friend istream& operator >> (istream& in,Graphmatrix<T,E>& G)	//输入
	{
			int i,j,k,n,m;
			T e1,e2;
			E weight;
			in>>n>>m;				//输入顶点数n和边数m
			for(i = 0; i < n; ++i)	//建立顶点表数据
			{
					in>>e1;
					G.insertVertex(e1);
			}
			i = 0;
			while(i < m)
			{
					in >> e1 >> e2 >> weight;
					j = G.getVertexPos(e1);
					k = G.getVertexPos(e2);
					if(j == -1 || k == -1)
					{
							cout<<"边两边端点信息有误，重新输入"<<endl;
					}
					else
					{
							G.insertEdge(j,k,weight);
							i++;
					}
			}
			return in;
	}
	friend ostream& operator << (ostream& out,Graphmatrix<T,E>& G)	//输出
	{
		int i,j,n,m;
		T e1,e2;
		E w;
		n = G.NumberOfVertices();
		m = G.NumberOfEdges();
		out << n << "," << m <<endl;
		for(i = 0; i < n; ++i)
			for(j = i+ 1; j < n; ++j)
			{
				w =G.getWeight(i,j);
				if(w > 0 && w < 20000)
				{
					e1 = G.getValue(i);
					e2 = G.getValue(j);
					out << "(" << e1 << "," << e2 << "," << w << ")" << endl;
				}
			}
		return out;
	}

protected:
	T *VerticesList;				//顶点表
	E **Edge;						//邻接矩阵 
	int getVertexPos(T vertex)		//给出顶点vertex在图中的位置
	{
		for(int i = 0; i < Graph<T,E>::numVertices; ++i)
			if(VerticesList[i] == vertex)
				return i;
		return -1;
	}
public:
	Graphmatrix(int sz = DefaultVertices);		//构造函数
	~Graphmatrix()
	{
		delete []VerticesList;
		delete []Edge;
	}
	T getValue(int i)				//取顶点i的值，i不合理返回0
	{
		return i >= 0 && i <= Graph<T,E>::numVertices ? VerticesList[i] : 0;
	}
	E getWeight(int v1,int v2)		//取边(v1,v2)的第一个邻接顶点
	{
		return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
	}
	int getFirstNeighbor(int v);		//取顶点v的第一个邻接顶点
	int getNextNeighbor(int v,int w);		//取v得邻接顶点w的下一个邻接顶点
	bool insertVertex(const T& vertex);		//插入顶点vertex
	bool insertEdge(int v1,int v2,E cost);	//插入边(v1,v2),权值为cost
	bool removeVertex(int v);				//删去顶点v和所有和它相关联的边
	bool removeEdge(int v1,int v2);			//在图中删除边(v1,v2)
};

/*
template<class T,class E>
istream& operator >> (istream& in,Graphmatrix<T,E>& G)	//输入
{
	int i,j,k,n,m;
	T e1,e2;
	E weight;
	in>>n>>m;				//输入顶点数n和边数m
	for(i = 0; i < n; ++i)	//建立顶点表数据
	{
		in>>e1;
		G.insertVertex(e1);
	}
	i = 0;
	while(i < m)
	{
		in >> e1 >> e2 >> weight;
		j = G.getVertexPos(e1);
		k = G.getVertexPos(e2);
		if(j == -1 || k == -1)
		{
			cout<<"边两边端点信息有误，重新输入"<<endl;
		}
		else
		{
			G.insertEdge(j,k,weight);
			i++;
		}
	}
	return in;
}

template<class T,class E>
ostream& operator << (ostream& out,Graphmatrix<T,E>& G)	//输出
{
	int i,j,n,m;
	T e1,e2;
	E w;
	n = G.NumberOfVertices();
	m = G.NumberOfEdges();
	out << n << "," << m <<endl;
	for(i = 0; i < n; ++i)
		for(j = i+ 1; j < n; ++j)
		{
			w =G.getWeight(i,j);
			if(w > 0 && w < Graph<T,E>::maxWeight)
			{
				e1 = G.getValue(i);
				e2 = G.getValue(j);
				out << "(" << e1 << "," << e2 << "," << w << ")" << endl;
			}
		}
	return out;
}

*/
template<class T,class E>
Graphmatrix<T,E>::Graphmatrix(int sz)					//构造函数
{
	Graph<T,E>::maxVertices = sz;
	Graph<T,E>::numVertices = 0;
	Graph<T,E>::numEdges = 0;
	int i,j;
	VerticesList = new T[Graph<T,E>::maxVertices];		//创建顶点表数组
	Edge = (E**) new E*[Graph<T,E>::maxVertices];		//创建邻接矩阵数组
	for(i = 0; i < Graph<T,E>::maxVertices; ++i)
		Edge[i] = new E[Graph<T,E>::maxVertices];
	for(i = 0; i < Graph<T,E>::maxVertices; ++i)		//邻接矩阵初始化
		for(j = 0; j < Graph<T,E>::maxVertices; ++j)
			Edge[i][j] = (i == j) ? 0 : Graph<T,E>::maxWeight;

}

template<class T,class E>
int Graphmatrix<T,E>::getFirstNeighbor(int v)		//取顶点v的第一个邻接顶点
{
	if(v != -1)
	{
		for(int col = 0; col < Graph<T,E>::numVertices; ++col)
			if(Edge[v][col] > 0 && Edge[v][col] < Graph<T,E>::maxWeight)
				return col;
	}
	return -1;
}

template<class T,class E>
int Graphmatrix<T,E>::getNextNeighbor(int v,int w)		//取v得邻接顶点w的下一个邻接顶点
{
	if(v != -1 && w != -1)
	{
		for(int col = w + 1; col < Graph<T,E>::numVertices; ++col)
			if(Edge[v][col] > 0 && Edge[v][col] < Graph<T,E>::maxWeight)
				return col;
	}
	return -1;
}

template<class T,class E>
bool Graphmatrix<T,E>::insertVertex(const T& vertex)		//插入顶点vertex
{
	if(Graph<T,E>::numVertices == Graph<T,E>::maxVertices)			//顶点表满的情况
		return false;
	VerticesList[Graph<T,E>::numVertices++] = vertex;
	return true;
}

template<class T,class E>
bool Graphmatrix<T,E>::insertEdge(int v1,int v2,E cost)	//插入边(v1,v2),权值为cost
{
	if(v1 > -1 && v1 < Graph<T,E>::numVertices && v2 > -1 && v2 < Graph<T,E>::numVertices && Edge[v1][v2] == Graph<T,E>::maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = cost;
		Graph<T,E>::numEdges++;
		return true;
	}
	else
		return false;
}

template<class T,class E>
bool Graphmatrix<T,E>::removeVertex(int v)				//删去顶点v和所有和它相关联的边
{
	if(v < 0 || v >= Graph<T,E>::numVertices)			//v不在图中，不删除
		return false;
	if(Graph<T,E>::numVertices == 1)					//只剩一个顶点，不删除
		return false;
	int i,j;
	VerticesList[v] = VerticesList[Graph<T,E>::numVertices-1];		//顶点表中删除该结点
	for(i = 0; i < Graph<T,E>::numVertices; ++i)
		if(Edge[i][v] > 0 && Edge[i][v] < Graph<T,E>::maxWeight)	//减去与v相关联边数
			Graph<T,E>::numEdges--;
	for(i = 0; i < Graph<T,E>::numVertices; ++i)					//用最后一列填补第v列
		Edge[i][v] = Edge[i][Graph<T,E>::numVertices-1];
	Graph<T,E>::numVertices--;										//顶点数减1
	for(j = 0; j < Graph<T,E>::numVertices; ++j)					//用最后一行填补第v行
		Edge[v][j] = Edge[Graph<T,E>::numVertices][j];
	return true;
}

template<class T,class E>
bool Graphmatrix<T,E>::removeEdge(int v1,int v2)			//在图中删除边(v1,v2)
{
	if(v1 > -1 && v1 < Graph<T,E>::numVertices && v2 > -1 && v2 < Graph<T,E>::numVertices && Edge[v1][v2] > 0 && Edge[v1][v2] < Graph<T,E>::maxWeight)
	{
		Edge[v1][v2] = Edge[v2][v1] = Graph<T,E>::maxWeight;
		Graph<T,E>::numEdges--;
		return true;
	}
	else
		return false;
}
