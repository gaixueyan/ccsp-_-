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
	int sum=0;
	for(i=1;i<n-1;i++)
	{
		if((a[i+1]>a[i]) && (a[i-1]>a[i]))
		{
			sum++;
		}
		else if((a[i+1]<a[i]) && (a[i-1]<a[i]))
		{
			sum++;
		}	
	} 
	cout<<sum;	
	return 0;
}
