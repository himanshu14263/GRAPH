// PROBLEM :: FIND CYCLE IN DIRECTED GRAPH USING COLORS

// TIME COMPLEXITY :: O(V+E) same as that of dfs

#include<bits/stdc++.h>
using namespace std;

const int white =0;
const int grey =1;
const int black= 2;

void addEdges(list<int>adjList[],int u,int v)
{
	adjList[u].push_back(v);
}

bool dfsUtil(list<int>adjList[],int visitedColor[],int v)
{
	visitedColor[v]=grey;
	list<int>::iterator it;
	for(it=adjList[v].begin();it!=adjList[v].end();++it)
	{
		if(visitedColor[*it]==grey)
					return true;

		if(visitedColor[*it] == white)
		{
			if(dfsUtil(adjList,visitedColor,*it))
				return true;
		}
	}

	visitedColor[v]=black;
	return false;
}
bool findCycle(list<int>adjList[],int v)
{
	int vertexColor[v];
	for(int i=0;i<v;i++)
		vertexColor[i]=white;

	for(int i=0;i<v;i++)
	{
		if(vertexColor[i] == white)
		{
			if(dfsUtil(adjList,vertexColor,i))
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

	if(findCycle(adjList,v))
		cout<<"\ncycle is present\n";
	else
		cout<<"\ncycle isn't present\n";
}
