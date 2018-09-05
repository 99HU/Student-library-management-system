#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#define Size sizeof(struct student)
using namespace std;
int number=0;
//ѧ���ṹ��
typedef struct student
{
	int studentnumber;//ѧ��
	int dormitrynumber;//�����
	int bednumber;//����
	char name[10];//����
	char sex;//�Ա�
	int age;//����
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
    printf("\t��ӭ�����������ϵͳ\n");
  	menu();
	int a;
	student *head;
	head=(student *)malloc(Size);
	head->next=NULL;
	taketxt(head);
	use(head);
	return 0;
}
//���Ӷ�̬����Ľڵ�
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
		printf("����������������� ���� �Ա� ѧ�� ����� ����\n");
		printf("��������ʤ 19 M 1707004425 221 3�м�ӿո�\n");
		scanf("%s %d %c %d %d %d",p->name,&p->age,&p->sex,&p->studentnumber,&p->dormitrynumber,&p->bednumber);
		p->next =NULL;
		number++;
	}
	else
	{
		printf("����ռ�ʧ��\n");
	 }
 }
//ɾ����Ӧ������ѧ��
void shanchu1(student *head)
{
	printf("������ɾ��ѧ������\n");
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
			printf("ɾ���ɹ�\n");
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
			printf("ɾ���ɹ�\n");
			p->next=q->next;
			x=1;

        }
    }
	if(x==0)
	{
		printf("����ʧ��û���ҵ���ѧ��\n");
	}	
}
//ɾ����Ӧѧ�ŵ�ѧ�� 
void shanchu(student *head)
{
    printf("������ɾ��ѧ��ѧ��\n");
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
			printf("ɾ���ɹ�\n");
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
			printf("ɾ���ɹ�\n");
			p->next=q->next;
			x=1;

        }
    }
	if(x==0)
	{
		printf("����ʧ��û���ҵ���ѧ��\n");
	}
}
//�������������ѧ����Ϣ
void search2(student *head)
{
	int c,y=0,x;
	printf("���������ѧ���������\n");
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
		printf("����ʧ��û���ҵ���ѧ��\n");
	}
	else{
		printf("�����ɹ�\n") ;
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
//������������ѧ����Ϣ
void search1(student *head)
{
	char a[10];
	int y=0,x;
	printf("���������ѧ��������\n") ;
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
			printf("�����ɹ�\n");
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
		printf("����ʧ��û���ҵ���ѧ��\n");
	}
 }
//����ѧ������ѧ����Ϣ
void search(student *head)
{
    int c,y=0,x;
    printf("���������ѧ����ѧ��\n");
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
			printf("�����ɹ�\n");
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
		printf("����ʧ��û���ҵ���ѧ��\n");
	}
}
//�޸Ķ�Ӧѧ��ѧ������Ϣ
void change(student *head)
{
    int w,x=0;
    printf("�������޸���Ϣѧ����ѧ��\n");
    scanf("%d",&w);
	student *p,*q,*f;
	p=head;
	do{
        if(p->next->studentnumber==w)
        {
            q=p->next;
            printf("%s %d %c %d %d %d\n",q->name,q->age,q->sex,q->studentnumber,q->dormitrynumber,q->bednumber);
            printf("�������޸ĺ�ѧ�������� ���� �Ա� ѧ�� ����� ����\n" );
            printf("��������ʤ 19 M 1707004425 221 3(�м�ӿո�)\n");
            scanf("%s %d %c %d %d %d",&f->name,&f->age,&f->sex,&f->studentnumber,&f->dormitrynumber,&f->bednumber);
            p->next=f;
            f->next=q->next;
            free(q);
            printf("�޸ĳɹ�\n");
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
            printf("�������޸ĺ�ѧ�������� ���� �Ա� ѧ�� ����� ����\n" );
            printf("��������ʤ 19 M 1707004425 221 3(�м�ӿո�)\n");
            scanf("%s %d %c %d %d %d",&f->name,&f->age,&f->sex,&f->studentnumber,&f->dormitrynumber,&f->bednumber);
            p->next=f;
            f->next=NULL;
            free(q);
            printf("�޸ĳɹ�\n");
            x=1;
        }
    }
    if(x==0)
    {

        printf("����ʧ���Ҳ�����ѧ��\n");
    }
}
void change1(student *head)
{
	char w[10];
    int x=0;
    printf("�������޸���Ϣѧ��������\n");
    scanf("%s",w);
	student *p,*q,*f;
	p=head;
	do{
        if(strcmp(p->next->name,w)==0)
        {
            q=p->next;
            printf("%s %d %c %d %d %d\n",q->name,q->age,q->sex,q->studentnumber,q->dormitrynumber,q->bednumber);
            printf("�������޸ĺ�ѧ�������� ���� �Ա� ѧ�� ����� ����\n" );
            printf("��������ʤ 19 M 1707004425 221 3(�м�ӿո�)\n");
            scanf("%s %d %c %d %d %d",&f->name,&f->age,&f->sex,&f->studentnumber,&f->dormitrynumber,&f->bednumber);
            p->next=f;
            f->next=q->next;
            free(q);
            printf("�޸ĳɹ�\n");
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
            printf("�������޸ĺ�ѧ�������� ���� �Ա� ѧ�� ����� ����\n" );
            printf("��������ʤ 19 M 1707004425 221 3(�м�ӿո�)\n");
            scanf("%s %d %c %d %d %d",&f->name,&f->age,&f->sex,&f->studentnumber,&f->dormitrynumber,&f->bednumber);
            p->next=f;
            f->next=NULL;
            free(q);
            printf("�޸ĳɹ�\n");
            x=1;
        }
    }
    if(x==0)
    {

        printf("����ʧ���Ҳ�����ѧ��\n");
    }	
 } 
