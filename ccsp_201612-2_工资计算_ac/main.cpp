#include <iostream>
using namespace std;
 
int main(int argc, char** argv) 
{
	long long s,t;
	cin>>t;
	s=t;
	if(s<=3500)
	{
		cout<<s;
		return 0;
	}
	
	s=(t-105)*100/97;
	if(s>3500 && s<=5000)
	{
		cout<<s;
		return 0;
	}
	
	s=(t+45-500)*100/90;
	if(s>5000 && s<=8000)
	{
		cout<<s;
		return 0;
	}	
	
	s=(t+345-1600)*10/8;
	if(s>8000 && s<=12500)
	{
		cout<<s;
		return 0;
	}
	
	s=(t+1245-125*25)*100/75;
	if(s>12500 && s<=38500)
	{
		cout<<s;
		return 0;
	}	
	
	s=(t+7745-0.3*38500)*10/7;
	if(s>38500 && s<=58500)
	{
		cout<<s;
		return 0;
	}
	
	s=(t+13745-0.35*58500)*100/65;
	if(s>58500 && s<=83500)
	{
		cout<<s;
		return 0;
	}	
	
	s=(t+22495-83500*0.45)*100/55;
	if(s>83500)
	{
		cout<<s;
		return 0;
	}
}
