program toki298_2; {Jawbreaker 4}
uses math;
type
   tarray=array[-1..30,-1..30] of integer;
var
   a,ao,o:tarray;
   m,n,x,y,b,k,z,zt,mz,xt,yt,xta,yta,zt2:longint;
 
procedure ff(y,x,tc,rc:longint;var a:tarray);
begin
   if ((x>=0) and (y>=0) and (x<=n-1) and (y<=m-1)) and
      (a[y,x]=tc) and
     ( ((a[y-1,x]=tc) or (a[y+1,x]=tc) 
   or (a[y,x-1]=tc) or (a[y,x+1]=tc)) or
      ((a[y-1,x]=rc) or (a[y+1,x]=rc) 
   or (a[y,x-1]=rc) or (a[y,x+1]=rc)) )
   then begin
      z:=z+1;
    // writeln(' ',y,x,' ',a[y,x],' ',z,':u',a[y-1,x],' d',a[y+1,x],' l',a[y,x-1],' r',a[y,x+1]);
      a[y,x]:=rc;
      ff(y-1,x,tc,rc,a{,z});
      ff(y+1,x,tc,rc,a{,z});
      ff(y,x-1,tc,rc,a{,z});
      ff(y,x+1,tc,rc,a{,z});
       
   end;
end;
procedure runtuh(var a:tarray);
var x,y,z:longint;
begin
   for x:=0 to n-1 do begin
      for y:=0 to m-1 do begin
         if a[y,x]<=0 then {runtuhkan} begin
            for z:=y downto 1 do begin
               a[z,x]:=a[z-1,x];
            end;
            a[0,x]:=-2; {-2: telah teruntuhkan :P}
         end;
      end;
   end;
end;
 
procedure play(time,tempscore:longint;a:tarray);
(*
* time: langkah ke-time
* tempscore: nilai saat ini (sblm langkah ke-time)
* a: kondisi papan saat ini (sblm langkah ke-time)
* *)
var
   x,y,b,k,maxz:longint;
   an,ah:tarray;
begin
   if time>=3 then begin
      if tempscore>mz then mz:=tempscore;
      exit;
   end else begin
      ah:=a;
      for y:=0 to m-1 do begin
         for x:=0 to n-1 do begin
            if (ah[y,x]>0) then begin
               ff(y,x,ah[y,x],-1,ah);
               z:=0;
               an:=a;
               ff(y,x,an[y,x],-1,an);
              { writeln(time,' (',y,',',x,') ',z);}
               runtuh(an);
               z:=z*(z-1);
               if (tempscore+z)>mz then mz:=(tempscore+z);
               play(time+1,z+tempscore,an);
            end;
             
         end;
      end;
   end;
end;
 
begin
   readln(m,n);
   for y:=0 to m-1 do begin
      for x:=0 to n-1 do begin
         {NOTE: pojok kiri atas = (y,x) = (0,0)}
         read(a[y,x]);
        // ao[y-1,x-1]:=a[y-1,x-1];
        // o[y-1,x-1]:=a[y-1,x-1];
      end;
      readln;
   end;
    
   mz:=0; //xt:=0; yt:=0;
   play(1,0,a);
   //writeln(xt,' ',yt);
   writeln(mz);
end.
