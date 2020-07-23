
#include<iostream>
#define MAXSIZE 10
using namespace std;

//邻边结点
typedef struct ArcNode
{
public:
	int adjvex;  //编号
	ArcNode*next;//下一连接
}ArcNode;

//顶点
typedef struct VertexNode
{
public:
	char vertex;       //顶点值
	ArcNode* firstedge;//第一个邻边结点
}VertexNode;

//图
class ALGraph
{
public:
	ALGraph(char vertexs[], int vNum, int aNum);
	void DFS(int num);	//深度优先搜索遍历
	void DFS_Foreach();	//整个图的深度优先搜索遍历
	void BFS();			//广度优先搜索遍历
	void Foreach();
private:
	VertexNode adjlist[MAXSIZE];//顶点数组
	int vertexNum;				//顶点数
	int arcNum;					//边数
	bool visited[MAXSIZE];		//已访问结点标志数组
};
void ALGraph::Foreach()
{
	for(int i=0;i<vertexNum;i++)
	{
		cout << adjlist[i].vertex <<" ";
		ArcNode*p = adjlist[i].firstedge;
		while(p!=NULL)
		{
			cout << p->adjvex << " ";
			p = p->next;
		}
		cout << endl;
	}
}

ALGraph::ALGraph(char vertexs[],int vNum,int aNum )
{
	int i, j,k;
	vertexNum = vNum;
	arcNum = aNum;

	//初始化顶点数组
	for(i=0;i<vertexNum;i++)
	{
		adjlist[i].vertex = vertexs[i];
		adjlist[i].firstedge = NULL;
		visited[i] = false;
	}
	//初始化每个顶点的邻边结点
	for(k=0;k<arcNum;k++)
	{
		cin >> i >> j;
		ArcNode *s=new ArcNode;
		s->adjvex = j;
		s->next = adjlist[i].firstedge;
		adjlist[i].firstedge = s;
	}

}

void ALGraph::DFS(int num)
{
	if(visited[num]==false)
	{
		cout << adjlist[num].vertex << " ";
		visited[num] = true;

		ArcNode* p = adjlist[num].firstedge;//获得第一个邻边结点

		while (p!=NULL)	//遍历当前结点的所有邻边结点
		{
			if(visited[p->adjvex]==false)
			{
				DFS(p->adjvex);//递归邻边结点
			}
			p = p->next;//访问到下一邻边结点
		}
	}
}

void ALGraph::BFS()
{
	//初试化各顶点的访问标志
	for (int i = 0; i < vertexNum; i++) 
	{
		visited[i] = false;
	}
	//每个顶点进行广度优先遍历
	for(int i=0;i<vertexNum;i++)
	{
		if(visited[i]==false)//判断顶点是否已访问
		{
			int front = -1;	//队头
			int rear = -1;	//队尾
			int Q[MAXSIZE];	//队列

			Q[++rear] = i;//顶点编号入队
			
			cout << adjlist[i].vertex << " ";
			
			visited[i] = true;

			while(front!=rear)
			{
				int v = Q[++front];              //顶点出队,出队的结点作为当前结点（先访问完顶点的所有邻接结点）
				ArcNode*p = adjlist[v].firstedge;//获得当前结点的第一个邻接结点
				
				while(p!=NULL)//遍历当前结点的所有邻接结点
				{
					if(visited[p->adjvex]==false)
					{
						cout << adjlist[p->adjvex].vertex << " ";
						visited[p->adjvex] = true;
						Q[++rear] = p->adjvex;//邻接结点编号入队
					}
					p = p->next;
				}
			}
		}
	}
}

void ALGraph::DFS_Foreach() {
	//初试化各顶点的访问标志
	for (int i = 0; i < vertexNum; i++)
	{
		visited[i] = false;
	}
	//遍历所有未访问过的顶点 (防止图不连通，导致一些顶点没被遍历) 
	for (int i = 0; i < vertexNum; i++)
	{
		DFS(i);
	}
	cout << endl;
}

int main()
{
	char vertex[MAXSIZE];
	int vertexNum, arcNum;
	cin >> vertexNum >> arcNum;

	for (int i = 0; i < vertexNum; i++)
	{
		cin >> vertex[i];
	}


	ALGraph a(vertex, vertexNum, arcNum);
	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << " ";
	}
	cout << endl;
	a.Foreach();
	
	a.DFS_Foreach();//深度优先搜索遍历
	a.BFS();		//广度优先搜索遍历
	return 0;
}
