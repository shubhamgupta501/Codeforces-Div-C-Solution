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
 

int main()
{
	//code goes here
	int n,p;
	vector<int> v;
	scd2(n,p);
	char str[100000+5];
	scstr1(str);
	p--;
	if(n%2==0)
	{
		if(p<n/2)
		{
			if((p-0)<(n/2-1-p))
			{
				for(int i=p;i>=0;i--)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
				for(int i=p+1;i<(n/2);i++)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
			}
			else
			{
				for(int i=p;i<(n/2);i++)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
				for(int i=p-1;i>=0;i--)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
			}
		}
		else
		{
			if((p-n/2)<(n-1-p))
			{
				for(int i=p;i>=(n/2);i--)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
				for(int i=p+1;i<n;i++)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
			}
			else
			{
				for(int i=p;i<n;i++)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}

				}
				for(int i=p-1;i>=n/2;i--)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
			}
		}
	}
	else
	{
		if(p<n/2)
		{
			if((p-0)<(n/2-1-p))
			{
				for(int i=p;i>=0;i--)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
				for(int i=p+1;i<(n/2);i++)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
			}
			else
			{
				
				for(int i=p;i<n/2;i++)
				{
					//printf("lopp %d",n);
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
				for(int i=p-1;i>=0;i--)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
			}
		}
		else if(p>=n/2)
		{
			if((p-n/2-1)<(n-1-p))
			{
				for(int i=p;i>(n/2);i--)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
				for(int i=p+1;i<n;i++)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
			}
			else
			{
				for(int i=p;i<n;i++)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
				for(int i=p-1;i>(n/2);i--)
				{
					if(str[i]!=str[n-i-1])
					{
						v.push_back(i);
					}
				}
			}
		}
		
	}
	int ch1,ch2,ans=0;
	for(int i=0;i<v.size();i++)
	{
		ch1= str[v[i]]-'a';
		ch2=str[n-v[i]-1]-'a';
		if(i==0)
		{
			ans+=abs(v[i]-p);
			
		}
		else
		{
			ans+=abs(v[i]-v[i-1]);
		}
		if(ch1>ch2)
				swap(ch1,ch2);
			ans+=min(abs(ch1+(26-ch2)),abs(ch1-ch2));
	}
	out(ans);
	

	


return 0;
}
