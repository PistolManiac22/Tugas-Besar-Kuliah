#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <conio.h>
#include <limits>
#include <map>
#include <iomanip>
#include <vector>

using namespace std;
const int MAX_SIZE = 11;

struct Node {
    string name;
    int number;
    Node* next;
};

void addNode(Node** head_ref, string name, int number) {
    Node* new_node = new Node();
    new_node->name = name;
    new_node->number = number;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void printList(Node* node) {
    while (node != NULL) {
        cout << node->name << ": " << node->number << endl;
        node = node->next;
    }
}
struct lokasi {
    string name;
    string jalan;
    string deskripsi;
    string jam;
    string harga;
    string jarak;
    string ulasan;
    string tag;
};

const lokasi lok[MAX_SIZE];
const char* filename = "./lokasi.txt";

void bookmark(string username){
    Node* head = NULL;
    int i = 1;

    ifstream infile("data.txt");
    cout << "List Bookmark : " << endl;
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            string name = line.substr(0, line.find(","));
            int number = stoi(line.substr(line.find(",") + 1));
            addNode(&head, name, number);
            if(name == username){
            cout <<"["<<i++<<"]"<< lok[number].name<<endl;
            }
        }
        infile.close();
    } else {
        cout << "File Error." << endl;
    }
}

void hapus(string input){
    ifstream input_file("./data.txt");

    vector<string> lines;
    string line;
    while (getline(input_file, line)) {
        if (line.find(input + ",") != string::npos) {
            continue;
        }
        lines.push_back(line);
    }
    input_file.close();

    ofstream output_file("./data.txt");
    for (const auto& line : lines) {
        output_file << line << endl;
    }
    output_file.close();
    cout << "Bookmark user "<<input<<" telah dihapus!" << endl;

}
void semuabookmark() {
    ifstream file("./data.txt");
    string line,ins,user;
    int i = 1;

    map<string, int> counts;

    while (getline(file, line)) {
        size_t pos = line.find(',');

        if (pos != string::npos) {
            string key = line.substr(0, pos);
            counts[key]++;
        }
    }

    cout << "=====================================================" << endl;
    cout << "|      User Bookmark       |          Count         |" << endl;
    cout << "=====================================================" << endl;
    for (const auto& pair : counts) {
        cout << "| " << setiosflags(ios::left) << setw(25) << pair.first << "| " << setiosflags(ios::left) << setw(23) << pair.second << "|" << endl;
        cout << "=====================================================" << endl;
    }

    cout << "Hapus Data Bookmark User?(y/n) : ";cin >> ins;
    if (ins == "y" || ins == "Y"){
        cout << "Masukkan Nama User Yang Ingin Anda Hapus : ";cin>>user;
        hapus(user);
    }
}

void addbookmark(string name, int number) {
    Node* head = NULL;

    addNode(&head, name, number);

    ofstream file("./data.txt", ios::app);
    if (file.is_open()) {
        Node* current = head;
        while (current != NULL) {
            file << current->name << "," << current->number << endl;
            current = current->next;
        }
        file.close();
        cout << "Data telah berhasil ditambahkan." << endl;
    } else {
        cout << "File Error!" << endl;
    }
    return;
}

void input() {
    int input;
    cout << "=====================================================" << endl;
    cout << "                                                     " << endl;
    cout << "                  Input Lokasi Baru                  " << endl;
    cout << "                                                     " << endl;
    cout << "=====================================================" << endl;
    cout << "Anda ingin menginput berapa lokasi baru : "; cin >> input;
    cin.ignore();
    if (input > MAX_SIZE) {
        cout << "Ukuran data melebihi kapasitas yang tersedia" << endl;
        return;
    }
    for (int a = 0; a < input; a++) {
        cout << "Masukkan Nama Tempat : ";
        getline(cin,lok[a].name);
        cout << "Masukkan Lokasi Tempat : ";
        getline(cin, lok[a].jalan);
        cout << "Masukkan Deskripsi Tempat : ";
        getline(cin, lok[a].deskripsi);
        cout << "Masukkan Jam Buka Tempat : ";
        getline(cin, lok[a].jam);
        cout << "Masukkan Harga Tiket Tempat (Jika Ada) : ";
        getline(cin, lok[a].harga);
        cout << "Masukkan Jarak Tempat : ";
        getline(cin, lok[a].jarak);
        cout << "Masukkan Ulasan Tempat : ";
        getline(cin, lok[a].ulasan);
        cout << "Masukkan Tag Tempat : ";
        getline(cin, lok[a].tag);
    }

    ofstream file(filename, ios::app);
    if (file.is_open()) {
        for (int i = 0; i < input; i++) {
            file << lok[i].name << endl;
            file << lok[i].jalan << endl;
            file << lok[i].deskripsi << endl;
            file << lok[i].jam << endl;
            file << lok[i].harga << endl;
            file << lok[i].jarak << endl;
            file << lok[i].ulasan << endl;
            file << lok[i].tag << endl;
        }
        file.close();
        cout << "Data telah disimpan ke dalam file." << endl;
    } else {
        cout << "Gagal membuka file." << endl;
    }
    return;
}

