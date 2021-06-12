#include <iostream>
using namespace std;


int main() 
{
//ÊäÈë 
	int n;
	int a[10000];
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
//Ã°ÅÝÅÅÐò 
    int j,r;
    for(i=n-1;i>0;i--)
    {
    	for(j=0;j<i;j++)
    	{
    		if(a[j]>a[j+1])
			{
				r=a[j];
				a[j]=a[j+1];
				a[j+1]=r;
			}
		}
	}
for(i=0;i<n;i++)
{
	cout<<a[i]<<"  ";
}
//ÏàÁÚÏà¼õ 
	int cha;
	int wcha;
	cha=a[1]-a[0];
	for(int k=n-1;k>0;k--)
	{
		wcha=a[k]-a[k-1];
		if(wcha<cha)
		{
			cha=wcha;
		}
	}
	cout<<cha;
	return 0;
}
