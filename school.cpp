#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5000
int M=20;
int i,k,j,w;
int path[19][19],dist[19][19] ;
int path1[19];
typedef struct dian {
	int number;
	char name[20];
	char information[100];
}; 
typedef struct map{
	int n ,e;
	dian point [19];
	int edges[19][19];
};
typedef struct node{
	int adjvex;
	node *next; 
};
typedef struct Vnode{
	char name[20];
    node *firstedge;
};
typedef struct linkgraph
{
	int n,e;
	Vnode adjvex[19];
};
map g;
linkgraph G;
void readpoint(map g)
{
	FILE *fp=NULL;
	if ((fp=fopen("F:\\information.txt", "r"))==NULL)
    {
        printf("读取景物信息失败\n");
        return;
    }
    else
    {
    	printf("读取景物信息成功\n");
    	i=0;
    	do{
		      fscanf(fp,"%d %s %s\n",&g.point[i].number,g.point[i].name,g.point[i].information); 
		      i++;
	    }while(i<M);
	} 
    fclose(fp);
    return;
}
void readedges(map g)
{
	FILE *fp=NULL;
	if((fp=fopen("F:\\edges.txt","r"))==NULL)
	{
		printf("读取距离信息失败\n");
		return;
	}
	else
	{
		printf("读取距离信息成功\n");
		fscanf(fp,"%d %d",&g.n,&g.e);
		for(i=0;i<g.n;i++)
		{
			for(j=0;j<g.n;j++)
			{
				if(i==j)
				g.edges[i][j]=0;
				else
				g.edges[i][j]=MAX;
			}
		}
		for(k=0;k<g.e;k++)
		{
			fscanf(fp,"%d %d %d",&i,&j,&k);
			g.edges[i][j]=k;
			g.edges[j][i]=k;
		}
	}
	fclose(fp);
	return;
}
void creatlinkgraph(map g,linkgraph G)
{
	FILE *fp=NULL;
	node *s;
	if((fp=fopen("F:\\linkgraph.txt","r"))==NULL)
	{
	    printf("邻接矩阵转换邻接表失败\n");
		return ;	
	}
	else
	{
		printf("邻接矩阵转换邻接表成功\n");
	    for(i=0;i<g.n;i++)
	    {
	        G.adjvex[i].firstedge=NULL;	
	        fscanf(fp,"%s\n",G.adjvex[i].name);
	    }
	    fscanf(fp,"%d %d",&G.n,&G.e);
	    for(k=0;k<g.e;k++)
	    {
		    fscanf(fp,"%d %d",&i,&j);
		    s=(node *)malloc(sizeof(node));
		    s->adjvex=j;
		    s->next=G.adjvex[i-1].firstedge;
		    G.adjvex[i-1].firstedge=s;
		    s=(node *)malloc(sizeof(node));
		    s->adjvex=i;
		    s->next=G.adjvex[j-1].firstedge;
		    G.adjvex[j-1].firstedge=s;
    	}		
	}
	fclose(fp);    
}
void show(map g)
{
	printf("以下是全部的校园景物信息\n");
	for(int i=0;i<g.n;i++)
	{
		printf("%d:%s\n %s\n",g.point[i].number,g.point[i].name,g.point[i].information);
	}
}
void search(map g)
{
	int a,b,d=0;
	char c[20];
	printf("请选择查找方式\n");
	printf("1.按序号查找\t2.按名称查找\n");
	scanf("%d",&a);
	if(a==1)
	{
		printf("请输入你要查找景物信息的序号\n");
		scanf("%d",&b);
		if(b>19||b<0)
		{
			printf("没有找到该序号的景物信息\n");
		}
		else
		{
			printf("%d:%s\n %s\n",g.point[b].number,g.point[b].name,g.point[b].information);
		}
	 } 
	else if(a==2)
	{
		printf("请选择你要查找的景物信息的名称\n"); 
		scanf("%s",c);
		for(i=0;i<g.n;i++)
		{
			if(strcmp(c,g.point[i].name)==0)
			{
				printf("%d:%s\n %s\n",g.point[b].number,g.point[b].name,g.point[b].information);
				d=1;
			}
		}
		if(d==0)
		{ 
			printf("没有找到该名称的景物信息\n");
		}
	}
	else
	{
		printf("输入错误\n");
	}
}
void important (map g, int path [19][19],int dist[19][19])
{
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
		{
			dist[i][j]=g.edges[i][j];
			if(i!=j&&dist[i][j]<MAX)
			{
				path[i][j]=i;
			}
			else
			{
				path[i][j]=-1;
			}
		}
	}
	for(k=0;k<g.n;k++)
	{
		for(i=0;i<g.n;i++)
		{
			for(j=0;j<g.n;j++)
			{
				if(dist[i][j]<dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=k;
				}
			}
		}
	 } 
}
void findshortway(map g,int path[19][19] ,int dist [19][19]){
	int a,b,b1,d=0,d1=0;
	char c[20],c1[20];
	int apath[19],f,s,u,v;
	printf("请选择查找方式\n");
	printf("1.按序号查找\t2.按名称查找\n");
	scanf("%d",&a);
	if(a==1)
	{
No:		printf("请输入你初始位置的序号\n");
		scanf("%d",&b);
		printf("请输入你到达位置的序号\n"); 
		scanf("%d",&b1);
		if(b1>19||b1<0||b>19||b<0)
		{
			printf("你输入的信息有误\n");
			goto No;
		}
		else
		{
			
            for(i=0;i<g.n;i++)
            {
                for(j=0;j<g.n;j++)
                {
                	if(dist[i][j]!=MAX&&i!=j&&b==i&&b1==j)
                	{
                		printf("从%d到%d的最短路径为：",b,b1);
                		k=path[i][j];
                		f=0;
                		apath[d]=j;
                		while(k!=-1&&k==i)
                		{
                			f++;
                			apath[f]=k;
                			k=path[i][k];
						}
						f++;
						apath[f]=i;
						printf("%d",g.point[apath[f]].number);
						for(s=f-1;s>=0;s--)
						{
							printf("->%d",g.point[apath[s]].number);
						}
						printf("\n");
						printf("路径长度为%d\n",dist[i][j]);
					}
				}
			}
		}
	 } 
	else if(a==2)
	{
NO1:		printf("请输入你初始位置的名称\n");
		scanf("%s",c);
		printf("请输入你到达位置的名称\n"); 
		scanf("%s",c1);
		for(i=0;i<g.n;i++)
		{
			if(strcmp(c,g.point[i].name)==0)
			{
				d=1;
			}
			else if(strcmp(c1,g.point[i].name)==0)
			{
				d1=1;
			}
		}
		if(d==0||d1==0)
		{
			printf("你输入的信息有误\n");
			goto NO1;
		 }
		 else
		 {
		 	for(i=0;i<g.n;i++)
		 	{
		 		if(strcmp(c,g.point[i].name)==0)
		 		{
		 			u=i;
				 }
				 if(strcmp(c1,g.point[i].name)==0)
				 {
				 	v=i;
				 }
			 }
		 	  for(i=0;i<g.n;i++)
            {
                for(j=0;j<g.n;j++)
                {
                	if(dist[i][j]!=MAX&&i!=j&&u==i&&v==j)
                	{
                		printf("从%s到%s的最短路径为：",c,c1);
                		k=path[i][j];
                		f=0;
                		apath[f]=j;
                		while(k!=-1&&k==i)
                		{
                			f++;
                			apath[d]=k;
                			k=path[i][k];
						}
						f++;
						apath[f]=i;
						printf("%s",g.point[apath[f]].name);
						for(s=d-1;s>=0;s--)
						{
							printf("->%s",g.point[apath[s]].name);
						}
						printf("\n");
						printf("路径长度为%d\n",dist[i][j]);
					}
				}
			}
		} 
    }
}
void findallway (map g,linkgraph G ,int u,int v,int path1[],int d)
{
	int visited[19];
	int w;
	node *p;
	visited[u]=1;
	d++;
	path1[d]=u;
	if(u==v&&d>=1)
    {
        printf(" ");
        for(i=0; i<d; i++)
        {
		    printf("%s->",g.point[path1[i]].name);
		} 
        printf("%s\n",g.point[path1[i]].name);
    }
    p=G.adjvex[u].firstedge;
    while(p!=NULL)
    {
        w=p->adjvex;
        if(visited[w]==0)
            findallway(g,G,w,v,path1,d);
        p=p->next;
    }
    visited[u]=0;
}
void shuchu (map g)
{
	for(i=0;i<g.n;i++)
	{
		printf("%d %s %s\n",g.point[i].number,g.point[i].name,g.point[i].information);
	}
}
void menu()
{
	printf("请输入数字选择你要进行的操作\n");
	printf("1.输出校内景物的序号名称以及简介\n");
	printf("2.按名称和序号查找学校内景物的简介\n");
	printf("3.查找两点间的最短路径\n");
	printf("4.查找两点间的所有路径\n");
	printf("5.退出系统\n");
}
/*void findbestway(map g)
{
	
}*/
int main ()
{
	int s,x;
	int o;
	printf("欢迎来到校园导游系统\n");
	creatlinkgraph(g,G);
	readpoint(g);
	readedges(g);
	show(g);
Start:	menu();
	scanf("%d",&o);
	if(o==1)
	{
		shuchu(g);
		goto Start;
	}
	else if(o==2)
	{
		search(g);
		goto Start;
	}
	else if(o==3)
	{
		important(g,path,dist);
		findshortway(g,path,dist);
		goto Start;
	}
	else if(o==4)
	{
		int a,b,b1,d,d1;
	    char c[20],c1[20];
    	printf("请选择查找方式\n");
	    printf("1.按序号查找\t2.按名称查找\n");
	    scanf("%d",&a);
	    if(a==1)
	    {
        No2:	printf("请输入你初始位置的序号\n");
		    scanf("%d",&b);
			printf("请输入你到达位置的序号\n"); 
			scanf("%d",&b1);
			if(b1>19||b1<0||b>19||b<0)
			{
				printf("你输入的信息有误\n");
				goto No2;
			}
			else
	    	{
		        findallway (g,G,b,b1,path1,-1);	    		    
	    	} 
	    }
	    else if(a==2)
		{
	    NO3:	printf("请输入你初始位置的名称\n");
			scanf("%s",c);
			printf("请输入你到达位置的名称\n"); 
			scanf("%d",c1);
			for(i=0;i<g.n;i++)
			{
				if(strcmp(c,g.point[i].name)==0)
				{
					d=1;
					i=s;
				}
				else if(strcmp(c1,g.point[i].name)==0)
				{
					d1=1;
					i=x;
				}
			}
			if(d==0||d1==0)
			{
				printf("你输入的信息有误\n");
				goto NO3;
			}
			else
			{
		        findallway (g,G,s,x,path1,-1);	
			}
		}
		goto Start;
	}
	else if(o==5)
	{
		return 0;
	}
	else
	{
		printf("输入错误\n");
		goto Start;
	}
	return 0;
} 
