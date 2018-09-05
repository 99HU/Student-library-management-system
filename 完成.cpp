#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define Size sizeof(struct student)
using namespace std;
int number=0;
//学生结构体
typedef struct student
{
	int studentnumber;//学号
	int dormitrynumber;//宿舍号
	int bednumber;//床号
	char name[10];//名字
	char sex;//性别
	int age;//年龄
	struct student *next;
};
int length (student *head); 
void pai(student *head);
void add(student *head);
void shanchu(student *head, int pos);
void search(student *head, int studentnumber);
void change(student *head, int pos);
void show(student *head);
void addtxt(student *head);
void taketxt(student *head);
void use(student *head);
void menu();
int main()
{
    printf("\t欢迎来到宿舍管理系统\n");
  	menu();
	int a;
	student *head;
	head=(student *)malloc(Size);
	head->next=NULL;
	taketxt(head);
	use(head);
	return 0;
}
//增加动态链表的节点
void add(student *head)
{
	student *q,*p;
	q=head;
    while(q->next!=NULL)
    {
    	q=q->next;
	}
	p=(student *)malloc(Size);
	if(p!=NULL)
	{
		q->next=p;
		printf("请依次输入你的姓名 年龄 性别 学号 宿舍号 床号\n");
		printf("例：胡文胜 19 M 1707004425 221 3中间加空格\n");
		scanf("%s %d %c %d %d %d",p->name,&p->age,&p->sex,&p->studentnumber,&p->dormitrynumber,&p->bednumber);
		p->next =NULL;
		number++;
	}
	else
	{
		printf("申请空间失败\n");
	 }
 }
