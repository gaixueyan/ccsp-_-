#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
// ‰»Î 
	int n;
	cin>>n;
//º∆À„ 
	int nping;
	nping=n/10;
	int nping5,nping3,nping1;
	nping5=nping/5;
	nping3=nping%5/3;
	nping1=nping%5%3;
	int jiangyou=0;
	jiangyou=nping5*7+nping3*4+nping1;
	cout<<jiangyou;
	return 0;
}
