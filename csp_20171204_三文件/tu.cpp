#include"tu.h"

Bian::Bian()
{
	veradj=0;
	cost=0;
	kind=0;
	link=NULL;
}

Head::Head() 
{
	vername=0;
	adjacent=NULL;
}

void make::input()
{
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		head[i].vername =i+1;
		head[i].adjacent =NULL;
	}
	for(i=0;i<m;i++)
	{
		cin>>t>>a>>b>>c;
		if(head[a-1].adjacent ==NULL)
		{
			p=new Bian;
			head[a-1].adjacent =p;
			p->veradj=b;
			p->cost=c;
			p->kind=t;
			p->link=NULL;
		}
		else
		{
			q=head[a-1].adjacent;
			while(q->link!=NULL)
			{
				q=q->link;
			}
			p=new Bian;
			q->link=p;
			p->veradj=b;
			p->cost=c;
			p->kind=t;
			p->link=NULL;
		}
	}
}

void make::back()
{
	for(i=0;i<n;i++)
	{
		while(head[i].adjacent !=NULL)
		{
			p=head[i].adjacent;
			head[i].adjacent=p->link;
			delete p;
		}
	}
}