//删除对应姓名的学生
void shanchu1(student *head)
{
	printf("请输入删除学生姓名\n");
    char b[10];
    scanf("%s",&b);
    int x=0;
	student *p,*q;
	p=head;
	do
	{
		if(strcmp(p->next->name,b)==0)
		{
		    q=p->next;
		    printf("%s %d %c %d %d %d\n",q->name,q->age,q->sex,q->studentnumber,q->dormitrynumber,q->bednumber);
			printf("删除成功\n");
			p->next=q->next;
			x=1;
			break;
		}
		else
		{
			p=p->next;
		}
	}while(p->next->next!=NULL);
	if(p->next->next==NULL)
    {
        if(strcmp(p->next->name,b)==0)
        {
		    q=p->next;
		    printf("%s %d %c %d %d %d\n",q->name,q->age,q->sex,q->studentnumber,q->dormitrynumber,q->bednumber);
			printf("删除成功\n");
			p->next=q->next;
			x=1;

        }
    }
	if(x==0)
	{
		printf("搜索失败没有找到该学生\n");
	}	
}
//删除对应学号的学生 
void shanchu(student *head)
{
    printf("请输入删除学生学号\n");
    int b;
    scanf("%d",&b);
    int x=0;
	student *p,*q;
	p=head;
	do
	{

		if(p->next->studentnumber==b)
		{
		    q=p->next;
		    printf("%s %d %c %d %d %d\n",q->name,q->age,q->sex,q->studentnumber,q->dormitrynumber,q->bednumber);
			printf("删除成功\n");
			p->next=q->next;
			x=1;
			break;
		}
		else
		{
			p=p->next;
		}
	}while(p->next->next!=NULL);
	if(p->next->next==NULL)
    {
        if(p->next->studentnumber==b)
        {
		    q=p->next;
		    printf("%s %d %c %d %d %d\n",q->name,q->age,q->sex,q->studentnumber,q->dormitrynumber,q->bednumber);
			printf("删除成功\n");
			p->next=q->next;
			x=1;

        }
    }
	if(x==0)
	{
		printf("搜索失败没有找到该学生\n");
	}
}
//根据宿舍号搜索学生信息
void search2(student *head)
{
	int c,y=0,x;
	printf("请输入查找学生的宿舍号\n");
    scanf("%d",&c);
    int low=1,high=length(head),mid,temp;
    student *p;
    while(low<=high)
    {

    	mid=(low+high)/2;
    	for(p=head->next,x=1;x!=mid;x++)
    	{
    		p=p->next;
		}
		if(p->dormitrynumber==c)
		{
			temp=mid;
			high=mid-1;			
			y=1;				
		}
		else if(p->dormitrynumber>c)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	
		if(y==0) 
	{
		printf("搜索失败没有找到该学生\n");
	}
	else{
		printf("搜索成功\n") ;
    	for(p=head->next,x=1;x!=temp;x++)
    	{
    		p=p->next;
		}
		while(p->dormitrynumber==c)
		{
			printf("%s %d %c %d %d %d\n",p->name,p->age,p->sex,p->studentnumber,p->dormitrynumber,p->bednumber);
			p=p->next; 
		} 
	} 
 } 
//根据名字搜索学生信息
void search1(student *head)
{
	char a[10];
	int y=0,x;
	printf("请输入查找学生的名字\n") ;
	scanf("%s",a);
    int low=1,high=length(head),mid;
    student *p;
    while(low<=high)
    {
    	mid=(low+high)/2;
    	for(p=head->next, x=1;x!=mid;x++)
    	{
    		p=p->next;
		}
		if(strcmp(a,p->name)==0)
		{
			printf("搜索成功\n");
			printf("%s %d %c %d %d %d\n",p->name,p->age,p->sex,p->studentnumber,p->dormitrynumber,p->bednumber);
			y=1;
			break;				
		}
		else if(strcmp(p->name,a)>0)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
		if(y==0) 
	{
		printf("搜索失败没有找到该学生\n");
	}
 }
//根据学号搜索学生信息
void search(student *head)
{
    int c,y=0,x;
    printf("请输入查找学生的学号\n");
    scanf("%d",&c);
    int low=1,high=length(head),mid;
    student *p;
    while(low<=high)
    {
    	mid=(low+high)/2;
    	for( x=1,p=head->next;x!=mid;x++)
    	{
    		p=p->next; 
		}
		if(p->studentnumber==c)
		{
			printf("搜索成功\n");
			printf("%s %d %c %d %d %d\n",p->name,p->age,p->sex,p->studentnumber,p->dormitrynumber,p->bednumber);
			y=1;
			break;			
		}
		else if(p->studentnumber>c)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}	
	}
	if(y==0) 
	{
		printf("搜索失败没有找到该学生\n");
	}
}
//修改对应学号学生的信息
void change(student *head)
{
    int w,x=0;
    printf("请输入修改信息学生的学号\n");
    scanf("%d",&w);
	student *p,*q,*f;
	p=head;
	do{
        if(p->next->studentnumber==w)
        {
            q=p->next;
            printf("%s %d %c %d %d %d\n",q->name,q->age,q->sex,q->studentnumber,q->dormitrynumber,q->bednumber);
            printf("请输入修改后学生的姓名 年龄 性别 学号 宿舍号 床号\n" );
            printf("例：胡文胜 19 M 1707004425 221 3(中间加空格)\n");
            scanf("%s %d %c %d %d %d",&f->name,&f->age,&f->sex,&f->studentnumber,&f->dormitrynumber,&f->bednumber);
            p->next=f;
            f->next=q->next;
            free(q);
            printf("修改成功\n");
            x=1;
        }
        else
        {
            p=p->next;
        }
	}while(p->next->next!=NULL);
	if(p->next->next==NULL)
    {
        if(p->next->studentnumber==w)
        {
            q=p->next;
            printf("%s %d %c %d %d %d\n",q->name,q->age,q->sex,q->studentnumber,q->dormitrynumber,q->bednumber);
            printf("请输入修改后学生的姓名 年龄 性别 学号 宿舍号 床号\n" );
            printf("例：胡文胜 19 M 1707004425 221 3(中间加空格)\n");
            scanf("%s %d %c %d %d %d",&f->name,&f->age,&f->sex,&f->studentnumber,&f->dormitrynumber,&f->bednumber);
            p->next=f;
            f->next=NULL;
            free(q);
            printf("修改成功\n");
            x=1;
        }
    }
    if(x==0)
    {

        printf("搜索失败找不到该学生\n");
    }
}
void change1(student *head)
{
	char w[10];
    int x=0;
    printf("请输入修改信息学生的姓名\n");
    scanf("%s",w);
	student *p,*q,*f;
	p=head;
	do{
        if(strcmp(p->next->name,w)==0)
        {
            q=p->next;
            printf("%s %d %c %d %d %d\n",q->name,q->age,q->sex,q->studentnumber,q->dormitrynumber,q->bednumber);
            printf("请输入修改后学生的姓名 年龄 性别 学号 宿舍号 床号\n" );
            printf("例：胡文胜 19 M 1707004425 221 3(中间加空格)\n");
            scanf("%s %d %c %d %d %d",&f->name,&f->age,&f->sex,&f->studentnumber,&f->dormitrynumber,&f->bednumber);
            p->next=f;
            f->next=q->next;
            free(q);
            printf("修改成功\n");
            x=1;
        }
        else
        {
            p=p->next;
        }
	}while(p->next->next!=NULL);
	if(p->next->next==NULL)
    {
        if(strcmp(p->next->name,w)==0)
        {
            q=p->next;
            printf("%s %d %c %d %d %d\n",q->name,q->age,q->sex,q->studentnumber,q->dormitrynumber,q->bednumber);
            printf("请输入修改后学生的姓名 年龄 性别 学号 宿舍号 床号\n" );
            printf("例：胡文胜 19 M 1707004425 221 3(中间加空格)\n");
            scanf("%s %d %c %d %d %d",&f->name,&f->age,&f->sex,&f->studentnumber,&f->dormitrynumber,&f->bednumber);
            p->next=f;
            f->next=NULL;
            free(q);
            printf("修改成功\n");
            x=1;
        }
    }
    if(x==0)
    {

        printf("搜索失败找不到该学生\n");
    }	
 } 
//罗列所有学生的信息
void show(student *head)
{
    student *p;
    p=head;
    if(head->next==NULL)
    {
    	printf("当前没有录入学生\n");
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
			printf("%s %d %c %d %d %d\n",p->name,p->age,p->sex,p->studentnumber,p->dormitrynumber,p->bednumber);
		}
		printf("以上是全部的学生信息\n");
	}
 }
 //将当前链表内的学生信息录入文件
 void addtxt(student *head)
 {
 	FILE *fp;
 	fp=fopen("F:\\studentlist.txt","w");
 	student *p;
 	p=head;
 	printf("1");
    while(p->next!=NULL)
    {
        p=p->next;
    	fprintf(fp,"%s %d %c %d %d %d\n",p->name,p->age,p->sex,p->studentnumber,p->dormitrynumber,p->bednumber);

	}
	 fclose(fp);
	 printf("保存成功\n");
  }
 //将文件内的信息加入链表
 void taketxt(student *head)
 {
 	FILE *fp=NULL	;
 	fp=fopen("F:\\studentlist.txt","r");
 	student *p=NULL,*q=NULL;
 	p=q=head;
 	if(fp==NULL)
    {
    	printf("读取文件失败\n");
    	return;
	}
	else
	{
		char a[10];int b;char c; int d; int e; int f;
		while(fscanf(fp,"%s %d %c %d %d %d\n",a,&b,&c,&d,&e,&f)!=EOF)
		{
			q= (student*)malloc(Size);
			if(q==NULL)
			printf("空间不足\n");
			strcpy(q->name,a);q->age=b;q->sex=c;q->studentnumber=d;q->dormitrynumber=e;q->bednumber=f;
			q->next=NULL;
			p->next=q;
			p=q;
		}
		p->next=NULL;
	}
	fclose(fp);
	printf("读取文件成功\n");
  }
 //操作系统菜单
