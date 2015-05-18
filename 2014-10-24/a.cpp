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

int t,n,m,s,a,b;
double v,r1,c1,r2,c2;
vector<pair<int,pd> > adjlist[110];
double tmax[110];
 

bool belford(){  
	//printf("%d %.3lf\n",dex,mon);
	tmax[s]=v;
	FORU(it,0,n-1){
		FORU(dex,1,n+1) if (tmax[dex]>=0){
			double mon=tmax[dex];
			FORU(i,0,adjlist[dex].size()){
				int tar=adjlist[dex][i].fi;
				double rat=adjlist[dex][i].se.fi;
				double com=adjlist[dex][i].se.se;
				double nex=(mon-com)*rat;
				if (nex<=0) continue;
				if (tmax[tar]>=0){
					if (tmax[tar]<nex) {
						//printf("update %lf %lf\n",tmax[tar],nex);
						tmax[tar]=nex;
					}
				} else {
					//printf("update %lf %lf\n",tmax[tar],nex);
					tmax[tar]=nex;
				}
			} 
		}
	}
	bool fnd=false;
	FORU(dex,1,n+1) if (tmax[dex]>=0){
		double mon=tmax[dex];
		FORU(i,0,adjlist[dex].size()){
			int tar=adjlist[dex][i].fi;
			double rat=adjlist[dex][i].se.fi;
			double com=adjlist[dex][i].se.se;
			double nex=(mon-com)*rat;
			if (nex<=0) continue;
			if (tmax[tar]>=0){
				if (tmax[tar]<nex) {
					//printf("stillupdate %lf %lf\n",tmax[tar],nex);
					tmax[tar]=nex;
					fnd=true;
				}
			} else {
					//printf("stillupdate %lf %lf\n",tmax[tar],nex);
				tmax[tar]=nex;
				fnd=true;
			}
		} 
	}
	return fnd;
}

int main(){ 
    scanf("%d %d %d %lf",&n,&m,&s,&v);
    FORU(i,0,m){
    	scanf("%d %d %lf %lf %lf %lf",&a,&b,&r1,&c1,&r2,&c2);
    	adjlist[a].pb(MP(b,MP(r1,c1)));
    	adjlist[b].pb(MP(a,MP(r2,c2)));
	}
	//dijkstra starting from F
	FORU(i,0,n+1) tmax[i]=-1;
	printf("%s\n",belford()?"YES":"NO");
    return(0);
}
