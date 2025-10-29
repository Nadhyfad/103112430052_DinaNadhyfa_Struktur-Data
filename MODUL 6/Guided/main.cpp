#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);
    
    int jumlahData = 0;
    const int MAX_DATA = 3; // Sesuai contoh output
    
    // Input data kendaraan
    while (jumlahData < MAX_DATA) {
        infotype kendaraan;
        
        cout << "masukkan nomor polisi: ";
        cin >> kendaraan.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> kendaraan.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> kendaraan.thnBuat;
        cout << endl;
        
        // Cek apakah nomor polisi sudah terdaftar
        if (isNopolExist(L, kendaraan.nopol)) {
            cout << "nomor polisi sudah terdaftar" << endl;
            cout << endl;
        } else {
            // Jika belum terdaftar, tambahkan ke list
            address P = alokasi(kendaraan);
            insertLast(L, P);
            jumlahData++;
        }
    }
    
    cout << "DATA LIST 1" << endl;
    cout << endl;
    printInfo(L);
    
    // Pencarian nomor polisi
    string nopolCari;
    cout << "Masukkan nomor polisi yang dicari: ";
    cin >> nopolCari;
    
    address hasilCari = findElm(L, nopolCari);
    
    if (hasilCari != NULL) {
        cout << "nopol    : " << hasilCari->info.nopol << endl;
        cout << "warna    : " << hasilCari->info.warna << endl;
        cout << "tahun    : " << hasilCari->info.thnBuat << endl;
    } else {
        cout << "Nomor polisi " << nopolCari << " tidak ditemukan" << endl;
    }
    
      // Menghapus data berdasarkan nomor polisi
    string nopolHapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus: ";
    cin >> nopolHapus;

        address P = findElm(L, nopolHapus);
    
    if (P != NULL) {
        deleteByNopol(L, nopolHapus);
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl;
    }
    
    cout << endl;
    
    cout << "DATA LIST 1" << endl;
    
    printInfo(L);
    
    return 0;
}