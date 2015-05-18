#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdlib>
#define DEBUG printf("TEST\n")
 
using namespace std;
 
int N, i;
long long ou;
 
struct bebek{
  long long P, S;
} b[100010];
 
bool comp(bebek A, bebek B){
  if(A.P < B.P) return true;
  return false;
}
 
bool cek(long long n){
   //cout<<n<<" ";
  long long bonbon = 0, skrg = 0;
  for(int i = 1; i <= N; ++i){
    skrg = b[i].S + bonbon;
    if(i == N) break;
    if(skrg < n) bonbon = (skrg - n) + (b[i].P - b[i + 1].P);
    else{
      bonbon = (skrg - n) + (b[i].P - b[i + 1].P);
      if(bonbon < 0) bonbon = 0;
    }
  }
  //cout<<bonbon<<endl;
  if(skrg < n) return false;
  return true;
}
 
long long bins(long long l, long long r){
  if(l == r) return l;
  else{
    long long mid = (l + r) / 2;
    if(cek(mid)){
      if(cek(mid + 1)) return bins(mid + 1, r);
      else return mid;
    }
    else return bins(l, mid - 1);
  }
}
 
int main(){
   
  scanf("%d", &N);
  for(i = 1; i <= N; ++i){
    scanf("%lld %lld", &b[i].P, &b[i].S);
  }
  sort(b + 1, b + 1 + N, comp);
   
  ou = bins(0LL, 1000000000000LL);
  printf("%lld\n", ou);
   
   
  return 0;
}
