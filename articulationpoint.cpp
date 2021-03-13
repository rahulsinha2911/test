#include<bits/stdc++.h>
using namespace std;
int t=0;
int child=0;
int root=1;
vector<int>v[3445];
int count=0;
void art(int x,int vis[],int dis[],int low[],int par[],int ap[] )
{
	vis[x]=1;
	if(x==1)
	low[x]=dis[x]=++t;
	for(int i=0;i<v[x].size();i++)
	{
		int k=vis[v[x][i]];
		if(vis[k]==0)
		{
			child++;
			par[k]=x;
			art(k,vis,dis,low,par,ap);
            low[x]=min(low[x],low[k]);	
		
			if(par[x]==-1 && child>=2)
			{
				count++;
			}
			if(par[x]==-1 && low[k]>=dis[x])
			{
				count++;
			}
		}
			else if(par[x]!=k)
			low[x]=min(low[x],dis[k]);
		}
}
int main()
{cout<<"type all the input\n";
	int n,m;
	cin>>n>>m;
	int vis[n+1];
	int dis[n+1];
	int low[n+1];
	int par[n+1];
	int ap[n+1];
	for(int i=1;i<=n;i++)
	{
		par[i]=-1;
		vis[i]=0;
		ap[i]=0;
    }
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	void art(1,vis,dis,low,par,ap);
	cout<<count;
}
