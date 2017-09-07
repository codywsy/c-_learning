/* 邻接矩阵存储的图 – BFS（C语言实现） */
/* 邻接矩阵的初步定义 */
#define  MaxVertexNum  100      /* 最大顶点数设为100 */
#define  INFINITY  65535     /* ∞设为双字节无符号整数的最大值65535*/
typedef  char  VertexType;      /* 顶点类型设为字符型 */
typedef  int  EdgeType;         /* 边的权值设为整型 */
enum GraphType { DG, UG, DN, UN };  
/* 有向图,无向图,有向网图,无向网图*/
  
typedef  struct {
    VertexType  Vertices[ MaxVertexNum ];  /* 顶点表 */
    EdgeType  Edges[ MaxVertexNum ][ MaxVertexNum ]; 	/* 邻接矩阵，即边表  */
    int  n, e;   /* 顶点数n和边数e */
    enum GraphType GType;   /* 图的类型分4种：UG、DG、UN、DN */
} MGraph;    /* MGragh是以邻接矩阵存储的图类型 */
  



void  BFS ( MGraph G )
{   /* 按广度优先遍历图G。使用辅助队列Q和访问标志数组Visited */
    Queue  *Q;    
    VertexType  U, V, W;
    for ( U = 0; U < G.n; ++U )  
       Visited[U] = FALSE;
    Q = CreatQueue( MaxSize ); /* 创建空队列Q */
    for ( U = 0; U<G.n; ++U )
       if ( !Visited[U] ) { /* 若U尚未访问 */
           Visited[U] = TRUE; 
           printf( "visit vertex: %c\n", G.Vertices[U] );
           /* 相当于访问顶点U */
           AddQ (Q, U);    /* U入队列 */
           while ( ! IsEmptyQ(Q) ) {
              V = DeleteQ( Q );  /*  队头元素出队并置为V */
              for( W = FirstAdjV(G, V);  W;  W = NextAdjV(G, V, W) )
                  if ( !Visited[W] ) {
                     Visited[W] = TRUE;
                     printf( "visit vertex: %c\n", G.Vertices[W] );
                     /* 相当于访问顶点W */
                     AddQ (Q, W);
                  }
           } /* while结束*/
} /* 结束从U开始的BFS */
}
  
/* FirstAdjV(G, V)和NextAdjV(G, V, W)请自己练习实现。*/
int FirstAdjV(MGraph G, int V)	//输入的G是完整的图存储，输入的V是目标点的顶点号，返回的是图的结点的顶点号
{
	int j, temp;
	for( j = 0; j < G->n; j++ )
		if( G->Edges[V][j] != 0 ){
			temp=j;
		}	
	return j;
	
}

int NextAdjV(int G, int V, int W)
{
	
	
	
}