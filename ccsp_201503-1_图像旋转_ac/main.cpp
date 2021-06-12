/*换一种思路，直接输出就行，要的是结果！是输出！*/

/*说了1000就1000，差一点就差分啊，把大数组开到main外不会崩溃*/
 
#include <iostream>
using namespace std;
	int a[1005][1005];
int main(int argc, char** argv) 
{
	//输入 
	int n,m;
	cin>>n>>m;

	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}


    for(int j=m-1; j>=0; j--) {
        for(int i=0; i<n; i++) {
        	cout << a[i][j];
            if(i!= n-1)
            {
            	cout << " ";
			} 
        }
        if(j!=0)
        {
    	     cout << endl;       	
		}
	}
	return 0;
}
