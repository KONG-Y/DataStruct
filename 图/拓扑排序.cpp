
#include<iostream>
#define MAXSIZE 10
using namespace std;


//邻边顶点
typedef struct ArcNode
{
	int adjvex;  //编号（顶点数组索引位置）
	ArcNode*next;//下一连接顶点
}ArcNode;

//顶点
typedef struct VertexNode
{
	char vertex;		//顶点值
	int count;		//入度值
	ArcNode* firstedge;	//第一个邻边顶点
}VertexNode;

//图
class ALGraph
{
public:
	ALGraph(char vertexs[], int vNum, int aNum);
	int TopSort();			//拓扑排序
	void Foreach();			//遍历每个顶点的邻近顶点
private:
	VertexNode adjlist[MAXSIZE];	//顶点数组
	int vertexNum;			//顶点数
	int arcNum;			//边数
	bool visited[MAXSIZE];		//已访问结点标志数组
};

void ALGraph::Foreach()
{
	for(int i=0;i<vertexNum;i++)
	{
		cout << adjlist[i].vertex << " " << adjlist[i].count << endl;
		//ArcNode*p = adjlist[i].firstedge;
		//while(p!=NULL)//遍历顶点的所有邻近顶点编号
		//{
		//	cout << p->adjvex << " ";
		//	p = p->next;
		//}
		//cout << endl;
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
		adjlist[i].count = 0;
		visited[i] = false;
	}
	//初始化每个顶点的邻边结点
	for(k=0;k<arcNum;k++)
	{
		cout <<endl<< "两个顶点连接:";
		cin >> i >> j;
		ArcNode *s=new ArcNode;
		s->adjvex = j;
		s->next = adjlist[i].firstedge;	//新添加的邻边顶点的下一顶点为头顶点
		adjlist[i].firstedge = s;	//头顶点变为新添加的邻边顶点
		adjlist[j].count++;		//被连接的顶点入度+1
	}

}


int ALGraph::TopSort() {
	int i, j, n = 0;
	int stack[MAXSIZE];//栈（存放入度为0的顶点）
	int top = -1;	   //栈顶
	ArcNode *p;

	/*入度为0的顶点入栈*/
	for (i = 0; i < vertexNum; i++) 
	{
		if (adjlist[i].count == 0)//顶点入度为0 
		{
			stack[++top] = i;
		}
	}
	while (top != -1) 
	{
		i = stack[top--];	//顶点出栈
		n++;			//出栈顶点数量
		cout << i << " ";
		p = adjlist[i].firstedge;//出栈顶点的第一个邻边顶点
		
		/*出栈顶点的所有邻边顶点入度-1，并把入度为0的顶点入栈*/
		while(p!=NULL)
		{
			j = p->adjvex;//顶点编号

			(adjlist[j].count)--;//邻边顶点入度-1

			if (adjlist[j].count == 0) //入度为0的邻边顶点入栈
			{
				stack[++top] = j;
			}
			p = p->next;
		}
	}

	if (n == vertexNum) //图的所有顶点出栈
	{
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	char vertex[MAXSIZE];
	int vertexNum, arcNum;
	cout << "输入顶点数" << endl;
	cin >> vertexNum;
	cout << "输入边数" << endl;
	cin >> arcNum;

	cout << "输入顶点值(字母)" << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		cin >> vertex[i];
	}

	ALGraph a(vertex, vertexNum, arcNum);

	a.Foreach();//遍历每个顶点的入度
	cout << endl;
	a.TopSort();//拓扑排序
	return 0;
}
