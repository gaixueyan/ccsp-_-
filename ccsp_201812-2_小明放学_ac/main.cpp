#include <iostream>
using namespace std;

int a[100005][2];
int main(int argc, char** argv) 
{
	//ÊäÈë
	int r,y,g;
	cin>>r>>y>>g;
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	//¼ÆËã
	long int time;
	time=0;
	long int shijianzhou;
	shijianzhou=r+y+g;
	long int dangqian=0;
	for(i=0;i<n;i++)
	{
		if(a[i][0]==0)
		{
			time=time+a[i][1];
		}
		else if(a[i][0]==1)
		{
			dangqian=(shijianzhou-a[i][1]+time)%shijianzhou;
			if(dangqian>g)
			{
				time=time+shijianzhou-dangqian;
			}
		}
		else if(a[i][0]==2)
		{
			dangqian=(g+y-a[i][1]+time)%shijianzhou;
			if(dangqian>g)
			{
				time=time+shijianzhou-dangqian;
			}
		}
		else if(a[i][0]==3)
		{
			dangqian=(g-a[i][1]+time)%shijianzhou;
			if(dangqian>g)
			{
				time=time+shijianzhou-dangqian;
			}
		}
	} 
	//Êä³ö
	cout<<time; 
	return 0;
}
