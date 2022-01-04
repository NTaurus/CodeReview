#include <iostream>
using namespace std;
#define maxn 100
typedef int ElemType;
typedef struct Edge
{
    int adjvex; //邻接顶点
    int cost;   //边权
    struct Edge *next;
} EdgeNode;
typedef struct VNode
{
    EdgeNode *head;
    ElemType val; //顶点信息
} VertexNode, AdjList[maxn];

typedef struct Graph
{
    AdjList vertices; //顶点集合
    int Enum, Vnum;
} Graph;

/*
    无向图
*/
// typedef struct vnode{
//     Elemtype vertice_info;
// }VList[maxn];
// typedef struct MGraph{
//     VList vertices;
//     int Edge[maxn][maxn];
//     int Enum,Vnum;
// }Graph;

void Copy(Graph &A, Graph &B)
{
    B.Enum=A.Enum;
    B.Vnum=A.Vnum;
    // A.Vnum是顶点的个数
    for (int i = 0; i < A.Vnum; i++)
    {
        //复制顶点i的信息
        B.vertices[i].val = A.vertices[i].val;
        //生成头结点，（为了操作方便，链表带头结点）
        B.vertices[i].head = new Edge();
        // pre指向图B的顶点i的头结点
        Edge *pre = B.vertices[i].head;
        //遍历A图中链表i，p指向A的顶点为i的链表的第一条边
        for (EdgeNode *p = A.vertices[i].head->next; p != NULL; p = p->next)
        {
            //生成新的边
            Edge *e = new Edge();
            //复制边的另一边的顶点信息（相邻的顶点）
            e->adjvex = p->adjvex;
            //将pre->next指向刚生成的边,将链表连起来（参考尾插法）
            pre->next = e;
            // pre指向表尾，让pre始终指向链表的尾结点
            pre = e;
        }
        //最后将链表的尾结点的next指向NULL
        pre->next = NULL;
    }
}
void Print(Graph G)
{
    for (int i = 0; i < G.Vnum; i++)
    {
        printf("与顶点%d相邻的顶点有：\n", G.vertices[i].val);
        for (Edge *p = G.vertices[i].head->next; p != NULL; p = p->next)
        {
            cout << G.vertices[p->adjvex].val << ' ';
        }
        cout << endl;
    }
}
void Create(Graph &G)
{
    cin >> G.Vnum >> G.Enum;
    //添加图的顶点信息，并生成头结点
    for (int i = 0; i < G.Vnum; i++)
    {
        int val=i;
        // cin >> val;
        G.vertices[i].val = val;
        G.vertices[i].head = new Edge();
        G.vertices[i].head->next = NULL;
    }
    //创建图的边，采用头插法插入
    for (int i = 0; i < G.Enum; i++)
    {
        int u, v;
        cin >> u >> v;
        Edge *e = new Edge();
        e->adjvex = v;
        e->next = G.vertices[u].head->next;
        G.vertices[u].head->next = e;
    }
}

int main()
{
    Graph G;
    Create(G);
    Print(G);
    cout<<"```````````````````"<<endl;
    Graph B;
    Copy(G,B);
    Print(B);
    return 0;
}
// typedef struct Edge{
//     Edge *next;//
//     int w;//边权
//     int adjvex;//临界顶点
// }Edge;
// typedef struct AGraph{
//     int Vertix[maxn];//顶点表
//     int Enum,Vnum;//边、顶点的个数
// }AGraph;