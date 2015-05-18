program pjj12_5_10;
uses math;
var
   v,h:array[1..50000] of longint;
   x,y,z,i,j,k,n,m:longint;
   t,l,r,p:real;
{N lg2 N
let t is the minimum time needed
let x[i] is the number of holes
v[i] the volume
t <= v[i] / x[i]
in conclusion
x[i] = ceil(v[i] / t)
uda bs kan?
}
begin
   readln(n,m);
   z:=0;
   for x:=1 to n do begin
      read(v[x]);
     // z:=max(z,v[x]);
   end;
   readln;
   z:=2000000000;
   l:=0;
   r:=z+1;
   while (r-l)>0.00001 do begin
      p:=(l+r)/2;
      k:=0;
      for x:=1 to n do begin
         k:=k+ceil(v[x]/p);
      end;
      if (k<=m) then begin
         r:=p;
      end else if (k>m) then begin
         l:=p;
      end;
   end;
    writeln(p:0:2);
   {t:=-1;
   for x:=1 to n do begin
      write(ceil(v[x]/p),' ');
      h[x]:=ceil(v[x]/p);
      t:=max(t,v[x]/h[x]);
   end;
  writeln(t:0:2);}
end.
