// PROBLEM :: TRANSITIVE CLOSURE OF GIVEN GRAPH USING DFS

// TIME COMPLEXITY :: O(V^2)

#include <bits/stdc++.h>
using namespace std;

void dfs(list<int>*adjList,bool **visited,int vertex,int reachable)
{
		visited[vertex][reachable]=true;

		list<int>::iterator it;
		for(it=adjList[reachable].begin();it!=adjList[reachable].end();++it)
		{
			if(visited[vertex][*it]==false)
				dfs(adjList,visited,vertex,*it);
		}
}


void transClosure(list<int>*adjList,int v)
{
	bool **closureMatrix;
	closureMatrix=new bool*[v];

	for(int i=0;i<v;i++)
	{
		closureMatrix[i]=new bool [v];
	}

	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			closureMatrix[i][j]=false;



	for(int i=0;i<v;i++)
	{
		dfs(adjList,closureMatrix,i,i);
	}

	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
			cout<<closureMatrix[i][j]<<" ";
		cout<<"\n";
	}


}
int main()
{
	int v=4;
	list<int>*adjList=new list<int>[v];

	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[1].push_back(2);
	adjList[2].push_back(0);
	adjList[2].push_back(3);
	adjList[3].push_back(3);

	transClosure(adjList,v);
}
