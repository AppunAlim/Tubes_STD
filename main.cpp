#include <iostream>
#include <limits>
#include "header.h"

using namespace std;

int main()
{
    adrNode root = newNode("My Music Library", "Root");

    int pilihan;
    string namaBaru, namaInduk;
    adrNode lokasiInduk = nullptr;

    do {
        menu();
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(pilihan) {
        case 1:
            cout << "Masukkan Nama Genre: ";
            getline(cin, namaBaru);
            insertNode(root, namaBaru, "Genre");
            break;

        case 2:
            cout << "Masukkan Nama Genre induknya: ";
            getline(cin, namaInduk);

            lokasiInduk = findNode(root, namaInduk);
            if (lokasiInduk != nullptr && lokasiInduk->info.tipe == "Genre") {
                cout << "Masukkan Nama Artist: ";
                getline(cin, namaBaru);
                insertNode(lokasiInduk, namaBaru, "Artist");
                cout << ">> Artist berhasil ditambahkan!" << endl;
            } else {
                cout << ">> Error: Genre tidak ditemukan!" << endl;
            }
            break;

        case 3:
            cout << "Masukkan Nama Artist induknya: ";
            getline(cin, namaInduk);

            lokasiInduk = findNode(root, namaInduk);
            if (lokasiInduk != nullptr && lokasiInduk->info.tipe == "Artist") {
                cout << "Masukkan Nama Album: ";
                getline(cin, namaBaru);
                insertNode(lokasiInduk, namaBaru, "Album");
                cout << ">> Album berhasil ditambahkan!" << endl;
            } else {
                cout << ">> Error: Artist tidak ditemukan!" << endl;
            }
            break;

        case 4:
            cout << "Masukkan Nama Album induknya: ";
            getline(cin, namaInduk);

            lokasiInduk = findNode(root, namaInduk);
            if (lokasiInduk != nullptr && lokasiInduk->info.tipe == "Album") {
                cout << "Masukkan Judul Lagu: ";
                getline(cin, namaBaru);
                insertNode(lokasiInduk, namaBaru, "Lagu");
                cout << ">> Lagu berhasil ditambahkan!" << endl;
            } else {
                cout << ">> Error: Album tidak ditemukan!" << endl;
            }
            break;

        case 5:
            cout << "\n=== Tampilan Playlist ===" << endl;
            levelOrder(root->firstChild, 0);
            break;

         case 6:
            cout << "\n=== Tampilan PreOrder ===" << endl;
            preOrder(root);
            break;

         case 7:
            cout << "\n=== Tampilan InOrder ===" << endl;
            inOrder(root);
            break;

         case 8:
            cout << "\n=== Tampilan PostOrder ===" << endl;
            postOrder(root);
            break;

        case 0:
            cout << "Keluar program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }

    } while (pilihan != 0);

    return 0;
}
