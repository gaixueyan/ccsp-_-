#include <iostream>
using namespace std;
 
int a[2005][3];
int b[1005];
int main(int argc, char** argv) 
{
	//输入 
	int n,k;
	cin>>n>>k;
	int i;
	int num;
	for(i=0;i<2*k;i=i+2)
	{
		cin>>num;
		a[i][0]=num;
		a[i+1][0]=num;
		a[i][1]=0;
		a[i+1][1]=1;
		cin>>a[i][2];
		cin>>a[i+1][2];
		a[i+1][2]=a[i][2]+a[i+1][2];
	}
	for(i=1;i<=n;i++)
	{
		b[i]=i;
	}
	b[0]=-1;

	//时间排序
	int j;
	int r;
	j=2*k-1;
	while(j>1)
	{
		for(i=0;i<j;i++)
		{
			if(a[i][2]>a[i+1][2])
			{
				r=a[i][0];
				a[i][0]=a[i+1][0];
				a[i+1][0]=r;
				r=a[i][1];
				a[i][1]=a[i+1][1];
				a[i+1][1]=r;
				r=a[i][2];
				a[i][2]=a[i+1][2];
				a[i+1][2]=r;				
			}
			else if(a[i][2]==a[i+1][2])
			{
				if(a[i][1]<a[i+1][1])
				{
					r=a[i][0];
					a[i][0]=a[i+1][0];
					a[i+1][0]=r;
					r=a[i][1];
					a[i][1]=a[i+1][1];
					a[i+1][1]=r;
					r=a[i][2];
					a[i][2]=a[i+1][2];
					a[i+1][2]=r;	
				}
				else if(a[i][1]==1 && a[i+1][1]==1)
				{
					if(a[i][0]>a[i+1][0])
					{
						r=a[i][0];
						a[i][0]=a[i+1][0];
						a[i+1][0]=r;
						r=a[i][1];
						a[i][1]=a[i+1][1];
						a[i+1][1]=r;
						r=a[i][2];
						a[i][2]=a[i+1][2];
						a[i+1][2]=r;	
					}
				}
			}
		}
		j=j-1;
	}


	//计算钥匙
	int flag;
	for(i=0;i<2*k;i++)
	{
		if(a[i][1]==0)
		{
			flag=1;
			for(j=1;j<=n && flag==1;j++)
			{
				if(b[j]==a[i][0])
				{
					b[j]=0;
					flag=0;
				}
			}
		}
		else
		{
			flag=1;
			for(j=1;j<=n && flag==1;j++)
			{
				if(b[j]==0)
				{
					b[j]=a[i][0];
					flag=0;
				}
			}
		}
	} 
	//输出
	for(i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
	} 
	return 0;
}
