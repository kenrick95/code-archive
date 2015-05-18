#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
 
using namespace std;
string kata[10001][2];
 
void qs(int left, int right) {
if (left<right) {
int l = left;
int r = right;
int piv = (left+right)/2;
 
while (l<=r) {
while ((kata[l][0] < kata[piv][0] || (kata[l][0]==kata[piv][0] && kata[l][1]<kata[piv][1])) && l<right) {
l++;
}
 
while ((kata[r][0] > kata[piv][0] || (kata[r][0]==kata[piv][0] && kata[r][1]>kata[piv][1])) && r>left) {
r--;
}
 
if (l<=r) {
 
string temp;
temp = kata[l][0];
kata[l][0] = kata[r][0];
kata[r][0] = temp;
 
temp = kata[l][1];
kata[l][1] = kata[r][1];
kata[r][1] = temp;
 
l++;
r--;
}
}
 
if (left < r) {
qs(left, r);
}
 
if (l < right) {
qs(l, right);
}
}
}
 
int main() {
int n;
int i;
string temp;
int maxpos, maxnum, tempnum, temppos;
string maxkata;
 
cin >> n;
for (i=0;i<n;i++) {
cin >> temp;
kata[i][0] = temp;
kata[i][1] = temp;
 
sort(kata[i][0].begin(), kata[i][0].end());
}
 
qs(0, n-1);
 
tempnum = 0;
maxnum = 0;
for (i=0;i<n;i++) {
if (i==0) {
tempnum = 1;
temppos = 0;
maxpos = i;
temp = kata[i][1];
maxkata = kata[i][1];
} else {
if (kata[i][0]!=kata[i-1][0]) {
if ((tempnum>=maxnum && temp<maxkata) || temppos==0) {
maxnum = tempnum;
maxpos = temppos;
maxkata = temp;
}
temppos = i;
tempnum = 1;
temp = kata[i][1];
} else {
tempnum++;
}
}
}
 
if ((tempnum>=maxnum && temp<maxkata) || temppos ==0) {
maxnum = tempnum;
maxpos = temppos;
maxkata = temp;
}
 
if (maxnum>1) {
cout << maxnum << endl;
for (i=maxpos;i<maxpos+maxnum;i++) {
cout << kata[i][1] << endl;
}
} else {
cout << "TIDAK ADA\n";
}
 
return 0;
}
