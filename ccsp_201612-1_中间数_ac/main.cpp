/*�����鷳�ˣ�ֻҪ���м���������λ��������С����λ���ľ��У�����㷨���Ӷȶ���n���ټ�����ʮ�������������á�*/
 
#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
//����	
	int n;
	int a[1001];
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	} 
//����
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
//����
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
