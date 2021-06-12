#include <iostream>
using namespace std;
#include <string>

string gai;
string a[1005];
int b[1005][3];

int wanjia1[8][3];
int wanjia2[8][3];

int main(int argc, char** argv) 
{
	//输入 
	int n;
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>gai;
		a[i]=gai;
		if(a[i]=="summon")
		{
			cin>>b[i][0]>>b[i][1]>>b[i][2];
		}
		else if(a[i]=="attack")
		{
			cin>>b[i][0]>>b[i][1];
		}
	}
	//赋初值
	wanjia1[0][0]=1;
	wanjia1[0][1]=0;
	wanjia1[0][2]=30; 
	wanjia2[0][0]=1;
	wanjia2[0][1]=0;
	wanjia2[0][2]=30; 
	for(i=1;i<8;i++)
	{
		wanjia1[i][0]=0;
		wanjia1[i][1]=0;
		wanjia1[i][2]=0;
		wanjia2[i][0]=0;
		wanjia2[i][1]=0;
		wanjia2[i][2]=0;
	}
	//计算
	int dangqian;
	dangqian=1;//1为先手玩家，-1为后手玩家
	int j;
	for(i=0;i<n;i++)
	{
		if(a[i]=="summon")
		{
			if(dangqian==1)
			{
				if(wanjia1[b[i][0]][0]==0)
				{
					wanjia1[b[i][0]][0]=1;
					wanjia1[b[i][0]][1]=b[i][1];
					wanjia1[b[i][0]][2]=b[i][2];
				}
				else
				{
					for(j=7;j>b[i][0];j--)
					{
						wanjia1[j][0]=wanjia1[j-1][0];
						wanjia1[j][1]=wanjia1[j-1][1];
						wanjia1[j][2]=wanjia1[j-1][2];
					}
					wanjia1[b[i][0]][0]=1;
					wanjia1[b[i][0]][1]=b[i][1];
					wanjia1[b[i][0]][2]=b[i][2];					
				}
			}
			else if(dangqian==-1)
			{
				if(wanjia2[b[i][0]][0]==0)
				{
					wanjia2[b[i][0]][0]=1;
					wanjia2[b[i][0]][1]=b[i][1];
					wanjia2[b[i][0]][2]=b[i][2];
				}
				else
				{
					for(j=7;j>b[i][0];j--)
					{
						wanjia2[j][0]=wanjia2[j-1][0];
						wanjia2[j][1]=wanjia2[j-1][1];
						wanjia2[j][2]=wanjia2[j-1][2];
					}
					wanjia2[b[i][0]][0]=1;
					wanjia2[b[i][0]][1]=b[i][1];
					wanjia2[b[i][0]][2]=b[i][2];					
				}
			}			
		}
		else if(a[i]=="attack")
		{
			if(dangqian==1)
			{
				wanjia1[b[i][0]][2]=wanjia1[b[i][0]][2]-wanjia2[b[i][0]][1];
				wanjia2[b[i][0]][2]=wanjia2[b[i][0]][2]-wanjia1[b[i][0]][1];
				if(wanjia1[b[i][0]][2]<=0)
				{
					wanjia1[b[i][0]][0]=0;
					for(j=b[i][0];j<n-1;j++)
					{
						wanjia1[j][0]=wanjia1[j+1][0];
						wanjia1[j][1]=wanjia1[j+1][1];
						wanjia1[j][2]=wanjia1[j+1][2];
					}
					wanjia1[7][0]=0;
					wanjia1[7][1]=0;
					wanjia1[7][2]=0;
				}
				if(wanjia2[b[i][0]][2]<=0)
				{
					wanjia2[b[i][0]][0]=0;
					for(j=b[i][0];j<n-1;j++)
					{
						wanjia2[j][0]=wanjia2[j+1][0];
						wanjia2[j][1]=wanjia2[j+1][1];
						wanjia2[j][2]=wanjia2[j+1][2];
					}
					wanjia2[7][0]=0;
					wanjia2[7][1]=0;
					wanjia2[7][2]=0;
				}
			}
			else if(dangqian==-1)
			{
				wanjia2[b[i][0]][2]=wanjia2[b[i][0]][2]-wanjia1[b[i][0]][1];
				wanjia1[b[i][0]][2]=wanjia1[b[i][0]][2]-wanjia2[b[i][0]][1];
				if(wanjia2[b[i][0]][2]<=0)
				{
					wanjia2[b[i][0]][0]=0;
					for(j=b[i][0];j<n-1;j++)
					{
						wanjia2[j][0]=wanjia2[j+1][0];
						wanjia2[j][1]=wanjia2[j+1][1];
						wanjia2[j][2]=wanjia2[j+1][2];
					}
					wanjia2[7][0]=0;
					wanjia2[7][1]=0;
					wanjia2[7][2]=0;
				}
				if(wanjia1[b[i][0]][2]<=0)
				{
					wanjia1[b[i][0]][0]=0;
					for(j=b[i][0];j<n-1;j++)
					{
						wanjia1[j][0]=wanjia1[j+1][0];
						wanjia1[j][1]=wanjia1[j+1][1];
						wanjia1[j][2]=wanjia1[j+1][2];
					}
					wanjia1[7][0]=0;
					wanjia1[7][1]=0;
					wanjia1[7][2]=0;
				}
			}
		}
		else
		{
			dangqian=dangqian*-1;
		}
	} 
	//输出
	if(wanjia2[0][0]==0)
	{
		cout<<1;
	} 
	else if(wanjia1[0][0]==0)
	{
		cout<<-1;
	}
	else
	{
		cout<<0;
	}
	cout<<endl;
	cout<<wanjia1[0][2]<<endl;
	int sum1=0;
	for(i=1;i<8;i++)
	{
		if(wanjia1[i][0]==1)
		{
			sum1++;
		}
	}
	cout<<sum1<<" ";
	for(i=1;i<8;i++)
	{
		if(wanjia1[i][0]==1)
		{
			cout<<wanjia1[i][2]<<" ";
		}
	}
	cout<<endl;
	cout<<wanjia2[0][2]<<endl;
	int sum2=0;
	for(i=1;i<8;i++)
	{
		if(wanjia2[i][0]==1)
		{
			sum2++;
		}
	}
	cout<<sum2<<" ";
	for(i=1;i<8;i++)
	{
		if(wanjia2[i][0]==1)
		{
			cout<<wanjia2[i][2]<<" ";
		}
	}
	return 0;
}
