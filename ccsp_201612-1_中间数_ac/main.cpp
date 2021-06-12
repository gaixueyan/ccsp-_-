/*我想麻烦了，只要数有几个大于中位数，几个小于中位数的就行，这点算法复杂度都是n，少几个几十个根本起不了作用。*/
 
#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
//输入	
	int n;
	int a[1001];
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	} 
//排序
	int j=n;
	int r;
	while(j>0)
	{
		for(i=0;i<j-1;i++)
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
//计算
	int zhongweishu=a[n/2];
	int xiaoyu=0,dayu=0;
	for(i=0;i<n/2;i++)
	{
		if(a[i]<zhongweishu)
		{
			xiaoyu++;
		}
	} 
	for(i=n/2;i<n;i++)
	{
		if(a[i]>zhongweishu)
		{
			dayu++;
		}
	}
	if(xiaoyu==dayu)
	{
		cout<<zhongweishu;
	}
	else
	{
		cout<<-1;
	}
	return 0;
}
