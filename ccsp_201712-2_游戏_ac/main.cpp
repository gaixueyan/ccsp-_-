#include <iostream>
using namespace std;
#include<stdlib.h>

struct link
{
	int num;
	struct link * next;
};

int main(int argc, char** argv) 
{
	//输入 
	int n,k;
	cin>>n>>k;
	//创建链表 
	struct link * head;
	head=(struct link *)malloc(sizeof(struct link));
	head->num=1;
	struct link * p;
	p=head;
	struct link * q;
	int i;
	for(i=2;i<=n;i++)
	{
		q=(struct link *)malloc(sizeof(struct link));
		q->num=i;
		p->next=q;
		p=q;
	}
	p->next=head;
	//删除链表
	q=head;
	int yishanchu=0;
	int baoshu=1;
	while(yishanchu<n-1)
	{
		if((baoshu%k==0) || (baoshu%10==k))
		{
			p->next=q->next;
			free(q);
			q=p->next;
			yishanchu+=1;
		}
		else
		{
			p=p->next;
			q=q->next;
		}
		baoshu+=1;
	} 
	//输出
	cout<<p->num; 
	return 0;
}
