/************************************************************************************************************************************************
*                                                                                                                                               *
*																	Name-Shubham Gupta                                                          *
*																	CSE,MNNIT Allahabad                                                         *
*																	Email-shubhamgupta501@gmail.com                                             *
*************************************************************************************************************************************************/


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
 
int ar[2000+5][2000+5];
long long int d1[4000+10],d2[4000+10];
int main()
{
	//code goes here
	
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
	long long int sol[3];
	sol[0]=sol[1]=-1;
	pair<int,int> v[2];
	int n;
	scd1(n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scd1(ar[i][j]);
			d1[i+j]+=ar[i][j];
			d2[i-j+n]+=ar[i][j];	
		}	
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((i+j)%2==0&&sol[0]<(d1[i+j]+d2[i-j+n]-ar[i][j]))
			{
				v[0].first=i;
				v[0].second=j;
				sol[0]=d1[i+j]+d2[i-j+n]-ar[i][j];
			}
			else if((i+j)%2==1&&sol[1]<(d1[i+j]+d2[i-j+n]-ar[i][j]))
			{
				v[1].first=i;
				v[1].second=j;
				sol[1]=d1[i+j]+d2[i-j+n]-ar[i][j];
			}
		}
	}
	outll(sol[0]+sol[1]);
	printf("%d %d %d %d",v[0].first,v[0].second,v[1].first,v[1].second);
return 0;
}
