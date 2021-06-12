#include <iostream>
using namespace std;

class Bian
{
	public:
	int veradj;
	int cost;
	int kind;
	Bian * link;
	Bian();
};

class Head
{
	public:
	int vername;
    Bian * adjacent;
    Head();
};

class make
{
	public:
		void input();
		void depth(Head head,)
		void back();
	private:
    	Head head[1000];
    	int n,m;
    	int i,j,k;
    	int t,a,b,c;
    	Bian * p;
    	Bian * q;
};
