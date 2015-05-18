program pjj12_4_25;
uses math;
var
   m,i,j,k,n,l,t,x,y,z,init,fina,tail,head:longint;
   a:array[0..512,0..512] of integer;
   {0=unconnected, 1=jalan biasa, 2=jalan tol}
   q:array[0..300000] of longint;
   mov:array[0..5,0..512] of longint;
   qt:array[0..300000] of boolean;
begin
   readln(n,l,t,init,fina);
   for m:=1 to l do begin
      readln(x,y);
      a[x,y]:=1;
      a[y,x]:=1;
   end;
   for m:=1 to t do begin
      readln(x,y);
      a[x,y]:=2;
      a[y,x]:=2;
   end;
   for x:=1 to n do begin
      mov[1,x]:=99999999;
      mov[2,x]:=99999999;
   end;
   tail:=0;
   head:=0;
   q[tail]:=init;
   qt[tail]:=false;
   mov[1,q[tail]]:=0;
   mov[2,q[tail]]:=0;
   tail:=tail+1;
   while head<tail do begin
     { writeln(q[head]); }
      for x:=1 to n do begin
         if (a[q[head],x]=1)
         and (qt[head]=false)
         and (mov[1,q[head]]+1<mov[1,x]) then begin
         {1: never use toll, 2:ever use toll}
            q[tail]:=x;
            mov[1,q[tail]]:=mov[1,q[head]]+1;
            qt[tail]:=qt[head];
             
            {if (qt[head]) and (mov[2,q[head]]+1<mov[2,x]) then begin
               mov[2,q[tail]]:=mov[2,q[head]]+1;
            end;}
             {writeln(' ',q[tail]);  }
            tail:=tail+1;
         end else if (a[q[head],x]=1)
         and (qt[head]=true)
         and (mov[2,q[head]]+1<mov[2,x]) 
         then begin
            q[tail]:=x;
            qt[tail]:=qt[head];
            mov[2,q[tail]]:=mov[2,q[head]]+1;
            {writeln(' ',q[tail]);  }
            tail:=tail+1;
         end else if (a[q[head],x]=2)
         and (qt[head]=false)
         and (mov[1,q[head]]+1<mov[1,x]) 
     and (mov[1,q[head]]+1<mov[2,x]) 
         then begin
            q[tail]:=x;
            mov[2,q[tail]]:=mov[1,q[head]]+1;
            qt[tail]:=true;
            { writeln(' ',q[tail]); }
  
            tail:=tail+1;
         end;
      end;
      head:=head+1;
   end;
   {for x:=1 to n do writeln(mov[1,x],' ',mov[2,x]);}
   if mov[2,fina]<>0 then writeln(min(mov[1,fina],mov[2,fina]))
   else writeln(mov[1,fina]);
end.
