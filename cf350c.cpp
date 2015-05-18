#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct point {
	int x,y;
} node[100100];
bool comp (point A, point B) {
	return (abs(A.x) + abs(A.y)) < (abs(B.x) + abs(B.y));
}

int main() {
	int n;
	cin>>n;
	int i,k;
	k = 0;
	for (i = 0; i < n; i++)
	{
		cin>>node[i].x;
		cin>>node[i].y;
		if ((node[i].x== 0) ||  (node[i].y == 0))
		{
			k += 4;
		}
		else
		{
			k += 6;
		}
	}
	sort(node, node+n, comp);
	/*for (i = 0; i < n; i++)
	{
		cout<<node[i].x<<" "<<node[i].y<<endl;
	}*/
	cout<<k;
	cout<<endl;
	for (i = 0; i < n; i++)
	{
		if (node[i].x != 0)
		{
			cout<<"1 ";
			cout<<abs(node[i].x)<<" ";
			node[i].x > 0 ? cout <<"R" : cout <<"L";
			cout<<endl;
		}
		if (node[i].y != 0)
		{
			cout<<"1 ";
			cout<<abs(node[i].y)<<" ";
			node[i].y > 0 ? cout <<"U" : cout <<"D";
			cout<<endl;
		}
		cout<<"2";
		cout<<endl;
		
		if (node[i].x != 0)
		{
			cout<<"1 ";
			cout<<abs(node[i].x)<<" ";
			node[i].x < 0 ? cout <<"R" : cout <<"L";
			cout<<endl;
		}
		if (node[i].y != 0)
		{
			cout<<"1 ";
			cout<<abs(node[i].y)<<" ";
			node[i].y < 0 ? cout <<"U" : cout <<"D";
			cout<<endl;
		}
		
		cout<<"3";
		cout<<endl;
	}
}
