#include <iostream>
using namespace std;

int a[2005][2];
int b[2005][2];
int max(int a,int b)
{
	if(a>=b)
	{
		return a;
	}
	return b;
}
int min(int a,int b)
{
	if(a<=b)
	{
		return a;
	}
	return b;
}

int main(int argc, char** argv) 
{
	//����
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	for(i=0;i<n;i++)
	{
		cin>>b[i][0]>>b[i][1];
	}
	//����
	long time;//���
	time=0;
	int na=0;
	int nb=0;
	int chongheshi;
	int chonghemo;
	while(na<n && nb<n)
	{
		if(a[na][1]<=b[nb][0])//a��������b��ʼ 
		{
			na=na+1;
		}
		else if(a[na][0]>=b[nb][1])//b��������a��ʼ
		{
			nb=nb+1;
		}
		else
		{
			chongheshi=max(a[na][0],b[nb][0]);
			chonghemo=min(a[na][1],b[nb][1]);
			time=time+chonghemo-chongheshi;
			if(a[na][1]>b[nb][1])
			{
				nb+=1;
			}
			else if(a[na][1]<b[nb][1])
			{
				na+=1;
			}
			else
			{
				na+=1;
				nb+=1;
			}
		}
	} 
	cout<<time;
	return 0;
}
