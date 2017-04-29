#include<bits/stdc++.h>
using namespace std;

#define N 8

int sol[N][N];

bool isSafe(int r,int c,int sol[N][N])
{
	if(r>=0 && r<8 && c>=0 && c<8 && sol[r][c]==-1)
		return 1;
	else
		return false;
}
bool ktUtil(int r,int c,int k,int sol[N][N],int xMove[],int yMove[])
{
	if(k==N*N)
		return true;

	for(int i=0;i<N;i++)
	{
		int nextX=r+xMove[i];
		int nextY=c+yMove[i];

		if(isSafe(nextX,nextY,sol))
		{
			sol[nextX][nextY]=k;
			if(ktUtil(nextX,nextY,k+1,sol,xMove,yMove))
				return true;
			else
				sol[nextX][nextY]=-1;

		}
	}

	return false;
}
void kt()
{

	int sol[N][N];

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			sol[i][j]=-1;

	int xMove[N]={2, 1, -1, -2, -2, -1,  1,  2};
	int yMove[N]={1, 2,  2,  1, -1, -2, -2, -1};

	sol[0][0]=0;

	if(ktUtil(0,0,1,sol,xMove,yMove)==false)
	{
		cout<<"solution doesn't exists\n";
	}
	else
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				cout<<sol[i][j]<<"\t";
			cout<<"\n\n\n";
		}
	}
}
int main()
{

	kt();

}
