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
 
long long int fact[1000000+2];

void calcFact(int n)
{
	fact[0]=fact[1]=1;
	for(int i=2;i<=n;i++)
	{
		fact[i]=((fact[i-1]%MOD)*(i%MOD))%MOD;
		fact[i]%=MOD;
	}
} 
long long int  pow(long long int  a,long long int b)
{
	long long int ans =1;
	while(b)
	{
		if(b&1)
		{
			ans=((ans%MOD)*(a%MOD))%MOD;
			ans%=MOD;
		}
		a=((a%MOD)*(a%MOD))%MOD;
		b>>=1;

	} 
	return ans;
}

int main()
{
	//code goes here
	int a,b,n;
	scd3(a,b,n);
	calcFact(n);
	long long int ans=0;
	for(int i=n;i>=0;i--)
	{
		long long int sum=(i*a)+(n-i)*b;
		int flag=0;
		while(sum!=0)
		{
			int rem=sum%10;
			if(rem==a||rem==b)
			{

			}
			else
			{
				flag=1;
				break;
			}
			sum=sum/10;
		}
		if(!flag)
		{
			ans+=((fact[n]*pow(fact[i],(MOD-2)))%MOD)*pow(fact[n-i],(MOD-2));
			ans=ans%MOD;
		}
	}
	outll(ans);
return 0;
}
