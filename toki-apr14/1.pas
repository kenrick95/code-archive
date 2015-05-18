var
    s:string;
    a,b,c,p:qword;
begin
    readln(s);
    val(copy(s,1,pos('+',s)-1),a);
    val(copy(s,pos('+',s)+1, length(s)-pos('+',s)),b);
    writeln(a+b);
end.
