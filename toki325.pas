program toki325_5;
type
   tarray=array[1..30] of shortint;
var
   s:string;
   x,y,z,i,ls:longint;
   v,u:array[0..600000] of int64;
   tr,tp:tarray;
   vs:int64;
   op:array[0..30] of string;
 
procedure g(q:shortint);
{ q:indeks ke-q}
var
   i,j:longint;
   vt,vt2,temp:int64;
begin
   if q<>ls then begin
      {op[i] adl operator antara tp[i] dan tp[i+1]
      * "_" = concat
      * "+" = plus
      * "-" = minus }
      op[q]:='_'; 
      g(q+1);
      op[q]:='+';
      g(q+1);
      op[q]:='-';
      g(q+1);
   end else begin {q=ls}
      temp:=1;
      vt:=0;
      vt2:=0;
      j:=ls;
      {for i:=1 to ls-1 do begin
         write(op[i]);
      end;}
      for i:=ls-1 downto 1 do begin
         if op[i]='_' then begin
            vt2:=vt2+temp*tp[i+1];
            temp:=temp*10;
         end else if op[i]='+' then begin
            vt2:=vt2+temp*tp[i+1];
            vt:=vt+vt2;
            temp:=1;
            vt2:=0;
            j:=i;
         end else if op[i]='-' then begin
            vt2:=vt2+temp*tp[i+1];
            vt:=vt-vt2;
            temp:=1;
            vt2:=0;
            j:=i;
         end;
      end;
      temp:=1;
      vt2:=0;
      for i:=j downto 1 do begin
         vt2:=vt2+temp*tp[i];
         temp:=temp*10;
      end;
      vt:=vt+vt2;
      z:=z+1;
      v[z]:=vt;
      {writeln(vt);}
   end;
end;
 
procedure qs(l,r:longint);
var temp,i,j,x:int64;
begin
  // randomize;
  // x:=v[random (r-l+1)+l];
   x:=v[(l+r) div 2];
   i:=l;
   j:=r;
   while (i<=j) do begin
      while (v[i]<x) do i:=i+1;
      while (v[j]>x) do j:=j-1;
      if (i<=j) then begin
         temp:=v[i];
         v[i]:=v[j];
         v[j]:=temp;
         i:=i+1;
         j:=j-1;
      end;
   end;
   if (i<r) then qs(i,r);
   if (l<j) then qs(l,j);
end;
 
begin
   readln(s);
   ls:=length(s);
   for x:=1 to ls do begin
      val(s[x],y);
      tp[x]:=y;
   end;
   z:=0;
   g(1);
   qs(1,z);
   i:=0;
   for x:=0 to z do begin
      u[x]:=-99999999999999;
   end;
   for x:=1 to z do begin
      //writeln(i);
      if (v[x]<>u[i]) then begin
         //writeln(' ',v[x],' ',u[i]);
         i:=i+1;
         u[i]:=v[x];
      end;
   end;
   writeln(i);
  // writeln(z);
 
end.
