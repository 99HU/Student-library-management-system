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
        printf("��ȡ������Ϣʧ��\n");
        return;
    }
    else
    {
    	printf("��ȡ������Ϣ�ɹ�\n");
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
		printf("��ȡ������Ϣʧ��\n");
		return;
	}
	else
	{
		printf("��ȡ������Ϣ�ɹ�\n");
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
	    printf("�ڽӾ���ת���ڽӱ�ʧ��\n");
		return ;	
	}
	else
	{
		printf("�ڽӾ���ת���ڽӱ�ɹ�\n");
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
	printf("������ȫ����У԰������Ϣ\n");
	for(int i=0;i<g.n;i++)
	{
		printf("%d:%s\n %s\n",g.point[i].number,g.point[i].name,g.point[i].information);
	}
}
void search(map g)
{
	int a,b,d=0;
	char c[20];
	printf("��ѡ����ҷ�ʽ\n");
	printf("1.����Ų���\t2.�����Ʋ���\n");
	scanf("%d",&a);
	if(a==1)
	{
		printf("��������Ҫ���Ҿ�����Ϣ�����\n");
		scanf("%d",&b);
		if(b>19||b<0)
		{
			printf("û���ҵ�����ŵľ�����Ϣ\n");
		}
		else
		{
			printf("%d:%s\n %s\n",g.point[b].number,g.point[b].name,g.point[b].information);
		}
	 } 
	else if(a==2)
	{
		printf("��ѡ����Ҫ���ҵľ�����Ϣ������\n"); 
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
			printf("û���ҵ������Ƶľ�����Ϣ\n");
		}
	}
	else
	{
		printf("�������\n");
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
	printf("��ѡ����ҷ�ʽ\n");
	printf("1.����Ų���\t2.�����Ʋ���\n");
	scanf("%d",&a);
	if(a==1)
	{
No:		printf("���������ʼλ�õ����\n");
		scanf("%d",&b);
		printf("�������㵽��λ�õ����\n"); 
		scanf("%d",&b1);
		if(b1>19||b1<0||b>19||b<0)
		{
			printf("���������Ϣ����\n");
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
                		printf("��%d��%d�����·��Ϊ��",b,b1);
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
						printf("·������Ϊ%d\n",dist[i][j]);
					}
				}
			}
		}
	 } 
	else if(a==2)
	{
NO1:		printf("���������ʼλ�õ�����\n");
		scanf("%s",c);
		printf("�������㵽��λ�õ�����\n"); 
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
			printf("���������Ϣ����\n");
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
                		printf("��%s��%s�����·��Ϊ��",c,c1);
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
						printf("·������Ϊ%d\n",dist[i][j]);
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
	printf("����������ѡ����Ҫ���еĲ���\n");
	printf("1.���У�ھ������������Լ����\n");
	printf("2.�����ƺ���Ų���ѧУ�ھ���ļ��\n");
	printf("3.�������������·��\n");
	printf("4.��������������·��\n");
	printf("5.�˳�ϵͳ\n");
}
/*void findbestway(map g)
{
	
}*/
int main ()
{
	int s,x;
	int o;
	printf("��ӭ����У԰����ϵͳ\n");
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
    	printf("��ѡ����ҷ�ʽ\n");
	    printf("1.����Ų���\t2.�����Ʋ���\n");
	    scanf("%d",&a);
	    if(a==1)
	    {
        No2:	printf("���������ʼλ�õ����\n");
		    scanf("%d",&b);
			printf("�������㵽��λ�õ����\n"); 
			scanf("%d",&b1);
			if(b1>19||b1<0||b>19||b<0)
			{
				printf("���������Ϣ����\n");
				goto No2;
			}
			else
	    	{
		        findallway (g,G,b,b1,path1,-1);	    		    
	    	} 
	    }
	    else if(a==2)
		{
	    NO3:	printf("���������ʼλ�õ�����\n");
			scanf("%s",c);
			printf("�������㵽��λ�õ�����\n"); 
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
				printf("���������Ϣ����\n");
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
		printf("�������\n");
		goto Start;
	}
	return 0;
} 
