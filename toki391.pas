{tantangan dengklek
1 node isinya array tsementara yg tlh di-reverse
tak perlu isikan indeksnya
[ ] -> [ ] -> [  ] sampai sorted
    -> [ ]
    -> [ ]
    ...
  
        brp kali reverse
         |
O(N! * (N-K+1)*K/2 )
  |             |
  worst case    reverse
  * 
  * WARNING: memory usage sekitar 88MB!
  * 
  * 
}
program toki391;
var
   n,m,k,i,j,x,y,z,tail,head,temp:longint;
   a: array[0..20] of longint;
   qmov:array[0..50000] of longint;
   aq:array[0..50000,0..20] of longint;
   aqc:array[0..87654322] of boolean;
   fin,afin,fin2:boolean;
  
begin
   readln(n);
   for m:=1 to n do begin
        read(a[m]);
   end;
   readln;
   readln(k);
   tail:=0;
   head:=0;
  
   for x:=1 to n do begin
        qmov[tail]:=0;
      aq[tail,x]:=a[x];
   end;
   tail:=tail+1;
   while (head<tail) do begin
      {writeln(head,'<',tail);}
      fin:=true;
      //fin:=false;
      afin:=true;
      for x:=1 to n do begin
         if aq[tail,x]<>aq[head,x] then fin:=false;
         if aq[head,x]<>x then afin:=false;
         {write(' ',aq[head,x],' ');}
      end;
      {writeln;}
      if afin then break;
      if not fin then begin
         for x:=1 to n-k+1 do begin
            for y:=1 to n do aq[tail,y]:=aq[head,y];
            i:=0;
            for y:=x to (x+(k-1) div 2 ) do begin
               i:=i+1;
               //writeln(x,' ',(x+(k-1) div 2),' ',x+k-i);
               temp:=aq[tail,y];
               aq[tail,y]:=aq[head,(x+k-i)];
               aq[tail,(x+k-i)]:=temp;
            end;
            temp:=1;
            z:=0;
            for y:=n downto 1 do begin
               z:=z+aq[tail,y]*temp;
               temp:=temp*10;
            end;
            if aqc[z] then begin
               fin2:=true;
            end else begin
               aqc[z]:=true;
               fin2:=false;
            end;
           { write(':',tail,'=');
            for y:=1 to n do write(aq[tail,y],' ');
            writeln;}
            {for z:=0 to tail-1 do begin
               fin2:=true;
               for y:=1 to n do begin
                  if aq[z,y]<>aq[tail,y] then begin
                     fin2:=false;
                     break;
                  end;
               end;
               if fin2 then break;
            end;}
            if (fin2=false) then begin
               qmov[tail]:=qmov[head]+1;
               tail:=tail+1;
            end;
         end;
      end;
      head:=head+1;
   end;
   if afin then writeln(qmov[head])
   else writeln(-1);
end.
