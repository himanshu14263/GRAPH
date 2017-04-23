#include <bits/stdc++.h>
using namespace std;

void addEdges(list<pair<int,int> >*adjLst,int src,int dst,int weight)
{
	adjLst[src].push_back(make_pair(dst,weight));
	adjLst[dst].push_back(make_pair(src,weight));
}


bool findPathMoreThanKUtil(list<pair<int,int> >*adjLst,vector<bool>&visited,int src,int k)
{
	if(k<=0)
		return true;

	list<pair<int,int> >::iterator it;

	for(it=adjLst[src].begin();it!=adjLst[src].end();++it)
	{
		int v=(*it).first;
		int w=(*it).second;

		if(visited[v]==true)
			continue;

		if(w>=k)
			return true;

		visited[v]=true;

		if(findPathMoreThanKUtil(adjLst,visited,v,k-w))
			return true;

		visited[v]=false;
	}

	return false;

}
bool findPathMoreThanK(list<pair<int,int> >*adjLst,int src,int k,int v)
{
	vector<bool>visited(v,false);
	visited[src]=true;
	return findPathMoreThanKUtil(adjLst,visited,src,k);
}
int main()
{
	int v;
	cout<<"enter the number of vertex\n";
	cin>>v;
	list<pair<int,int> >*adjLst=new list<pair<int,int> >[v];

	cout<<"enter the number of edges\n";
	int e;
	cin>>e;

	for(int i=0;i<e;i++)
	{
		int s,d,w;
		cout<<"enter source,destination and weight\n";
		cin>>s>>d>>w;
		addEdges(adjLst,s,d,w);
	}

	int k,src;
	cout<<"enter the value of k and src\n";
	cin>>k>>src;
	if(findPathMoreThanK(adjLst,src,k,v))
		cout<<"there is a path\n";
	else
		cout<<"no path is there\n";

}
