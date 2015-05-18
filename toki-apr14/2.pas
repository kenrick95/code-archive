var
    s,t:string;
    a:array[0..300] of integer;
    i,j,k:longint;
    c:char;
{
Karakter Yang Hilang

Diberikan 2 buah string, carilah karakter yang hilang

Baris pertama berisi sebuah string S. Baris kedua berisi string T yang merupakan permutasi dari string S yang dihalangkan satu karakter.

Sebuah karakter yang hilang ditambah karakter pertama dari kedua string. :3

Panjang string S dan T minimal satu dan tidak lebih dari seratus.
}
begin
    readln(s);
    readln(t);
    for i:= 1 to length(s) do begin
        a[ord(s[i])] := a[ord(s[i])] + 1;
    end;
    for i:= 1 to length(t) do begin
        a[ord(t[i])] := a[ord(t[i])] - 1;
    end;
    j := 0;
    c := chr(0);
    for i:= 1 to 300 do begin
        if a[i] <> 0 then begin
            c := chr(i);
            break;
        end;
    end;
    write(c);
    write(s[1]);
    write(t[1]);
    writeln;
end.
