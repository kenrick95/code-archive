#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	bool ans = true;
	int a[10];
	int temp;
	int i;
	for (i=0; i<4; i++)
		a[i] = 0;
	for (i=0; i<n; i++)
	{
		cin>>temp;
		if (temp == 25) {
			a[1]++;
		} else if (temp == 50) {
			a[2]++;
			a[1]--;
		} else if (temp == 100) {
			a[3]++;
			if (a[2] > 0) {
				a[2]--;
				a[1]--;
			} else {
				a[1] -= 3;
			}
		}
		//cout << a[1] <<" " << a[2] << " " <<a[3]<<endl;
		if (min(min(a[1],a[2]),a[3]) < 0)
		{
			ans = false;
			break;
		}
	}
	ans ? cout<<"YES" : cout<<"NO";
	cout<<endl;
	return 0;
}