//��������ѧ������Ϣ
void show(student *head)
{
    student *p;
    p=head;
    if(head->next==NULL)
    {
    	printf("��ǰû��¼��ѧ��\n");
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
			printf("%s %d %c %d %d %d\n",p->name,p->age,p->sex,p->studentnumber,p->dormitrynumber,p->bednumber);
		}
		printf("������ȫ����ѧ����Ϣ\n");
	}
 }
 //����ǰ�����ڵ�ѧ����Ϣ¼���ļ�
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
	 printf("����ɹ�\n");
  }
 //���ļ��ڵ���Ϣ��������
 void taketxt(student *head)
 {
 	FILE *fp=NULL	;
 	fp=fopen("F:\\studentlist.txt","r");
 	student *p=NULL,*q=NULL;
 	p=q=head;
 	if(fp==NULL)
    {
    	printf("��ȡ�ļ�ʧ��\n");
    	return;
	}
	else
	{
		char a[10];int b;char c; int d; int e; int f;
		while(fscanf(fp,"%s %d %c %d %d %d\n",a,&b,&c,&d,&e,&f)!=EOF)
		{
			q= (student*)malloc(Size);
			if(q==NULL)
			printf("�ռ䲻��\n");
			strcpy(q->name,a);q->age=b;q->sex=c;q->studentnumber=d;q->dormitrynumber=e;q->bednumber=f;
			q->next=NULL;
			p->next=q;
			p=q;
		}
		p->next=NULL;
	}
	fclose(fp);
	printf("��ȡ�ļ��ɹ�\n");
  }
 //����ϵͳ�˵�
void  menu()
 {
 	printf("1.����Ѿ�¼���ѧ����Ϣ\n");
	printf("2.����¼��ѧ����Ϣ\n");
	printf("3.��ȥ¼��ѧ����Ϣ\n");
	printf("4.����ѧ����Ϣ\t");
	printf("�����ǰ�Ȱ���Ӧ����ʽ��������\n");
	printf("5.�޸�¼��ѧ������Ϣ\n");
	printf("6.����ѧ����Ϣ\n");
	printf("7.�˳�ϵͳ\n");
	return ;
}
//���������
void pai2(student *head)
{
	if((head->next==NULL||head->next->next==NULL))
	{
		printf("�������\n");
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
	 printf("�������\n");
 } 
//��������
void pai1(student *head)
{
	if(head->next==NULL||head->next->next==NULL)
	{
		printf("�������\n");
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
	printf("�������\n"); 
 } 
//ѧ������ 
void pai(student *head)
{
    if(head->next==NULL||head->next->next==NULL)
    {
    	printf("�������\n");
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
	printf("�������\n");
 }
//ʹ��ϵͳ
 void use(student *head)
{
 	int x;
	printf("������1��7������ѡ�����\n");
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
			printf("��ѡ��ɾ���Ĳ��ҷ�ʽ\n");
			printf("1.ѧ�Ų���������1\n");
			printf("2.��������������2\n");			
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
				printf("�������\n");
			}			
			use(head);
			break;
		case 4:
			printf("��ѡ����ҷ�ʽ\n");
			printf("�����ǰ�Ȱ���Ӧ����ʽ��������\n");
			printf("1.ѧ�Ų���������1\n");
			printf("2.��������������2\n");
			printf("3.����Ų���������3\n");
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
				printf("�������\n");
			}
			use(head);
			break;
		case 5:
			printf("��ѡ������޸���Ϣѧ���ķ�ʽ\n");
			printf("1.ѧ�Ų���������1\n");
			printf("2.��������������2\n");
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
				printf("�������\n");
			}								
			use(head);
			break;
		case 6:
			printf("��ѡ������ʽ\n");
			printf("1.��ѧ������������1\n");
			printf("2.����������������2\n");
			printf("3.�����������������3\n");
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
				printf("�������\n");
			}			
			use(head);
			break;
		case 7:
			addtxt(head);
			printf("�˳�ϵͳ�ɹ�\n");
			use(head);
			break;
	    default:
		    printf("�����������������\n");
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
