#include <iostream>
using namespace std;
 

int main(int argc, char** argv) 
{
// ‰»Î 
	int n;
	int a[1002];
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
//≈≈–Ú
	int r;
	int j=n-1;
	while(j>0)
	{
		for(i=0;i<j;i++) 
		{
			if(a[i]>a[i+1])
			{
				r=a[i];
				a[i]=a[i+1];
				a[i+1]=r;
			}
		}
		j--;
	}
	
//º∆À„
	int b[1001];
	for(i=0;i<n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	} 
	
	int minb=b[0];
	for(i=0;i<n-1;i++)
	{
		if(b[i]<minb)
		{
			minb=b[i];
		}
	}
	cout<<minb;
	return 0;
}
