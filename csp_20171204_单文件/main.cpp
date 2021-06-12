//行车路线 ccf，我失败了，我用的图的深度搜索，但是不引用viste造成递归不出去，网上说dijstra，邻接矩阵，暂时不太会 
#include <iostream>
using namespace std;

class Bian
{
	public:
	int veradj;
	int cost;
	int kind;
	Bian * link;
	Bian();
};

class Head
{
	public:
	int vername;
    Bian * adjacent;
    Head();
};

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

void depth(int v,int lianxiao,int nowpi,int ci);
    
int n,m;
int pilao[1000];
int k;
Head head[1000];

int main() 
{
   	int i,j;
   	int t,a,b,c;
   	Bian * p;
   	Bian * q;
    
	//输入
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
    
	//输出
    for(i=0;i<n;i++)
    {
    	cout<<endl;
   	    cout<<head[i].vername;
   	    p=head[i].adjacent ;
   	    while(p!=NULL)
   	    {
   	        cout<<"-->"<<"编号"<<p->veradj<<"类型"<<p->kind<<"值"<<p->cost;
   	        p=p->link;
		}
	} 
    
	//计算 
    k=0;
	depth(1,0,0,1);
	int min;
	min=pilao[0];
	cout<<"进去结果"<<endl;
    for(i=0;i<k;i++)
    {
    	if(pilao[i]<min)
    	{
    		min=pilao[i];
		}
	}
	cout<<min;
	//delete
	for(i=0;i<n;i++)
	{
		cout<<"进入删除"<<endl;
		while(head[i].adjacent !=NULL)
		{
			p=head[i].adjacent;
			head[i].adjacent=p->link;
			delete p;
		}
	} 
	cout<<"删除完毕"<<endl;
	return 0;
}

void depth(int v,int lianxiao,int nowpi,int ci)
{
    Bian * p;
	p=head[v-1].adjacent;
	if(p==NULL)
	{
		return;
	}
	for(int i=1;i<ci;i++)
	{
		p=p->link;
	}
	ci++;
	while(p!=NULL)
	{
		if(p->kind==0)
		{
			nowpi=nowpi+lianxiao*lianxiao;
			lianxiao=0;
			nowpi=nowpi+p->cost;
//			cout<<"kind1,lianxiao="<<lianxiao<<"  nowpi="<<nowpi<<endl;
		}
		else if(p->kind==1)
		{
			lianxiao=lianxiao+p->cost;
//			cout<<"kind2 ,lianxiao="<<lianxiao<<"  nowpi="<<nowpi<<endl;
		}
		if(p->veradj==n)
		{
			nowpi=nowpi+lianxiao*lianxiao;
			pilao[k]=nowpi;
			k++;
//			cout<<"pilao["<<k<<"]="<<pilao[k-1]<<endl;
		}
		depth(p->veradj,lianxiao,nowpi,1);
	}
	p=p->link;
}
