// PROBLEM :: FIND K CORES OF AN UNDIRECTED-GRAPH

#include <bits/stdc++.h>
using namespace std;

void addEdge(list<int>*&adjList,int u,int v)
{
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

bool dfsUtil(list<int>* adjList,bool visited[],int vOut[],int v,int k)
{
	visited[v]=true;

	list<int>::iterator it;

	for(it=adjList[v].begin();it!=adjList[v].end();++it)
	{
		if(vOut[v]<k)
			vOut[*it]--;
		if(visited[*it]==false)
		{
			if(dfsUtil(adjList,visited,vOut,*it,k))
				vOut[v]--;
		}
	}

	return (vOut[v]<k);
}
void kCores(list<int>*adjList,int v,int k)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;

	int vOut[v];

	int minOut=INT_MAX;
	int strtIndx;

	for(int i=0;i<v;i++)
	{
		vOut[i]=adjList[i].size();

		if(vOut[i]<minOut)
		{
			if(vOut[i]<minOut)
			{
				minOut=vOut[i];
				strtIndx=i;
			}
		}
	}


	dfsUtil(adjList,visited,vOut,strtIndx,k);

	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			dfsUtil(adjList,visited,vOut,i,k);
		}
	}

	// printing

	for(int i=0;i<v;i++){

		if(vOut[i]>=k)
		{
			cout<<"["<<i<<"]";
			list<int>::iterator it;
			for(it=adjList[i].begin();it!=adjList[i].end();++it)
			{
				if(vOut[*it]>=k)
					cout<<"->"<<*it;
			}
			cout<<"\n";
		}

	}

}
int main()
{
	int v=9;

	list<int>*adjList=new list<int>[v];

	addEdge(adjList,0,1);
	addEdge(adjList,1,2);
	addEdge(adjList,0,2);
	addEdge(adjList,1,5);
	addEdge(adjList,2,5);
	addEdge(adjList,5,8);
	addEdge(adjList,5,6);
	addEdge(adjList,2,6);
	addEdge(adjList,6,8);
	addEdge(adjList,2,4);
	addEdge(adjList,2,3);
	addEdge(adjList,3,6);
	addEdge(adjList,4,6);
	addEdge(adjList,4,3);
	addEdge(adjList,4,7);
	addEdge(adjList,6,7);
	addEdge(adjList,3,7);

	int k=3;
	kCores(adjList,v,k);
}
