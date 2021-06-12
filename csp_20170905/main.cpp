//时间超 以后用更好的算法来解决他 
#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	int N,M;
	cin>>N>>M;
	int i,j,k;
	int n[100000];
	for(i=0;i<N;i++)
	{
		cin>>n[i];
	}
	int opt;
	int l,r,v;
	int sum;
	for(j=0;j<M;j++)
	{
		cin>>opt;
		if(opt==1)
		{
			cin>>l>>r>>v;
			for(i=l-1;i<r;i++)
			{
				if(n[i]%v==0)
				{
					n[i]=n[i]/v;
				}
			}
		}
		else if(opt==2)
		{
			sum=0;
			cin>>l>>r;
			for(i=l-1;i<r;i++)
			{
				sum=sum+n[i];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
