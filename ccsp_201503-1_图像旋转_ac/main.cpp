/*��һ��˼·��ֱ��������У�Ҫ���ǽ�����������*/

/*˵��1000��1000����һ��Ͳ�ְ����Ѵ����鿪��main�ⲻ�����*/
 
#include <iostream>
using namespace std;
	int a[1005][1005];
int main(int argc, char** argv) 
{
	//���� 
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
