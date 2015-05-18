#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<cmath>
#include<string>
 
typedef long long int64;
using namespace std;
 
struct matx{
   long long i[5][5];
} mat,mata,ma,mb,mt;
 
long long x,y,z,i,j,m,md;
long long a,b,c,d,n,xi[3],xj[3];
/*
 * [a b c] [0 0 1]^n = [b  c  a+b+c]
 *         [1 0 1]
 *         [0 1 1]
 * */
matx Mult(matx ma,matx mb) {
   matx mt;
   for (int ia=1;ia<=3;ia++) {
      for(int ib=1;ib<=3;ib++) {
         mt.i[ia][ib]=0;
         for (int ic=1;ic<=3;ic++){
            mt.i[ia][ib]+=(ma.i[ia][ic] * mb.i[ic][ib])%md;
            //cout<<mt.i[ia][ib]<<"> ";
         }
         //cout<<"! ";
      }
      //cout<<endl;
   }
   return mt;
}
matx Pow(matx ma,long long p){
   matx mt;
   if (p==1) {
      mt=ma;
      return mt;
   } else if (p==0){
      for (int ia=1;ia<=3;ia++){
         for(int ib=1;ib<=3;ib++){
            mt.i[ia][ib]=0;
         }
      }
      return mt;
   }
   if (p%2==0) {
      mt=Pow(ma,p/2);
      mt=Mult(mt,mt);
   } else {
      mt=Mult(Pow(ma,p-1),ma);
   }
   return mt;
}
 
int main(){
   scanf("%lld %lld %lld",&a,&b,&c);
   md=1000000007;
   scanf("%lld",&n);
   if (n==1) {
      printf("%lld\n",a);
      return 0;
   } else if (n==2) {
      printf("%lld\n",b);
      return 0;
   } else if (n==3) {
      printf("%lld\n",c);
      return 0;
   } else {
      n-=3;
   }
    
   mat.i[1][1]=0;
   mat.i[1][2]=0;
   mat.i[1][3]=1;
   mat.i[2][1]=1;
   mat.i[2][2]=0;
   mat.i[2][3]=1;
   mat.i[3][1]=0;
   mat.i[3][2]=1;
   mat.i[3][3]=1;
   mata=Pow(mat,n);
   //Pow(ma,n);
 
   //mata=Mult(mat,mat);
   /*for (int ia=1;ia<=3;ia++){
      for (int ib=1;ib<=3;ib++){
         cout<<mata.i[ia][ib]<<" ";
      }
      cout<<endl;
   }*/
   ma.i[1][1]=a;
   ma.i[1][2]=b;
   ma.i[1][3]=c;
      for(int ib=1;ib<=3;ib++) {
         mt.i[1][ib]=0;
         for (int ic=1;ic<=3;ic++){
            mt.i[1][ib]+=(ma.i[1][ic] * mata.i[ic][ib])%md;
         }
      }
   cout<<mt.i[1][3]%md<<endl;
   return 0;
}
