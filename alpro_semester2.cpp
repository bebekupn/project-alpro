#include <iostream>
#include <string>

using namespace std;

struct Produk {
    int id;
    string nama;
    int stok;
    int harga;
};

struct kategori {
    string nama_kategori;
    struct Produk produk[10];
    int jum_produk = 0;

};

struct rak {
    string nama_rak;
    struct kategori kategori1[10];
    int jum_kategori = 0;
};

rak rak1[100];
int total_rak = 0;

int binarySearch(Produk arr[], int kiri, int kanan, int x) {
    if (kanan >= kiri) {
        int mid = kiri + (kanan - kiri) / 2;

        if (arr[mid].id == x)
            return mid;

        if (arr[mid].id > x)
            return binarySearch(arr, kiri, mid - 1, x);

        return binarySearch(arr, mid + 1, kanan, x);
    }

    return -1;
}

int main(){
    string username, password;
    int salah = 0;

    // do{
    //     cout << "== login section ==" << endl;
    //     cout << "username: ";
    //     getline(cin, username);
    //     cout << "password: ";
    //     getline(cin, password);
    //     if (username == "admin" && password == "admin123"){
    //         cout << "Login successful!" << endl;
    //     } else {
    //         salah ++ ;
    //         cout << "Login failed. Invalid username or password." << endl;
    //     }   
    // }while (salah < 3 && salah != 0);
    // if (salah == 3){
    //     cout << "Too many failed login attempts. Access denied." << endl;
    //     return 0;
    // }

    cout << "Login successful!" << endl;
    int menu;
     
    do {
    cout << "\n== Manajemen Produk Toko ==" << endl;
    cout << "MENU UTAMA" << endl;
    cout << " 1. Input data barang" << endl;
    cout << " 2. Tampilkan data barang (sorted)" << endl;
    cout << " 3. Cari produk berdasarkan id" << endl;
    cout << " 4. Ubah detail produk" << endl;
    cout << " 5. Keluar" << endl;
    cout << "Pilih menu: ";
    cin >> menu;

    switch (menu){
        case 1: {
            cout << "\n===== INPUT DATA BARANG =====" << endl;
            cout << "Berapa banyak rak yang ingin ditambahkan? ";
            cin >> total_rak;
            for (int i = 0; i < total_rak; i++) {
                cout << "Masukkan nama rak: ";
                cin >> rak1[i].nama_rak;
                cout << "Berapa banyak kategori yang ingin ditambahkan? ";
                cin >> rak1[i].jum_kategori;
                for (int j = 0; j < rak1[i].jum_kategori; j++){
                    cout << "Masukkan nama kategori: ";
                    cin >> rak1[i].kategori1[j].nama_kategori;
                    cout << "Berapa banyak data yang ingin diinput? ";
                    cin >> rak1[i].kategori1[j].jum_produk;
                    for (int k = 0; k < rak1[i].kategori1[j].jum_produk; k++){
                        cout << "\nPRODUK ke-" << k + 1 << ":\n";
                        cout << "ID: "; cin >> rak1[i].kategori1[j].produk[k].id;
                        cout << "Nama: "; getline(cin >> ws, rak1[i].kategori1[j].produk[k].nama);
                        cout << "Stok: "; cin >> rak1[i].kategori1[j].produk[k].stok;
                        cout << "Harga: "; cin >> rak1[i].kategori1[j].produk[k].harga;
                    }
                
                    int n = rak1[i].kategori1[j].jum_produk;
                    for (int a = 0; a < n - 1; a++) {
                        for (int b = 0; b < n - a - 1; b++) {
                            if (rak1[i].kategori1[j].produk[b].id > rak1[i].kategori1[j].produk[b+1].id) {
                                Produk temp = rak1[i].kategori1[j].produk[b];
                                rak1[i].kategori1[j].produk[b] = rak1[i].kategori1[j].produk[b+1];
                                rak1[i].kategori1[j].produk[b+1] = temp;
                            }
                        }
                    }
                }
            }    
        break;
        } case 2: {
            cout << "\n===== DAFTAR PRODUK (SORTED) =====" << endl;
            for (int i = 0; i < total_rak; i++) {
                cout << "==============================\n";
                cout << "Rak: " << rak1[i].nama_rak << endl;
                for (int j = 0; j < rak1[i].jum_kategori; j++) {
                    cout << "Kategori: " << rak1[i].kategori1[j].nama_kategori << endl;
                    for (int k = 0; k < rak1[i].kategori1[j].jum_produk; k++){
                        cout << k+1 << ". \n";
                        cout << "ID: " << rak1[i].kategori1[j].produk[k].id << endl;
                        cout << "Nama: " << rak1[i].kategori1[j].produk[k].nama << endl;
                        cout << "Stok: " << rak1[i].kategori1[j].produk[k].stok << endl;
                        cout << "Harga: " << rak1[i].kategori1[j].produk[k].harga << endl;
                        cout << "-----" << endl;
                    }
                }
            }
        break;
        } case 3: {
            int id_cari, ketemu;
            bool ditemukan = false;
            cout << "\n===== CARI PRODUK DENGAN ID =====\n";
            cout << "Masukkan id produk yang ingin dicari: ";
            cin >> id_cari;
            for (int a = 0; a < total_rak; a++) {
                for (int b = 0; b < rak1[a].jum_kategori; b++) {
                    ketemu = binarySearch(rak1[a].kategori1[b].produk, 0, rak1[a].kategori1[b].jum_produk - 1, id_cari);

                    if (ketemu != -1) {
                        cout << "Ditemukan! Detail produk: \n";
                        cout << "ID: " << rak1[a].kategori1[b].produk[ketemu].id << endl;
                        cout << "Nama: " << rak1[a].kategori1[b].produk[ketemu].nama << endl;
                        cout << "Stok: " << rak1[a].kategori1[b].produk[ketemu].stok << endl;
                        cout << "Harga: " << rak1[a].kategori1[b].produk[ketemu].harga << endl;
                        ditemukan = true;
                        break;
                    } 
                    
                    if (ditemukan) break;
                }
            }
            if (!ditemukan) {
                cout << "Maaf, produk dengan id " << id_cari << "tidak ada.\n";
            }
        break;
        } case 4:{
            int idUbah, stokBaru, hargaBaru;
            string namaBaru;
            bool found = false;

            cout << "\n===== UBAH DETAIL PRODUK (SELAIN ID)=====" << endl;
            cout << "[NOTE]: Tidak boleh mengubah ID Produk sebelumnya!\n";
            cout << "\nMasukkan id produk yang ingin diubah: "; cin >> idUbah;

            for (int a = 0; a < total_rak; a++) {
                for (int b = 0; b < rak1[a].jum_kategori; b++) {
                    for (int c = 0; c < rak1[a].kategori1[b].jum_produk; c++) {
                        if (rak1[a].kategori1[b].produk[c].id == idUbah) {
                            cout << "Data ditemukan!\n"; 
                            cout << "Masukkan Nama Baru: "; getline(cin >> ws, rak1[a].kategori1[b].produk[c].nama);
                            cout << "Stok Baru: "; cin >> rak1[a].kategori1[b].produk[c].stok;
                            cout << "Harga Baru: "; cin >> rak1[a].kategori1[b].produk[c].harga;
                            found = true;
                            break; 
                        }
                    }
                }
            }
            if (!found) cout << "ID tidak ditemukan di seluruh rak!\n";
            break;
        } case 5:{
            cout << "Program akan berhenti, keluar dari program.\n" << endl;
            return 0;
            break;
        } default:{
            cout << "Pilihan tidak valid! Coba lagi." << endl;
        }
    }
    } while (menu != 6);    
}