void importData() {
    ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < MAX_SIZE; i++) {
            getline(file, lok[i].name);
            getline(file, lok[i].jalan);
            getline(file, lok[i].deskripsi);
            getline(file, lok[i].jam);
            getline(file, lok[i].harga);
            getline(file, lok[i].jarak);
            getline(file, lok[i].ulasan);
            getline(file, lok[i].tag);
        }
        file.close();
        cout << "Data telah diimpor dari file." << endl;
    } else {
        cout << "Gagal membuka file." << endl;
    }
}

void search(string username) {
    string key, pilih;
    int input;
    bool validasi;
    cout << "=====================================================" << endl;
    cout << "                                                     " << endl;
    cout << "                Telusuri Tempat Wisata               " << endl;
    cout << "                                                     " << endl;
    cout << "=====================================================" << endl;
    cout << "Masukkan Nama Tempat Yang Ingin Dicari : ";
    getline(cin,key);
    cout<<"\nHasil Pencarian:\n";
    int found = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (lok[i].name.rfind(key, 0) == 0){
            cout<<"["<<i<<"] "<<lok[i].name<<endl;
            found++;
        }
    }
    if (found == 0) {
        cout << "Nama tidak ditemukan" << endl;
        return;
    }
     do
        {
            cout << "Pilih : ";
            if(cin >> input) {
                if(input > -1 && input < MAX_SIZE){
                    validasi = true;
                }
                else {
                    cout << "Inputan salah!" << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Inputan salah!" << endl;
            }
        } while (!validasi);
    cin.ignore();
        cout << "=====================================================" << endl;
        cout << "                                                     " << endl;
        cout << "                  Informasi Lokasi                   " << endl;
        cout << "                                                     " << endl;
        cout << "=====================================================" << endl;
        cout <<"Nama Tempat\t: "<< lok[input].name<<endl;
        cout <<"Alamat Tempat\t: "<< lok[input].jalan<<endl;
        cout <<"Deskripsi Tempat: "<< lok[input].deskripsi<<endl;
        cout <<"Jam Buka\t: "<< lok[input].jam<<endl;
        cout <<"Harga Tiket\t: "<< lok[input].harga<<endl;
        cout <<"Jarak Tempat\t: "<< lok[input].jarak<<endl;
        cout <<"Rating Tempat\t: "<< lok[input].ulasan<<endl;

        cout << "Apakah anda ingin menambahkannya kek bookmark?(y/t) ";
        cin >> pilih;
        if (pilih == "y" || pilih == "Y") {
            addbookmark(username, input);
        }
}

