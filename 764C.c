	/**************************************************************************************************************
*                                                                                                              *
*				Name-Shubham Gupta                              											   *
*																	                                           *																                                         									*
****************************************************************************************************************/


#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<math.h>
#include<limits.h>

using namespace std;

//input
#define scd1(x)          scanf("%d",&(x))
#define scd2(x,y)    	 scanf("%d%d",&(x),&(y))
#define scd3(x,y,z) 	 scanf("%d%d%d",&(x),&(y),&(z))
#define sclld1(x)    	 scanf("%lld",&(x))
#define sclld2(x,y)    	 scanf("%lld%lld",&(x),&(y))
#define sclld3(x,y,z)    scanf("%lld%lld%lld",&(x),&(y),&(z))
#define scstr1(x)        scanf("%s",(x));
#define scstr2(x,y)      scanf("%s%s",(x),(y));


//output
#define out(x)           printf("%d\n",x)
#define out2(x,y)        printf("%d %d\n",x,y)
#define outll(x)         printf("%lld\n",x)
#define outll2(x,y)      printf("%lld %lld\n",x,y)
#define nl               printf("\n");


#define MP               make_pair
#define pb               push_back
#define rep(i,n)         for(int i=0;i<n;i++)
#define REP(i,a,b)       for(int i=a;i<=b;i++)
#define PER(i,a,b)       for(int i=b;i>=a;i--)
#define X                first
#define Y                second
#define all(c)           c.begin(),c.end()  //eg sort(all(v));

//for size and initialize
#define sz(a)            int((a).size())
#define clr(a)           memset(a,0,sizeof(a))
#define ini(a)           memset(a,-1,sizeof(a))


//cost
#define MAX 1000000
#define MOD 1000000007
#define pi  3.1415926536

typedef long long int lld;
 int curColor,check;
 vector<int>adj[100000+10];
int color[100000+10];

void dfs(int cur,int par)
{
	check =check&&(curColor==color[cur]);
	for(int i=0;i<adj[cur].size();i++)
	{
		if(adj[cur][i]!=par)
		{
			dfs(adj[cur][i],cur);
		}
	}
}


bool solve(int v)
{
	bool ans=true;
	for(int i=0;i<adj[v].size();i++)
	{
		curColor=color[adj[v][i]];
		check =true;
		dfs(adj[v][i],v);
		ans=check&&ans;
	}
	return ans;
}


int main()
{
	//code goes here
	int n,u,v,c;
	scd1(n);
	for(int i=0;i<n-1;i++)
	{
		scd2(u,v);
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	for(int i=0;i<n;i++)
	{
		scd1(color[i]);
	}
	int root1,root2;
	root1=root2=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			if(color[i]!=color[adj[i][j]])
			{
				root1=i;
				root2=adj[i][j];
			}
		}
	}
	if(root1==-1&&root2==-1)
	{
		printf("YES\n");
		out(1);
	}
	else
	{
		bool res1 =solve(root1);
		bool res2=solve(root2);
		if(res1)
		{
			printf("YES\n");
			out(root1+1);

		}
		else if(res2)
		{
			printf("YES\n");
			out(root2+1);

		}
		else
		{
			printf("NO\n");
		}
	}



	


return 0;
}
