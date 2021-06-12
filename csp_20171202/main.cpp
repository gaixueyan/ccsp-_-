#include <iostream>
using namespace std;

int main() 
{
	int n,k;
	cin>>n;
	cin>>k;
	int a[1000];
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=1;//³õÊ¼ÉúÃü 
	}
	i=0;
	int lives;
	lives=n;
	int baoshu=1;
	while(lives>1)
	{
		if(i>n-1)
		{
			i=0;
		}
		if(a[i]!=0)
		{
			if(baoshu%k==0 || baoshu%10==k)
			{
			    a[i]=0;
		        lives=lives-1;
			}
			baoshu++;
		}
		i++;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			cout<<i+1;
		}
	}
	return 0;
}