void survey(string user){
    int suasana, kegiatan, found = 0,input;
    string tag,pilih;
    cout << "=====================================================" << endl;
    cout << "                                                     " << endl;
    cout << "                  Survey Tempat Wisata               " << endl;
    cout << "                                                     " << endl;
    cout << "=====================================================" << endl;
    cout << "Suasana Seperti Apa Yang Anda Inginkan? "<<endl;
    cout << "[1].Alam"<<endl;
    cout << "[2].Non-alam"<<endl;
    cout << "Pilih opsi [1-2] : ";cin >> suasana;
    cin.ignore();
    if(suasana = 1){
        cout << "Kegiatan Seperti Apa Yang Anda Inginkan? "<<endl;
        cout << "[1].Menikmati Pemandangan Alam"<<endl;
        cout << "[2].Melihat-lihat Hewan"<<endl;
        cout << "[3].Kegiatan Outdoor"<<endl;
        cout << "[4].Pantai"<<endl;
        cout << "Pilih opsi [1-4] : ";cin >> kegiatan;
        cin.ignore();
    }
    else if(suasana = 2){
        cout << "Kegiatan Seperti Apa Yang Anda Inginkan? "<<endl;
        cout << "[1].Hiburan"<<endl;
        cout << "[2].Sejarah/Pengetahuan"<<endl;
        cout << "[3].Rekreasi"<<endl;
        cout << "Pilih opsi [1-3] : ";cin >> kegiatan;
        cin.ignore();
    }
    system("cls");
    cout << "=================================================================================" << endl;
    cout << "                                                     " << endl;
    cout << "Berdasarkan Kriteria Yang Anda Pilih, Inilah Beberapa Rekomendasi Tempat Wisata :" << endl;
    cout << "                                                     " << endl;
    cout << "=================================================================================" << endl;
    if (suasana == 1) {
        if (kegiatan == 1) {
            for (int i = 0; i < MAX_SIZE; i++) {
            if (lok[i].tag == "alam-pemandangan"){
                cout<<"["<<i<<"] "<<lok[i].name<<endl;
                found++;
                }
            }
        }
        else if (kegiatan == 2) {
            for (int i = 0; i < MAX_SIZE; i++) {
            if (lok[i].tag == "alam-hewan"){
                cout<<"["<<i<<"] "<<lok[i].name<<endl;
                found++;
                }
            }
            if (found == 0) {
                cout << "Error" << endl;
            }
        }
        else if (kegiatan == 3) {
            for (int i = 0; i < MAX_SIZE; i++) {
            if (lok[i].tag == "alam-outdoor"){
                cout<<"["<<i<<"] "<<lok[i].name<<endl;
                found++;
                }
            }
            if (found == 0) {
                cout << "Error" << endl;
            }
        }
        else if (kegiatan == 4) {
            for (int i = 0; i < MAX_SIZE; i++) {
            if (lok[i].tag == "alam-pantai"){
                cout<<"["<<i<<"] "<<lok[i].name<<endl;
                found++;
                }
            }
            if (found == 0) {
                cout << "Error" << endl;
            }
        }
    }

    if (suasana == 2) {
        if (kegiatan == 1) {
            for (int i = 0; i < MAX_SIZE; i++) {
            if (lok[i].tag == "nonalam-hiburan"){
                cout<<"["<<i<<"] "<<lok[i].name<<endl;
                found++;
                }
            }
        }
        else if (kegiatan == 2) {
            for (int i = 0; i < MAX_SIZE; i++) {
            if (lok[i].tag == "nonalam-sejarah"){
                cout<<"["<<i<<"] "<<lok[i].name<<endl;
                found++;
                }
            }
            if (found == 0) {
                cout << "Error" << endl;
            }
        }
        else if (kegiatan == 3) {
            for (int i = 0; i < MAX_SIZE; i++) {
            if (lok[i].tag == "nonalam-rekreasi"){
                cout<<"["<<i<<"] "<<lok[i].name<<endl;
                found++;
                }
            }
            if (found == 0) {
                cout << "Error" << endl;
            }
        }
    }

    cout<<"Pilih : ";cin>>input;
    cin.ignore();
    if(input > -1 ) {
        cout << "=====================================================" << endl;
        cout << "                                                     " << endl;
        cout << "                  Informasi Lokasi                   " << endl;
        cout << "                                                     " << endl;
        cout << "=====================================================" << endl;
        cout <<"Nama Tempat\t: "<< lok[input].name<<endl;
        cout <<"Alamat Tempat\t: "<< lok[input].jalan<<endl;
        cout <<"Deskripsi Tempat: "<< lok[input].deskripsi<<endl;
        cout <<"Jam Buka\t: "<< lok[input].jam<<endl;
        cout <<"Harga Tiket\t: "<< lok[input].harga<<endl;
        cout <<"Jarak Tempat\t: "<< lok[input].jarak<<endl;
        cout <<"Rating Tempat\t: "<< lok[input].ulasan<<endl;

        cout << "Apakah anda ingin menambahkannya kek bookmark?(y/t) ";
        cin >> pilih;
        if (pilih == "y" || pilih == "Y") {
            addbookmark(user, input);
        }
    }
    else {
        cout << "Input Error";
    }
    }

void aboutUs() {
    cout << "=====================================================" << endl;
    cout << "                                                     " << endl;
	cout << "                       About Us                      " << endl;
    cout << "                                                     " << endl;
	cout << "=====================================================" << endl;
	cout << "  Selamat datang diaplikasi TriPlan teman perjalanan " << endl;
	cout << "yang menyenangkan untuk membantu anda mencari wisata " << endl;
	cout << "impian yang anda inginkan. kami menawarkan pilihan   " << endl;
	cout << "wisata yang beragam dan menarik sesuai dengan        " << endl;
	cout << "keinginan anda.                                      " << endl;
	cout << "=====================================================" << endl;
	cout << endl;
}

