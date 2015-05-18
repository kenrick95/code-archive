#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<fstream>
#include<cmath>
#include<map>
typedef long long int64;
using namespace std;
/*
yooo ._.
ohhh ini ._.
hmmm
pakai map...
sama graph...
pake STL map...
trus dibuat pohonnya...
kalau kagak pakai map itu nanti jadinya N^2
._.
dan kalau itu awalnya angka... bukan string, itu soal bisa diselesain dalam O(N)
 
 
STL map gmn pakainya? kubaca2 dr internet g ngerti2
hmmm
deklarasinya gini
map<string, int> nama;
<pertama, kedua> yang pertama itu dari apa, yang kedua itu kemana...
jadi...
kita bisa memetakan
misalkan
"asdf" -> 1
itu caranya
nama["asdf"] = 1;
jadi kita bisa mendapatkan angka satu dari nama["asdf"]
._.
itu get sama set nilainya itu dilakukan dalam logN
kalau pair?
kalau pair
itu...
sejenis struct...
tapi hanya punya first sama second doang...
._.
jadi anggap aja itu kayak record di pascal, tapi cuman punya dua variable didalamnya yaitu first sama second
...
ooh
grin
jadi anggap aja...
map itu...
mirip array
tapi indeksnya itu bisa objek lain selain integer doang...
gampangnya seh gitu :-?...
Chat conversation end
kalau insert elemen ke dalam map mesti lewat pair ya?
macam http://www.cplusplus.com/reference/stl/map/insert/
mymap.insert ( pair<char,int>('a',100) );
bisa seh...
tapi gak harus gitu...
:-?...
itu bisa diubah jadi gini enaknya
mymap['a'] = 100;
gitu grin
mirip array... tapi gak harus angka yang jadi indeksnya...
 
jadi map itu semacam peta yg menunjukkan apakah A & B itu terhubung, gitu aja?
kagak ._.
map itu ARRAY, yang INDEKS nya gak harus INTEGER
:-?...
hmmm?
biasanya di array
itu kayak gini
a[100] = 12;
di map
a[anythinghere] = 12;
begitu saja ya? oooh
iya ._>
._.
haha smile
thx smile
sep2...
*/
 
// eline map: <child,parent>
multimap<string,string> eline;
bool tf;
long n,m,i,j,k,x,y,z;
string s,t,st,tst;
string lit[10050];
 
bool test(string s,string t) {
  x=eline.count(t);
  if (x==0) { //TM
    z=-1;
    //exit;
    return false;
  }
  y=1;
  lit[y]=t;
  st=eline.find(t)->second; //get the starting parent
  y++;
  lit[y]=st;
  
  if (st==s) { //goal!
    z=1;
  } else { 
    z=-1; //-1 = TM, 1=goal;
    tst=st;
    x=eline.count(tst);
    while ((x>0)&&(y<=n)) {
      tst=st;
      if (tst==s) {
        z=1;
        break;
      }
      x=eline.count(tst);
      if (x>0) {
        st=eline.find(tst)->second;
        y++;
        lit[y]=st;
      } else {
        break;
      }
      //cout<<st<<"\n";
    }
  }
  if (z==1) {
    for (x=y;x>=1;x--) {
      cout<<lit[x]<<"\n";
    }
    return true;
  } else {
    return false;
  } 
}
 
int main(){
  scanf("%ld %ld",&n,&m);
  for (i=1;i<=m;i++) {
    cin>>s; //Parent
    cin>>t; //Child
    //scanf("%s",&s);
    //scanf("%s",&t);
    //cout<<s<<" "<<t;
    //eline[s]=t;
    eline.insert(pair<string,string>(t,s));
    //cout<<eline.find(s)->first<<eline.find(s)->second;
  }
  cin>>s;
  cin>>t;
  tf=test(s,t);
 /* for (x=y;x>=1;x--) {
      cout<<lit[x]<<"\n";
    }
    cout<<"\n";*/
  if (!tf) {
    tf=test(t,s);
    /*for (x=y;x>=1;x--) {
      cout<<lit[x]<<"\n";
    }*/
  }
  if (!tf) {
    cout<<"TIDAK MUNGKIN\n";
  }
   
  return 0;
}
