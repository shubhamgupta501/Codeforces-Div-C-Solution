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
 
char str[1000000+5];
int rem1[1000000+10];
int rem2[1000000+10];

int main()
{
	//code goes here
	
	scstr1(str);
	long long int a,b,num1=0;
	sclld2(a,b);
	int n=strlen(str);
		int rem;
	for(int i=0;i<n;i++)
	{
		num1=num1*10+(str[i]-'0');
		rem=num1%a;
		rem1[i]=rem;
		num1=rem;
	}
	
	rem2[n-1]=str[n-1]-'0';
	num1=0;
	long long int raise =1;
	for(int i=n-1;i>=0;i--)
	{
		num1=(raise*(str[i]-'0'))%b+(num1%b);
		rem=num1%b;
		rem2[i]=rem;
		num1=rem;
		raise*=10;
		raise =raise%b;
	}
	int bp=-1;
	for(int i=0;i<n-1;i++)
	{
		if(rem1[i]==0&&rem2[i+1]==0&&str[i+1]!='0')
		{
			bp= i;
			break;
		}
	}
	if(bp!=-1)
	{
		printf("YES\n");
		for(int i=0;i<=bp;i++)
		{
			printf("%c",str[i]);
		}
		nl;
		printf("%s",str+bp+1);
	}
	else
	{
		printf("NO\n");
		out(-1);
	}	
		

return 0;
}
