// PROBLEM :: RAT IN A MAZE PROBLEM

#include<bits/stdc++.h>
using namespace std;

#define N 4


bool isSafe(int mat[N][N],int r,int c)
{
	if((r>=0 && r<N) && (c>=0 && c<N) && (mat[r][c]!=0))
		return true;
	return false;
}


void printMat(int mat[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<mat[i][j]<<" ";
		cout<<"\n";
	}
}
bool solveMazeUtil(int mat[N][N],int r,int c,int sol[N][N])
{
	if(r==N-1 && c==N-1)
	{
		sol[r][c]=1;
		return true;
	}
	if(isSafe(mat,r,c))
	{
		sol[r][c]=1;
		if(solveMazeUtil(mat,r,c+1,sol)==true)
			return true;
		if(solveMazeUtil(mat,r+1,c,sol)==true)
			return true;

		sol[r][c]=0;
		return false;
	}
	return false;
}
bool solveMaze(int mat[N][N])
{
	int sol[N][N]={ {0, 0, 0, 0},
	        {0, 0, 0, 0},
	        {0, 0, 0, 0},
	        {0, 0, 0, 0}
	    };

	if(solveMazeUtil(mat,0,0,sol))
	{
		printMat(sol);
		return true;
	}
	return false;
}
int main()
{
	int mat[N][N]={ {1, 0, 0, 0},
	        {1, 1, 0, 1},
	        {0, 1, 0, 0},
	        {1, 1, 1, 1}
	    };

	if(!solveMaze(mat))
		cout<<"there is no path\n";
}