void menuUtama(string username) {
    int i,counter,z;
    bool validasi = false,validasi2 = false;
    string user = username;
    do {
        counter = 0;
        system("cls");
        importData();
        cout << "=====================================================" << endl;
        cout << "                                                     " << endl;
        cout << "               Selamat Datang di TriPlan, "<<user<<"!"  << endl;
        cout << "                                                     " << endl;
        cout << "=====================================================" << endl;
        cout << "[1] Telusuri Tempat Wisata" << endl;
        cout << "[2] Rekomendasi Tempat Wisata Berdasarkan Survey" << endl;
        cout << "[3] Bookmark" << endl;
        cout << "[4] About Us" << endl;
        cout << "[5] Exit" << endl;
        cout << "=====================================================" << endl;
        do
        {
            cout << "Pilih menu [1-5]: ";
            if(cin >> i) {
                if(i >= 1 && i <= 5){
                    validasi = true;
                }
                else {
                    cout << "Inputan salah!" << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Inputan salah!" << endl;
            }
        } while (!validasi);
        cin.ignore();
        system("cls");
        switch (i) {
            case 1:
                search(user);
                goto akhir;
            case 2:
                survey(user);
                goto akhir;
            case 3:
                bookmark(user);
                goto akhir;
            case 4:
                aboutUs();
                goto akhir;
            case 5:
                goto end;
            default:

            	break;
        }
        akhir :
        cout << "\nPilih Opsi : "<<endl;
        cout << "[1]Kembali Ke Menu Utama"<<endl;
        cout << "[2]Exit" << endl;
        cout << "Opsi [1-2]: ";
        do
        {
            cout << "Pilih menu [1-2]: ";
            if(cin >> counter) {
                if(counter >= 1 && counter <= 2){
                    validasi2 = true;
                }
                else {
                    cout << "Inputan salah!" << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Inputan salah!" << endl;
            }
        } while (!validasi2);
        cin.ignore();
        if(counter == 1 ){
            continue;
        }
        else if(counter == 2) {
            break;
        }
        else {
            cout << "Input Error!";
            goto akhir;
        }

    } while(counter != 2);
    end :
    	abort();
}

void bersih(){
	ofstream ofs;
	ofs.open("./data.txt", ofstream::out | ofstream::trunc);
	ofs.close();
}
void tambahAdmin()
{
    system("cls");
    string username, password;
    char ch;
    cout << "=====================================================" << endl;
    cout << "                                                     " << endl;
    cout << "                   Register Admin                    " << endl;
    cout << "                                                     " << endl;
    cout << "=====================================================" << endl << endl;
    cout << "Masukan username: ";
    cin >> username;
    cout << "Masukan password: ";
    ch = _getch();
    while (ch != 13)
    {
        if (ch == 8)
        {
            if (password.size() > 0)
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            password.push_back(ch);
            cout << "*";
        }
        ch = _getch();
    }

    ofstream outfile("accounts.txt", ios::app);

        if (outfile.is_open())
        {
            outfile << username << " " << password << " admin" << endl;

            outfile.close();

            system("cls");
            cout << "Akun Berhasil Dibuat!" << endl;
            system("pause");
        }
        else
        {
            system("cls");
            cout << "File Error" << endl;
            system("pause");
        }
}
void MenuAdmin(string user) {
    int i,counter,z;
    string inputbersih;
    bool validasi = false,validasi2 = false;
    do {
        counter = 0;
        system("cls");
        importData();
        cout << "=====================================================" << endl;
        cout << "                                                     " << endl;
        cout << "             Selamat Datang di Menu Admin, "<<user<<"!"  << endl;
        cout << "                                                     " << endl;
        cout << "=====================================================" << endl;
        cout << "[1] Telusuri Tempat Wisata" << endl;
        cout << "[2] Rekomendasi Tempat Wisata Berdasarkan Survey" << endl;
        cout << "[3] Cek Bookmark Semua User(Khusus Admin)" << endl;
        cout << "[4] About Us" << endl;
        cout << "[5] Exit" << endl;
        cout << "[6] Input Lokasi Baru(Khusus Admin)" << endl;
        cout << "[7] Membersihkan Semua Data Bookmark(Khusus Admin)" << endl;
        cout << "[8] Tambah Akun Admin" << endl;
        cout << "=====================================================" << endl;
        do
        {
            cout << "Pilih menu [1-8]: ";
            if(cin >> i) {
                if(i >= 1 && i <= 8){
                    validasi = true;
                }
                else {
                    cout << "Inputan salah!" << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Inputan salah!" << endl;
            }
        } while (!validasi);
        cin.ignore();
        system("cls");
        switch (i) {
            case 1:
                search("admin");
                goto akhir;
            case 2:
                survey("admin");
                goto akhir;
            case 3:
                semuabookmark();
                goto akhir;
            case 4:
                aboutUs();
                goto akhir;
            case 5:
                goto end;
            case 6:
                input();
                goto akhir;
            case 7:
            	cout << "Apakah Anda Yakin Ingin Menghapus Semua Bookmark User?(y/n) : ";getline(cin,inputbersih);
            	if(inputbersih == "y" || inputbersih == "Y"){
            	bersih();
            	}
            	goto akhir;
            case 8:
                tambahAdmin();
                goto akhir;
            default:

            	break;
        }
        akhir :
        cout << "\nPilih Opsi : "<<endl;
        cout << "[1]Kembali Ke Menu Utama"<<endl;
        cout << "[2]Exit" << endl;
        do
        {
            cout << "Pilih menu [1-2]: ";
            if(cin >> counter) {
                if(counter >= 1 && counter <= 2){
                    validasi2 = true;
                }
                else {
                    cout << "Inputan salah!" << endl;
                }
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Inputan salah!" << endl;
            }
        } while (!validasi2);
        cin.ignore();
        if(counter == 1 ){
            continue;
        }
        else if(counter == 2) {
            break;
        }
        else {
            cout << "Input Error!";
            goto akhir;
        }

    } while(counter != 2);
    end :
    	abort();
}

void login() {
    string username, password, fileUsername, filePassword,fileRole;
    char ch;
    for (int i = 2; i >= 0; i--) {
        system("cls");
        cout << "=====================================================" << endl;
        cout << "                Selamat Datang di TriPlan            " << endl;
        cout << "                                                     " << endl;
        cout << "                     Silahkan Login                  " << endl;
        cout << "=====================================================" << endl << endl;

        cout << "Masukan username: ";
        cin >> username;
        cout << "Masukan password: ";
        ch = _getch();
        while (ch != 13)
        {
            if (ch == 8) {
                if (password.size() > 0 )
                {
                    password.pop_back();
                    cout << "\b \b";
                }

            }
            else {
                password.push_back(ch);
                cout << "*";
            }
            ch = _getch();
        }


        ifstream infile("./accounts.txt");

        if (infile.is_open())
            {
                bool found = false;

                while (infile >> fileUsername >> filePassword >> fileRole)
                {
                    if (username == fileUsername && password == filePassword && fileRole == "admin")
                    {
                        system("cls");
                        cout << "Login Berhasil!" << endl;
                        system("pause");
                        MenuAdmin(username);
                        break;
                    }
                    else if (username == fileUsername && password == filePassword && fileRole == "user")
                    {
                        found = true;
                        break;
                    }
                }

                infile.close();

                if (found)
                {
                    system("cls");
                    cout << "Login Berhasil!" << endl;
                    system("pause");
                    menuUtama(username);
                    break;
                }
                else
                {

                    if (i > 0)
                    {
                        system("cls");
                        cout << "Username atau Password salah!" << endl;
                        cout << "Kesempatan anda tersisa " << i << " lagi" << endl;
                        system("pause");
                    }
                }
            }
            else
            {
                cout << "File Error!!";
                system("pause");
            }
        }
        system("cls");
        cout << "Anda tidak bisa mengakses aplikasi ini" << endl;
    }

void daftarAkun() {
    string username, password;
    system("cls");
    cout << "=====================================================" << endl;
    cout << "                Selamat Datang di TriPlan            " << endl;
    cout << "                                                     " << endl;
    cout << "                     Silahkan Daftar                 " << endl;
    cout << "=====================================================" << endl << endl;

    cout << "Masukan username: ";
    cin >> username;
    cout << "Masukan password: ";
    cin >> password;

    ofstream outfile("./accounts.txt", ios::app);

    if (outfile.is_open()) {
        outfile << username << " " << password << endl;

        outfile.close();

        system("cls");
        cout << "Akun Berhasil Dibuat!" << endl;
        system("pause");
        return login();
    }
    else {
        system("cls");
        cout << "File Error" << endl;
        system("pause");
    }
}
int main() {
    system("cls");
    string pilih_login;

    cout << "=====================================================" << endl;
    cout << "                Selamat Datang di TriPlan            " << endl;
    cout << "                                                     " << endl;
    cout << "                     Silahkan Login                  " << endl;
    cout << "=====================================================" << endl;
    cout << "Apakah anda sudah mempunyai akun?(y/t) ";
    cin >> pilih_login;
    if (pilih_login == "y" || pilih_login == "Y") {
        login();
    }

    else if (pilih_login == "t" || pilih_login == "T") {
        daftarAkun();
    }

    else {
        cout << "Inputan salah!!" << endl;
        system("pause");
        return main();
    }

    cout << "=====================================================" << endl;

    return 0;
}
