#include<iostream>
#define MAXSIZE  10
using namespace std;
class MGraph
{
public:
	MGraph(char ver[], int n, int e);
	void Dijkstra(int v);
	void Floyd();
	void arcForeach();
private:
	int vertexNum, arcNum;    //顶点数，边数
	char vertex[MAXSIZE];     //顶点数组
	int arc[MAXSIZE][MAXSIZE];//邻接矩阵
	int visited[MAXSIZE];     //访问标志
};


void MGraph::arcForeach()
{
	for (int x = 0; x < vertexNum; x++)
	{
		for (int y = 0; y < vertexNum; y++)
		{
			cout << arc[x][y] << " ";
			if (y == vertexNum - 1) { cout << endl; }
		}
	}
}

MGraph::MGraph(char ver[], int n, int e)
{
	int x, y, k;
	vertexNum = n;
	arcNum = e;

	//顶点数组初始化
	for (x = 0; x < vertexNum; x++)
	{
		vertex[x] = ver[x];
		visited[x] = 0;
	}

	//初始化邻接矩阵
	for (x = 0; x < vertexNum; x++)
	{
		for (y = 0; y < vertexNum; y++)
		{
			arc[x][y] = 0;
		}
	}

	//邻接矩阵赋值，对称矩阵
	for (k = 0; k < arcNum; k++)
	{
		cin >> x >> y;
		arc[x][y] = 1;
		arc[y][x] = 1;
	}
}

void MGraph::Floyd() 
{
	int A[MAXSIZE][MAXSIZE];//路径权值
	
	/*初始化*/
	for (int i = 0; i < vertexNum; i++) 
	{
		for(int j=0;j<vertexNum;j++)
		{
			A[i][j] = arc[i][j];
		}
	}

	for(int k=0;k<vertexNum;k++)
	{
		for(int i=0;i<vertexNum;i++)
		{
			for (int j = 0; j <vertexNum; j++) 
			{
				//判断当前顶点经过中转顶点k到目标顶点j的路径长度是否小于直接到目标顶点路径长度
				if(A[i][j]>A[i][k]+A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
	}
}

void MGraph::Dijkstra(int v) 
{
	int s[MAXSIZE];		//标记数组
	int path[MAXSIZE];	//顶点的前一顶点
	int dist[MAXSIZE];	//路径权值
	
	/*初始化数组*/
	for (int i = 0; i < vertexNum; i++)
	{
		dist[i] = arc[v][i];//边的权值
		s[i] = 0;			//都为无效顶点，没被s录入

		if (arc[v][i] < 10000000) //小于无穷大，为有效边
		{
			path[i] = v;//前一顶点
		}
		else 
		{
			path[i] = -1;//当前没有前一顶点
		}
		s[v] = 1;		//原点为有效顶点，被s录入
		path[v] = -1;	//原点没有前一顶点
	}


	for(int i=0;i<vertexNum;i++)
	{
		int min = 10000000;
		int u;

		/*选出从当前顶点到剩余的顶点（没被s录入）路径权值最短的顶点*/
		for(int j = 0; j < vertexNum; j++)
		{
			if(s[j]==0 && dist[j]<min)//没被s录入，比当前最短路径长度还要短
			{
				min = dist[j];
				u = j;
			}
		}

		s[u] = 1;

		/*判断新加入的顶点（s新录入）对原点通往其余顶点是否有更短路径*/
		for (int j = 0; j < vertexNum; j++) 
		{
			//dist[u]为到顶点u的权值，arc[u][j]为顶点u到顶点j的权值，u作为中转站判断是否比dist[j]权值要小
			if(s[j]==0 && dist[u] + arc[u][j] < dist[j])//新加入的顶点，更改路径，判断是否有原点通往顶点j更短的路径
			{
				dist[j] = dist[u] + arc[u][i];
				path[j] = u;
			}
		}
	}
}

int main()
{

	char vertex[MAXSIZE];
	int vertexNum, arcNum;
	cin >> vertexNum>> arcNum;
	
	for (int i = 0; i < vertexNum; i++)
	{

		cin >> vertex[i];
	}
	
	
	MGraph a(vertex, vertexNum, arcNum);
	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;
	a.arcForeach();

	return 0;
}
