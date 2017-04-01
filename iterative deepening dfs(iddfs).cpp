// PROBLEM :: ITERATIVE DEEPENING DFS(IDDFS)

#include <bits/stdc++.h>
using namespace std;


bool dfs(list<int>*adjList,int target,int src,int max_depth)
{
	if(src==target)
		return true;

	if(max_depth<=0)
		return false;

	list<int>::iterator it;
	for(it=adjList[src].begin();it!=adjList[src].end();++it)
	{
		if ((dfs(adjList,target,*it,max_depth-1))==true)
			return true;
	}

	return false;
}

bool iddfs(list<int>*adjList,int target,int src ,int max_depth)
{
	for(int i=1;i<=max_depth;i++)
	{
		if(dfs(adjList,target,src,max_depth))
			return true;
	}
	return false;
}
int main()
{
	int v=7;
	list<int>*adjList=new list<int>[v];

	adjList[0].push_back(1);
	adjList[0].push_back(2);
	adjList[1].push_back(3);
	adjList[1].push_back(4);
	adjList[2].push_back(5);
	adjList[2].push_back(6);

	int target=6,src=0,max_depth=3;

	if(iddfs(adjList,target,src,max_depth))
		cout<<"reachable\n ";
	else
		cout<<"not-reachable\n";

}
