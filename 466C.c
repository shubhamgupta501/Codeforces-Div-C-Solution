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
#define sclld3(x,y,z)    scanf("%lld",&(x),&(y),&(z))
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
 

int main()
{
	//code goes here
	int n,ar[5*100000+10];
	long long int count[5*100000+10],sum1=0,sum2=0;
	scd1(n);
	clr(count);
	for(int i=0;i<n;i++)
	{
		scd1(ar[i]);
		sum1+=ar[i];
	}
	if(sum1%3!=0)
	{
		out(0);
	}
    else
    {	
    	long long int ans=0;
    	sum1=sum1/3;
    	sum2=0;

		for(int i=n-1;i>=0;i--)
		{
			sum2+=ar[i];
			if(sum2==sum1)
				count[i]=1;
		}
		for(int i=n-2;i>=0;i--)
		{
			count[i]+=count[i+1];
		}
		sum2=0;
		for(int i=0;i<n-2;i++)
		{
			sum2+=ar[i];
			if(sum2==sum1)
			{
				ans+=count[i+2];
			}

		}
		outll(ans);
	}

	


return 0;
}
