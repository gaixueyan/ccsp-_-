#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
// ‰»Î 
	int r,y,g;
	int n;
	int a[105][2];
	cin>>r>>y>>g;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
//‘ÀÀ„
	int time;
	time=0; 
	for(i=0;i<n;i++)
	{
		switch (a[i][0])
		{
			case 0: time+=a[i][1];
			break;
			case 1:time+=a[i][1];
			break;
			case 2:time=time+a[i][1]+r;	
		}
	}
	cout<<time;	
	return 0;
}
