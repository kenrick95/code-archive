{*
   Pascal template for problem "Pokezip"
   Try Out PJJ OSN 2014 bidang Komputer
*}

{* ************************************************************************* *}
{*
   SOLUSI ANDA DIMULAI DARI SINI
   ANDA BOLEH MENGUBAH BERKAS KODE MULAI DARI TITIK INI SESUAI ATURAN PADA SOAL
*}

{ deklarasi variabel global }


{ Fungsi compress() }

function compress(const data: ansistring): ansistring;
var
    ch: char;
    ch_count, i, SIZE: longint;
    temp: string;

begin
	{ ... }
    ch := chr(0);
    ch_count := 0;
    SIZE := length(data);
    for i := 1 to SIZE do begin
        if (ch <> data[i]) then begin
            if (ch_count > 1) then begin
                str(ch_count, temp);
                compress := compress + '{' + temp + '}';
            end;
            ch := data[i];
            ch_count := 1;
            compress := compress + ch;
        end else begin
            ch_count := ch_count + 1;
        end;
    end;
    if (ch_count > 1) then begin
        str(ch_count, temp);
        compress := compress + '{' + temp + '}';
    end;
    
	//compress := data;
end;


{ Fungsi decompress() }

function decompress(const data: ansistring): ansistring;
var
    ch: string;
    post, post_end, i, num: longint;
    temp: ansistring;
    num_str: string;
begin
	{ ... }
    temp := data;
    post := pos('{', temp);
    post_end := pos('}', temp);
    while (post > 0) do begin
        ch := copy(temp, post - 1, 1);
        num_str := copy(temp, post + 1, post_end - post - 1);
        val(num_str, num);
        
        decompress := decompress + copy(temp, 1, post - 1);
        while (num > 0) do begin
            decompress := decompress + ch;
            num := num - 1;
        end;
        
        
        delete(temp, 1, post_end);
        
        post := pos('{', temp);
        post_end := pos('}', temp);
    end;
    
    
	//decompress := data;
end;


{* ************************************************************************* *}
{*
   ANDA DILARANG MENGUBAH KODE-KODE DI BAWAH INI
   KONSEKUENSI TELAH DIJELASKAN PADA BAGIAN PERINGATAN PADA HALAMAN SOAL
*}

procedure main;
var
	real_data	: ansistring;
	tmp		: ansistring;
	compressed	: ansistring;
	decompressed	: ansistring;
begin
	real_data := '';
	while not eof do begin
		readln(tmp);
		real_data := real_data + tmp;
	end;

	compressed := compress(real_data);
	decompressed := decompress(compressed);

	writeln(compressed);
	writeln('[END_OF_COMPRESSED_DATA]');
	writeln(decompressed);
	writeln('[END_OF_DECOMPRESSED_DATA]');

end;

begin
	main;
end.
