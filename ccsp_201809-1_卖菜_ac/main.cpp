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
//º∆À„ 
	int b[1002];
	b[0]=(a[0]+a[1])/2;
	b[n-1]=(a[n-1]+a[n-2])/2;
	for(i=1;i<n-1;i++)
	{
		b[i]=(a[i]+a[i-1]+a[i+1])/3;
	}
// ‰≥ˆ
	for(i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}	
	return 0;
}
