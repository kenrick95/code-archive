#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#define INF 1000000000000LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/* Problem: Facebook Hacker Cup 2014 Qualification Round
 *          Problem C: Tennison
 * URL: https://www.facebook.com/hackercup/problems.php?pid=373965339404375&round=598486203541358
 
 DUNNO HOW TO FIX ALRDY T.T
 
 */
 
int T,K;
double Ps, Pr, Pi, Pu, Pw, Pd, Pl;

double prob(int D, int S, double Pi)
{ //memasuki set ke-D, telah menang S kali
    double win = 0.0;
    double lose = 0.0;
    double win_inc1 = 1.0;
    double lose_inc1 = 1.0;
    double win_inc2 = 1.0;
    double lose_inc2 = 1.0;
    double temp = 0.0;
    //cout<<Pi<<" "<<Ps<<" "<<Pr<<endl;
    
    win = Pi * Ps + (1.0 - Pi) * Pr;
    lose = 1.0 - win;
    if ((D-S) >= K)
    {
        temp = 0.0;
    } else if (S >= K) {
        temp = 1.0;
    }
    else if (S < K)
    {
        //cout<<D<<" "<<Pi<<endl;
        win_inc1 = min(1.0, Pw * prob(D+1, S+1, Pi + Pu));
        win_inc2 = min(1.0, (1.0 - Pw) * prob(D+1, S+1, Pi));
        
        lose_inc1 = min(1.0, Pl * prob(D+1, S, Pi - Pd));
        lose_inc2 = min(1.0, (1.0 - Pl) * prob(D+1, S, Pi));
        
        //cout<<"     "<<win<<" "<<win_inc1<<" "<<win_inc2<<" + "<<lose<<" "<<lose_inc1<<" "<<lose_inc2<<endl;
        temp = min(1.0, win * (win_inc1 + win_inc2) + lose * (lose_inc1 + lose_inc2));
        //cout<<"   = "<<temp<<endl;
    }
    else {
        temp = win;
        //cout<<D<<" "<<Pi<<endl;
        //cout<<" === "<<temp<<endl;
    }
    
    
    return temp;
}

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
        scanf("%d %lf %lf %lf %lf %lf %lf %lf", &K, &Ps, &Pr, &Pi, &Pu, &Pw, &Pd, &Pl);
        printf("Case #%d: %.5lf\n", t, prob(1, 0, Pi));
    }
    
	return 0;
}
