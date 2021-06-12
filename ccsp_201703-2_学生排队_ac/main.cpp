#include <iostream>
using namespace std;
 
int a[1005][2];
int b[1005];
int main(int argc, char** argv) 
{
	//输入 
	int n,m;
	cin>>n>>m;
	int i;
	for(i=0;i<m;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	//初始排队赋值
	for(i=0;i<n;i++)
	{
		b[i]=i+1;
	} 
	//排序
	int j;
	int r;
	int k;
	for(i=0;i<m;i++)
	{
		j=0;
		while(b[j]!=a[i][0])
		{
			j++;
		}
		if(a[i][1]>0)
		{
			r=a[i][0];
			for(k=0;k<a[i][1];k++)
			{
				b[j]=b[j+1];
				j++;
			}
			b[j]=r;
		}
		else
		{
			r=a[i][0];
			for(k=0;k<-a[i][1];k++)
			{
				b[j]=b[j-1];
				j--;
			}
			b[j]=r;
		}
	} 
	//输出
	for(i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
