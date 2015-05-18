#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
 
typedef long long int64;
using namespace std;
 
struct matx{
    int i[32][32];
} mat,mata,ma,mb,mt,mat1,mat2;

struct imatx {// for inverse matrix
    double i[32][32];
};
struct ematx { //expanded matrix, for inverse matrix
    double i[32][64];
};

int x,y,z,i,j,md;
int  n,k,m, xi[32],xj[32];

/*
 * [a b c] [0 0 1]^n = [b  c  a+b+c]
 *         [1 0 1]
 *         [0 1 1]
 * */
matx Mult (matx ma, matx mb) {
    matx mt;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            mt.i[i][j] = 0;
            for (int k = 1; k <= n; k++){
                mt.i[i][j] += (ma.i[i][k] * mb.i[k][j]) % md;
                //cout<<mt.i[i][j]<<"> ";
            }
            //cout<<"! ";
        }
        //cout<<endl;
    }
    return mt;
}
imatx Mult (imatx ma, matx mb) {
    imatx mt;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            mt.i[i][j] = 0;
            for (int k = 1; k <= n; k++){
                mt.i[i][j] += (ma.i[i][k] * mb.i[k][j]);
                //cout<<mt.i[i][j]<<"> ";
            }
            //cout<<"! ";
        }
        //cout<<endl;
    }
    return mt;
}

matx Pow (matx ma, long long p) {
    matx mt;
    if (p == 1) {
        mt = ma;
        return mt;
    } else if (p==0) {
        for (int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                mt.i[i][j] = 0;
            }
        }
        return mt;
    }
    if (p%2==0) {
        mt = Pow(ma, p/2);
        mt = Mult(mt, mt);
    } else {
        mt = Mult(Pow(ma, p-1), ma);
    }
    return mt;
}

imatx Inverse(matx mat) {
    // merge with identity matrix
    ematx emat;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            emat.i[i][j] = (double) mat.i[i][j];
        }
        for (int j = n + 1; j <= 2 * n; j++) {
            emat.i[i][j] = (double) (i == (j - n));
        }
    }
    double d;
    // http://ganeshtiwaridotcomdotnp.blogspot.sg/2009/12/c-c-code-gauss-jordan-method-for.html
    // partial pivoting
    for (int i = n; i > 1; i--) {
        if (emat.i[i-1][1] < emat.i[i][1])
            for(int j = 1; j <= n*2; j++) {
                d = emat.i[i][j];
                emat.i[i][j] = emat.i[i-1][j];
                emat.i[i-1][j] = d;
            }
    }
   /*for (int ia=1; ia<=n; ia++){
      for (int ib=1; ib<=2*n; ib++){
         cout<<emat.i[ia][ib]<<" ";
      }
      cout<<endl;
   }*/
    // reducing to diagonal  matrix 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n * 2; j++)
            if (j != i) {
                d = emat.i[j][i] / emat.i[i][i];
                for (k = 1; k <= n * 2; k++)
                    emat.i[j][k] -= emat.i[i][k] * d;
            }
    }
   /*for (int ia=1; ia<=n; ia++){
      for (int ib=1; ib<=2*n; ib++){
         cout<<emat.i[ia][ib]<<" ";
      }
      cout<<endl;
   }*/
    // reducing to unit matrix
    for (int i = 1; i <= n; i++){
        d = emat.i[i][i];
        for (int j = 1; j <= n * 2; j++)
            emat.i[i][j] = emat.i[i][j] / d;
    }
  /* for (int ia=1; ia<=n; ia++){
      for (int ib=1; ib<=2*n; ib++){
         cout<<emat.i[ia][ib]<<" ";
      }
      cout<<endl;
   }*/
    
    imatx imat;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            imat.i[i][j] = emat.i[i][j + n];
        }
    }
    return imat;
    
}
 
int main(){
   scanf("%d %d %d", &n, &k, &m);
   md=m;
   
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= n; j++) {
           scanf("%d", &mat.i[i][j]);
       }
   }
   
   
   // geometric sum of square matrix = (I - S)^-1 * (I - S^N)
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= n; j++) {
           mat1.i[i][j] = (i == j) - mat.i[i][j];
           mat2.i[i][j] = mat.i[i][j];
       }
   } // I - S
   
   mata = Pow(mat2, n); //S ^ N
   
   for (int i = 1; i <= n; i++) {
       for (int j = 1; j <= n; j++) {
           mat2.i[i][j] = (i == j) - mata.i[i][j];
       }
   } // I - S ^ N
   
   /*for (int ia=1; ia<=n; ia++){
      for (int ib=1; ib<=n; ib++){
         cout<<mat2.i[ia][ib]<<" ";
      }
      cout<<endl;
   }*/
   
   // do inverse matrix of mat1
   imatx imat = Inverse(mat1); // (I - S) ^ -1
   
   /*for (int ia=1; ia<=n; ia++){
      for (int ib=1; ib<=n; ib++){
         cout<<imat.i[ia][ib]<<" ";
      }
      cout<<endl;
   }*/
   
   // then multiply mat1 with mat2
   imat = Mult(imat, mat2);


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
           imat.i[i][j] = imat.i[i][j] - (i == j);
           imat.i[i][j] = imat.i[i][j] + mata.i[i][j];
           
        }
    } 
 
   //mata=Mult(mat,mat);
   for (int ia=1; ia<=n; ia++){
      for (int ib=1; ib<=n; ib++){
         cout<<imat.i[ia][ib]<<" ";
      }
      cout<<endl;
   }
   
   return 0;
}
