#include <iostream>
using namespace std;

struct quchuxing
{
	int shijian;
	int hao;
};

struct fangruxing
{
	int shijian;
	int hao;
};

int main(int argc, char** argv) 
{
	int yaoshi[1000];
	struct quchuxing quchu[1000];
	struct fangruxing fangru[1000];
	int N,k,w,s,c;
	cin>>N>>k;
	int i,j;
	for(i=0;i<N;i++)
	{
		yaoshi[i]=i+1;
	}
	for(i=0;i<k;i++)
	{
		cin>>w>>s>>c;
		quchu[i].shijian=s;
		quchu[i].hao=w;
		fangru[i].hao=w;
		fangru[i].shijian=s+c;
	}
	int rs,rh;
	for(i=1;i<k;i++)
	{
		j=i-1;
		rs=quchu[i].shijian ;
		rh=quchu[i].hao ;
		while(quchu[j].shijian >rs && j>=0)
		{
			quchu[j+1].shijian =quchu[j].shijian ;
			quchu[j+1].hao =quchu[j].hao ;
			j--;
		}
		quchu[j+1].shijian =rs;
		quchu[j+1].hao =rh;
	}
	for(i=1;i<k;i++)
	{
		j=i-1;
		rs=fangru[i].shijian ;
		rh=fangru[i].hao ;
		while((fangru[j].shijian>rs ||(fangru[j].shijian==rs&&fangru[j].hao >rh)) && j>=0)
		{
	    	fangru[j+1].shijian =fangru[j].shijian ;
	        fangru[j+1].hao =fangru[j].hao ;
			j--;
		}
		fangru[j+1].shijian =rs;
		fangru[j+1].hao =rh;
	}
/*	
	cout<<endl;
    for(i=0;i<k;i++)
    {
    	cout<<"取出时间"<<quchu[i].shijian <<"号"<<quchu[i].hao <<endl;
	}
	for(i=0;i<k;i++)
    {
    	cout<<"放入时间"<<fangru[i].shijian <<"号"<<fangru[i].hao <<endl;
	}
*/
	int topq=0,topf=0;
	int sq=k,sf=k;
	int flag;
	while(sq!=0)
	{
		if(quchu[topq].shijian <fangru[topf].shijian )
		{
			flag=1;
			for(i=0;i<N,flag==1;i++)
			{
				if(yaoshi[i]==quchu[topq].hao )
				{
					cout<<"时间"<<quchu[topq].shijian <<"取出"<<quchu[topq].hao<<endl;
					yaoshi[i]=0;
					sq--;
					topq++;
					flag=0;
				}
			}
		}
		else
		{
			flag=1;
			for(i=0;i<N,flag==1;i++)
			{
				if(yaoshi[i]==0)
				{
					yaoshi[i]=fangru[topf].hao ;
					cout<<"时间"<<fangru[topf].shijian <<"放入"<<fangru[topf].hao<<endl;
					topf++;
					sf--;
					flag=0;
				}
			}
		}
	}
	while(sf>0)
	{
		flag=1;
		for(i=0;i<N,flag==1;i++)
		{
			if(yaoshi[i]==0)
			{
				yaoshi[i]=fangru[topf].hao ;
				cout<<"时间"<<fangru[topf].shijian <<"放入"<<fangru[topf].hao<<endl;
				topf++;
				sf--;
				flag=0;
			}
		}
	}
	for(i=0;i<N-1;i++)
	{
		cout<<yaoshi[i]<<" ";
	}
	cout<<yaoshi[i];
	return 0;
}
