#include<iostream>
#define MAXSIZE  100
using namespace std;
class MGraph
{
public:
	MGraph(char ver[], int n, int e);
	void arcForeach();
	void Prim();//普里姆算法
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
	int x, y,w, k;
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
			if(x==y)
			{
				arc[x][y] = 0;
			}
			else
			{
				arc[x][y] = 999;//无穷
			}
		}
	}

	//邻接矩阵赋值，对称矩阵
	for (k = 0; k < arcNum; k++)
	{
		cout << "输入路径和权值: ";
		cin >> x >> y >> w;
		arc[x][y] = w;
		arc[y][x] = w;
	}
}

void MGraph::Prim() 
{
	int lowcost[MAXSIZE];	//记录当前生成树到剩余顶点的最小权值
	int vset[MAXSIZE];		//邻接顶点数组
	int min;
	int k;	
	lowcost[0] = 0;//原点
	vset[0] = 0;

	//初始化
	for(int i=0;i<vertexNum;i++)
	{
		lowcost[i] = arc[0][i];
		vset[i] = 0;
	}

	for(int i=0; i<vertexNum;i++)
	{
		min = 999;
		k = 0;
		//找顶点
		for(int j=0;j<vertexNum;j++)
		{
			if(vset[j]==0&&lowcost[j]<min)//找出不在生成树且权值最小的顶点（整个树）
			{
				min = lowcost[j];//权值
				k = j;			//权值最小顶点的编号
			}
		}

		cout << k << " ";
		vset[k] = 1;//顶点加入生成树
		
		//更新数组
		for(int j=0;j<vertexNum;j++)
		{
			//邻接矩阵，顶点间没有连接的权值为无穷大
			//新加入顶点k改变生成树到剩余顶点的权值（权值更小的进行更改）
			if(vset[j]==0 && arc[k][j]<lowcost[j])
			{
				lowcost[j] = arc[k][j];
				
			}
		}

	}

}


int main()
{

	char vertex[MAXSIZE];
	int vertexNum, arcNum;
	cout << "输入顶点数:";
	cin >> vertexNum;
	cout << "输入边数:";
	cin >> arcNum;
	
	cout << "输入顶点"<<endl;
	for (int i = 0; i < vertexNum; i++)
	{
		cin >> vertex[i];
	}
	
	
	MGraph a(vertex, vertexNum, arcNum);
	
	a.arcForeach();
	cout << endl;
	a.Prim();
	return 0;
}