void  menu()
 {
 	printf("1.输出已经录入的学生信息\n");
	printf("2.增加录入学生信息\n");
	printf("3.减去录入学生信息\n");
	printf("4.查找学生信息\t");
	printf("请查找前先按对应排序方式进行排序\n");
	printf("5.修改录入学生的信息\n");
	printf("6.排序学生信息\n");
	printf("7.退出系统\n");
	return ;
}
//宿舍号排序
void pai2(student *head)
{
	if((head->next==NULL||head->next->next==NULL))
	{
		printf("排序完成\n");
		return;
	}
	student *temp,*s,*f,*t,*end;
	end=NULL;
	while(head->next!=end)
	{
		for(f=head,s=f->next,t=s->next;t!=end;f=f->next,s=s->next,t=t->next)
		{
			if(s->dormitrynumber>=t->dormitrynumber)
			{
				s->next=t->next;
				f->next=t;
				t->next=s;
				temp=t;
				t=s;
				s=temp;						
			}
		}
		end=s;
	 } 
	 printf("排序完成\n");
 } 
//名字排序
void pai1(student *head)
{
	if(head->next==NULL||head->next->next==NULL)
	{
		printf("排序完成\n");
		return; 
	}
	student *temp,*s,*f,*t,*end;
	end=NULL;
	while(head->next!=end)
	{
		for(f=head,s=f->next,t=s->next;t!=end;f=f->next,s=s->next,t=t->next)
		{
			if(strcmp(s->name,t->name)>=0)
			{
				s->next=t->next;
				f->next=t;
				t->next=s;
				temp=t;
				t=s;
				s=temp;				
			}
		}
		end=s;
	}
	printf("排序完成\n"); 
 } 
