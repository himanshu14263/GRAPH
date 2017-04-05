// detect cycle in undirected-graph using union-find algorithm

#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int src,dest;

};

int finD(int parent[],int i)
{
	if(parent[i]==-1)
		return i;
	return finD(parent,parent[i]);
}

void unioN(int parent[],int x,int y)
{
	int xset=finD(parent,x);
	int yset=finD(parent,y);

	parent[xset]=yset;
}
bool isCycle(vector<pair<int,int> >graph,int v,int e)
{
	int parent[v];
	for(int i=0;i<v;i++)
		parent[i]=-1;

	for(int i=0;i<e;i++)
	{
		if(finD(parent,graph[i].first)==finD(parent,graph[i].second))
			return true;
		unioN(parent,graph[i].first,graph[i].second);
	}
	return false;
}
int main()
{
	vector<pair<int,int> >graph;

	int e,v;

	cout<<"enter the number of vertices in the graph\n";
	cin>>v;

	cout<<"enter the number of edges in the graph\n";
	cin>>e;

	cout<<"enter the edges :: \n";

	for(int i=0;i<e;i++)
	{
		cout<<"enter source and destination for edge :: "<<i<<"\n";
		int src,dest;
		cin>>src>>dest;
		graph.push_back(make_pair(src,dest));
	}

	if(isCycle(graph,v,e))
		cout<<"cycle is present\n";
	else
		cout<<"cycle isn't present\n";
}
