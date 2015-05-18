/**
 * C++ template for problem "Pokezip"
 * Try Out PJJ OSN 2014 bidang Komputer
 */

#include <bits/stdc++.h>
using namespace std;

/* ************************************************************************* */
/**
 * SOLUSI ANDA DIMULAI DARI SINI
 * ANDA BOLEH MENGUBAH BERKAS KODE MULAI DARI TITIK INI SESUAI ATURAN PADA SOAL
 */


/* Fungsi compress() */

string compress(const string &data)
{
	// ...
    char ch = 0;
	int ch_count = 0;
	int i;
    int SIZE = data.length();
    string ret("");

	for (i = 0; i < SIZE; i++) {
        if (ch != data[i]) {
            if (ch_count > 1) {
                ret.append("{" + ch_count + "}");
            }
            ch = data[i];
            ch_count = 1;
            ret.append(ch);
        } else { // if previous == current character
            ch_count++;
        }
    }
    if (ch_count > 1) {
        ret.append("{" + ch_count + "}");
    }
    
	return ret;
}


/* Fungsi decompress() */

string decompress(const string &data)
{
	// ...
	return data;
}

/* ************************************************************************* */
/**
 * ANDA DILARANG MENGUBAH KODE-KODE DI BAWAH INI
 * KONSEKUENSI TELAH DIJELASKAN PADA BAGIAN PERINGATAN PADA HALAMAN SOAL
 */

int main(int argc, const char *argv[])
{
	string real_data, tmp;
	string compressed;
	string decompressed;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while (getline(cin,tmp)) real_data.append(tmp);

	compressed = compress(real_data);
	decompressed = decompress(compressed);

	cout << compressed << "\n";
	cout << "[END_OF_COMPRESSED_DATA]" << "\n";
	cout << decompressed << "\n";
	cout << "[END_OF_DECOMPRESSED_DATA]" << "\n";

	return 0;
}