//学号排序 
void pai(student *head)
{
    if(head->next==NULL||head->next->next==NULL)
    {
    	printf("排序完成\n");
    	return;
	}
	student *temp,*s,*f,*t,*end;
	end=NULL; 
	while(head->next!=end)
	{
		for(f=head,s=f->next,t=s->next;t!=end;f=f->next,s=s->next,t=t->next)
		{
			if(s->studentnumber>t->studentnumber)
			{
				s->next=t->next;
				f->next=t;
				t->next=s;
				temp=t;
				t=s;
				s=temp;
			}
		 }
		end = s;
	}
	printf("排序完成\n");
 }
//使用系统
 void use(student *head)
{
 	int x;
	printf("请输入1到7的数字选择操作\n");
	scanf("%d",&x);
	switch(x){
		case 1:
			show(head);
			use(head);
			break;
		case 2:
			add(head);
			use(head);
			break;
		case 3:
			printf("请选择删除的查找方式\n");
			printf("1.学号查找请输入1\n");
			printf("2.姓名查找请输入2\n");			
			int n;
			scanf("%d",&n);
			if(n==1)
			{
			    shanchu(head);
			} 
			else if(n==2)
			{
			    shanchu1(head);
			} 
			else 
			{
				printf("输入错误\n");
			}			
			use(head);
			break;
		case 4:
			printf("请选择查找方式\n");
			printf("请查找前先按对应排序方式进行排序\n");
			printf("1.学号查找请输入1\n");
			printf("2.姓名查找请输入2\n");
			printf("3.宿舍号查找请输入3\n");
			int h;
			scanf("%d",&h);
			printf("1");
			if(h==1)
			{
			    search(head);
			} 
			else if(h==2)
			{
			    search1(head);
			} 
			else if(h==3) 
			{
				search2(head);
			}
			else 
			{
				printf("输入错误\n");
			}
			use(head);
			break;
		case 5:
			printf("请选择查找修改信息学生的方式\n");
			printf("1.学号查找请输入1\n");
			printf("2.姓名查找请输入2\n");
			int o;
			scanf("%d",&o);
			if(o==1)
			{
			    change(head);
			} 
			else if(o==2)
			{
			    change1(head);
			} 
			else 
			{
				printf("输入错误\n");
			}								
			use(head);
			break;
		case 6:
			printf("请选择排序方式\n");
			printf("1.按学号排序请输入1\n");
			printf("2.按姓名排序请输入2\n");
			printf("3.按宿舍号排序请输入3\n");
			int z;
			scanf("%d",&z);
			if(z==1)
			{
			    pai(head);
			} 
			else if(z==2)
			{
			    pai1(head);
			} 
			else if(z==3) 
			{
				pai2(head);
			}
			else 
			{
				printf("输入错误\n");
			}			
			use(head);
			break;
		case 7:
			addtxt(head);
			printf("退出系统成功\n");
			use(head);
			break;
	    default:
		    printf("输入错误请重新输入\n");
		    use(head);
    }
}
int length(student *head)
{
	int x=0;
	student *p;
	p=head;
	while(p->next!=NULL)
	{
		x++;
		p=p->next;
	}
	x++;
	return x;
}
