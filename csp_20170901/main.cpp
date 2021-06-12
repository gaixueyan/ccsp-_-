#include <iostream>
using namespace std;

int main()
{
	int money,n,m;
	cin>>money;
	int zuizhong=money/10;//初始得到瓶数，单瓶买 
	int max=money/50;
	int i,j;
	int zanshiy=0,zanshix,zanshi;
	for(i=max;i>=0;i--)
	{
		n=money;
		n=n-i*50;
		zanshi=zanshiy;
		zanshi=zanshi+i*7;
		int mid=n/30;
		for(j=mid;j>=0;j--)
		{
			m=n;
			m=m-j*30;
			zanshix=zanshi;
			zanshix=zanshix+j*4;
			zanshix=zanshix+(m/10);
			if(zanshix>zuizhong)
			{
				zuizhong=zanshix;
			}
		}
	}
	cout<<zuizhong;
	return 0;
}
