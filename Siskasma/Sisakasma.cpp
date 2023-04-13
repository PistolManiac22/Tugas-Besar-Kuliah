#include <iostream>

 using namespace std;

int nyari(string barang1[], int size, string cari)
{
    for (int i = 0; i < size; ++i)
	{
		if (barang1[i] == cari)
		{
			return i;
		}
	}
	return -1;
}

int deleting(int pesanan[], int size, int cari)
{
    for (int i = 0; i < size; ++i)
	{
		if (pesanan[i] == cari)
		{
			return i;
		}
	}
	return -1;
}

void sistem(){
    string inputbarang,editnama;
    string barang1[50] = {"susu","kecap","gula","beras","garam","yogurt","odol","sabun","telur","permen","roti","minyak","tepung","lilin","teh","kopi","mie","pewangi","lampu","santan","sosis","cabai","mentega","naget","popok","cuka","perban","saus","sirup","tauco","sambal","coklat","selai","madu","sereal","biskuit","keripik","kerupuk","mainan","obat","tisu","buah","jus","soda","merica","donat","jagung","sayur","ikan","ayam"};
    string barang2[50] = {"Susu   ","Kecap  ","Gula   ","Beras  ","Garam  ","Yogurt ","Odol   ","Sabun  ","Telur  ","Permen ","Roti   ","Minyak ","Tepung ","Lilin  ","Teh    ","Kopi   ","Mie    ","Pewangi","Lampu  ","Santan ","Sosis  ","Cabai  ","Mentega","Naget  ","Popok  ","Cuka   ","Perban ","Saus   ","Sirup  ","Tauco  ","Sambal ","Coklat ","Selai  ","Madu   ","Sereal ","Biskuit","Keripik","Kerupuk","Mainan ","Obat   ","Tisu   ","Buah   ","Jus    ","Soda   ","Merica ","Donat  ","Jagung ","Sayur  ","Ikan   ","Ayam   "};
    int pesanan[50];
    int banyak[50];
    int harga1[50] = {4,16,8,60,12,14,8,18,2,13,12,12,34,46,65,24,74,86,24,46,24,58,97,24,47,6,94,24,6,13,57,13,5,7,79,64,8,61,35,68,13,35,57,13,46,31,35,13,35,13};
    int list = 0,sizea = sizeof(barang1)/sizeof(barang1[0]),sizeb = sizeof(pesanan)/sizeof(pesanan[0]),totalbarang,hargatotal1,hargatotal2 = 0,edit,editjuml,hapus,carihapus,bayar,kembalian,pilihfitur;


    awalan :
     cout<<"\n||================================================||\n";
    cout<<"||                  FITUR SISKASMA                ||\n";
    cout<<"||================================================||\n";
    fitur :
    cout<<"|| 1. Input Pembelian                             ||\n";
    cout<<"|| 2. Menampilkan Daftar Barang                   ||\n";
    cout<<"||================================================||\n";
    cout<<"||Pilih Fitur : ";cin>>pilihfitur;
    system("CLS");

    if (pilihfitur == 2) {
        cout<<"\n||================================================||\n";
    cout<<"||                  Daftar Barang                 ||\n";
    cout<<"||================================================||\n";
    cout<<"|| Nama Barang           ||       Harga Barang    ||\n";
    cout<<"||================================================||\n";
    for (int i = 0; i < sizea; i++)
        {
        cout<<"|| "<<barang2[i]<<"\t\t\t\t ||"<<"\t\t  Rp."<<harga1[i]<<".000"<<"\t\t  ||\n";
        }
        cout<<"||================================================||\n";
        goto fitur;
    }

    else if (pilihfitur == 1) {
    cout<<"\n||================================================||\n";
    cout<<"||                 INPUT PEMBELIAN                ||\n";
    cout<<"||================================================||\n";

    awal :
    do {
    cout<<"||     Jika Sudah Selesai Mohon Ketik 'total'     ||"<<endl;
    cout<<"||================================================||"<<endl;
    cout<<"|| Masukkan Nama Barang      : ";cin>>inputbarang;
    int info = nyari (barang1, sizea-1, inputbarang);
    if (inputbarang == "total") {
        system("CLS");
        break;
            }
    else {
        if(info == -1){
            cout<<"|| Barang Tidak Ditemukan\n\n";
            continue;
                }

        else{
            cout<<"|| Jumlah                    : ";cin>>banyak[list];
            system("CLS");
            cout<<"||================================================||"<<endl;
            cout<<"|| Nama Barang      : "<<barang2[info]<<endl;
            cout<<"|| Harga Barang     : Rp."<<harga1[info]<<".000"<<endl;
            cout<<"|| Jumlah Barang    : "<<banyak[list]<<endl;
            cout<<"|| Harga Total      : Rp."<<banyak[list] * harga1[info]<<".000"<<endl;
            cout<<"||================================================||"<<endl;
            pesanan[list] = info;
                }
            list = list+1;
            }
        } while (list <= 30);

    struk :
    edit = 0;
    hargatotal2 = hargatotal2 - hargatotal2;
    cout<<endl;
        cout<<"\n||================================================||\n";
            cout<<"||                 STRUK PEMBELIAN                ||\n";
            cout<<"||================================================||\n";
        cout<<"|| Nama Barang ||  Jumlah Barang  || Harga Barang ||\n";
    cout<<"||================================================||\n";
        for (int a = 0;a < list;a++) {
            totalbarang = pesanan[a];
            hargatotal1 = harga1[totalbarang]*banyak[a];
            cout<<"|| "<<barang2[totalbarang]<<"\t   ||  "<<banyak[a]<<"\t\t\t\t Rp."<<hargatotal1<<".000\t  ||"<<endl;
            hargatotal2 = hargatotal2 + hargatotal1;
        }
        cout<<"||================================================||\n";
        cout<<"|| Total Harga :                     Rp."<<hargatotal2<<".000\t  ||\n";
        cout<<"||================================================||\n";
        cout<<"|| Apakah List Barang Sudah Benar?                ||"<<endl;
        cout<<"|| 1.Hapus Barang Dari List                       ||"<<endl;
        cout<<"|| 2.Tambah Barang Kedalam List                   ||"<<endl;
        cout<<"|| 3.Pembayaran                                   ||"<<endl;
        cout<<"||================================================||\n";
        cout<<"|| Pilih : ";cin>>edit;
        switch (edit){
            case 1 :
            system("CLS");
                cout<<"|| Masukkan Nama Barang     : ";cin>>editnama;

                carihapus = nyari(barang1, sizea-1 , editnama);
                if (carihapus == -1) {
                cout<<"|| Barang Tidak Ditemukan\n";
                cout<<"|| Masukkan Nama Barang Yang Benar!\n\n";
                goto struk;
                }
                else {
                cout<<"|| Jumlah Barang            : ";cin>>editjuml;
                hapus = deleting(pesanan, sizeb-1, carihapus);
                banyak[hapus] = banyak[hapus] - editjuml;
                hargatotal2 = hargatotal2 - hargatotal2;
                goto struk;
                }
            case 2 :
            system("CLS");
            goto awal;
            case 3 :
            cout<<"|| Nominal Pembayaran : ";cin>>bayar;
            if (bayar >= hargatotal2){
            kembalian = bayar - hargatotal2;
             cout<<"================================================="<<endl;
            cout<<"\t\tNominal Kembalian Sebesar Rp."<<kembalian<<".000"<<endl;
            cout<<"\t\t  Terima Kasih Sudah Berbelanja!"<<endl;
             cout<<"================================================="<<endl;
             abort();
            default :
            cout<<"|| Mohon Masukkan Pilihan Yang Benar!\n";
            goto struk;
            }
            else {
                cout<<"|| Nominal Pembayaran Kurang!"<<endl;
                cout<<"|| Silahkan Bayar Sesuai Dengan Struk\n\n";
                goto struk;
            }
        }
    }
    else {
        goto awalan;
    }
}


void login(){
    string username = "admin",password = "admin",inputuser,inputpass,kondisi;
    int coba = 2;

    cout<<"\n||================================================||\n";
        cout<<"||                 LOGIN SISKASMA                 ||\n";
        cout<<"||================================================||\n";
    do {
        cout<<"||Masukkan Username : ";cin>>inputuser;
        cout<<"||Masukkan Password : ";cin>>inputpass;

        if (inputuser == username && inputpass == password) {
        kondisi = "berhasil";
            break;
        }
        else if (coba > 0 ) {
            cout<<"||Username atau Password Salah! Silahkan Coba Lagi\n";
            cout<<"||Kesempatan Anda Tinggal "<<coba--<<"X Lagi!\n\n";
        }
        else {
            cout<<"Anda Tidak Diperkenankan Masuk!\n";
            break;
        }
    } while (coba > -1);

    if (kondisi == "berhasil") {
        system("CLS");
        sistem();
    }
 }

 int main() {
   login();
}
