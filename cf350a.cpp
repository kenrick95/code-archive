#include <iostream>
using namespace std;
int main() {
	int v = 0;
	int n,m;
	int i;
	cin>>n;
	cin>>m;
	int a[110],b[110];
	int mina,minb,maxa,maxb;
	mina = minb = 1000000007;
	maxa = maxb = -1;
	for (i = 0; i<n; i++)
	{
		cin>>a[i];
		mina = min(mina, a[i]);
		maxa = max(maxa, a[i]);
	}
	for (i = 0; i<m; i++)
	{
		cin>>b[i];
		minb = min(minb, b[i]);
		maxb = max(maxb, b[i]);
	}
	v = max(maxa, 2*mina);
	v < minb ? cout<<v : cout<<"-1";
	cout<<endl;
}
