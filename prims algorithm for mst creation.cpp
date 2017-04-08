
#include<bits/stdc++.h>
using namespace std;


int findMin(bool visited[],int key[],int v)
{
	int min=INT_MAX;int minIndex;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false && key[i]<min)
		{
			min=key[i];minIndex=i;
		}
	}
	return minIndex;
}
void printMST(int**adjMat,int v)
{
	bool visited[v];
	int parent[v];
	int key[v];

	for(int i=0;i<v;i++)
	{
		key[i]=INT_MAX;
		visited[i]=false;
		parent[i]=-1;
	}

	key[0]=0;

	for(int i=0;i<v;i++)
	{
		int u= findMin(visited,key,v);

		visited[u]=true;

		for(int k=0;k<v;k++)
		{
			if(adjMat[u][k] && visited[k]==false && adjMat[u][k]<key[k])
			{
				parent[k]=u; key[k]=adjMat[u][k];
			}
		}
	}

	// printing the MST

	cout<<"  edge          weight\n";
	for(int i=1;i<v;i++)
	{
		cout<<parent[i]<<"----->"<<i<<"           "<<key[i]<<"\n";
	}
}
int main()
{
	int v;
	cout<<"enter the number of vertices\n";
	cin>>v;

	int* *adjMat=new int*[v];
	for(int i=0;i<v;i++)
	{
		adjMat[i]=new int[v];
	}

	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			cin>>adjMat[i][j];

	printMST(adjMat,v);
}
