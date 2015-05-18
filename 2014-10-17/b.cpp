#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cfloat>
#include<bitset>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
#define Joshua using
#define is namespace
#define awesome std
Joshua is awesome;

typedef long long			ll;
typedef long double         ld;
typedef pair<int,int>       pi;
typedef pair<ll,ll>         pl;
typedef pair<double,double> pd;
typedef vector<int>         vi;
typedef vector<ll>          vl;
typedef vector<pi>          vii;
typedef vector<pl>          vll;
typedef vector<pd>          vdd;
typedef vector<vi>          vvi;
typedef vector<vl>          vvl;

#define fi first
#define se second
#define pq priority_queue
#define SORT(a) sort(a.begin(),a.end())
#define DEBUG(a) printf("DEBUG %s\n",#a)
#define VALUE(a) printf("value of %s is %d\n",#a,a)
#define VALUELL(a) printf("value of %s is %lld\n",#a,a)
#define FORU(a,b,c) for(int a=b;a<c;++a)
#define FORD(a,b,c) for(int a=b-1;a>=c;--a)
#define MP(a,b) make_pair(a,b)
#define bikin_popcorn __builtin_popcount
#define iswhite(a) (a==' '||a=='\n')
#define pb push_back
#define pf push_front
#define db pop_back
#define df pop_front
#define PI 3.14159265
#define INF 100000000
#define MOD 1000
#define EPS 1E-9
#define MXN 1000
//#define getchar getchar_unlocked

template <class T> inline void getint(T &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar()) && (!isdigit(c) && c!='-'));
	if (c=='-'){
		neg=1;
		c=getchar();
	}
	do num=num*10+c-'0';
	while ((c=getchar()) && isdigit(c));
	num*=(neg)?-1:1;
}

int t,n,k;
int inp[210];
double a,b,c;
double arr[210];
void gen(int st,int ed,double mul){
	if (st>ed||mul<0.00000000000001F) return;
	double len=ed-st+1;
	FORU(i,st,ed+1){
		arr[i]+=mul*a/len;
		gen(st,i-1,mul*b/len);
		gen(i+1,ed,mul*c/len);
	}
	return;
}

int main(){
	/*   scanf("%d %lf %lf",&k,&a,&b);
	    c=1;
	    c=c-a-b;
		FORU(i,0,k) arr[i]=0;
	 	gen(0,k-1,1);*/
	while(scanf("%d",&n)>=0){
        if (n < 0) break;
		vi srt;
		FORU(i,0,n) {
			getint(inp[i]);
			srt.pb(inp[i]);
		}
	    scanf("%d %lf %lf",&k,&a,&b);
	    
		int tar=-1, las=-1, cnt=0;
		sort(srt.begin(),srt.end());
		FORU(i,0,srt.size()){
			if (srt[i]!=las){
				++cnt;
				las=srt[i];
			}
			if (cnt==k){
				tar=srt[i];
				break;
			}
		}
		//printf("%d\n",tar);
	    c=1;
	    c=c-a-b;
		FORU(i,0,n) arr[i]=0;
	    gen(0,n-1,1);
	    double tot=0;
	    FORU(i,0,n){
	    	if (inp[i]==tar) tot+=arr[i];
		} 
		printf("%.3lf\n",tot);
	}
    return(0);
}
