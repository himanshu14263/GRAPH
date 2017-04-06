// PROBLEM :: FIND CYCLE IN UNDIRECTED GRAPH USING DFS

#include <bits/stdc++.h>
using namespace std;

void addEdges(list<int>adjList[],int u,int v)
{
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

bool dfsUtil(list<int>adjList[],bool visited[],int v,int parent)
{
	visited[v]=true;

	list<int>::iterator it;
	for(it=adjList[v].begin();it!=adjList[v].end();++it)
	{
		if(visited[*it]==false)
		{
			if(dfsUtil(adjList,visited,*it,v))
				return true;
		}
		else if(parent==*it)
			return true;
	}
	return false;
}
bool findCycle(list<int>adjList[],int v,int e)
{
	bool visited[v];
	memset(visited,false,sizeof(visited));

	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			if(dfsUtil(adjList,visited,i,-1))
					return true;
		}
	}
	return false;
}
int main()
{
	int v;
	cout<<"enter the number of vertices\n";
	cin>>v;
	list<int>adjList[v];

	int e;
	cout<<"enter the number of edges\n";
	cin>>e;

	for(int i=0;i<e;i++)
	{
		cout<<"enter the edges\n";
		int e1,e2;
		cin>>e1>>e2;
		addEdges(adjList,e1,e2);
	}

	if(findCycle(adjList,v,e))
		cout<<"\ncycle is present\n";
	else
		cout<<"\ncycle isn't present\n";
}
