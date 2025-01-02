#include <iostream>
#include <sstream>
using namespace std;

int main() {
    const int MAX_MENU = 100;
    char namaMenu[MAX_MENU][50];
    int hargaMenu[MAX_MENU];
    int terjualMenu[MAX_MENU] = {0};
    int ketersediaanMenu[MAX_MENU] = {0};
    int jumlahMenu = 3;

    for (int i = 0; i < 50; i++) namaMenu[0][i] = '\0';
    namaMenu[0][0] = 'E'; namaMenu[0][1] = 's'; namaMenu[0][2] = 'p'; namaMenu[0][3] = 'r'; namaMenu[0][4] = 'e'; namaMenu[0][5] = 's'; namaMenu[0][6] = 's'; namaMenu[0][7] = 'o';
    hargaMenu[0] = 20000;
    ketersediaanMenu[0] = 1;

    for (int i = 0; i < 50; i++) namaMenu[1][i] = '\0';
    namaMenu[1][0] = 'L'; namaMenu[1][1] = 'a'; namaMenu[1][2] = 't'; namaMenu[1][3] = 't'; namaMenu[1][4] = 'e';
    hargaMenu[1] = 25000;
    ketersediaanMenu[1] = 1;

    for (int i = 0; i < 50; i++) namaMenu[2][i] = '\0';
    namaMenu[2][0] = 'C'; namaMenu[2][1] = 'a'; namaMenu[2][2] = 'p'; namaMenu[2][3] = 'p'; namaMenu[2][4] = 'u'; namaMenu[2][5] = 'c'; namaMenu[2][6] = 'c'; namaMenu[2][7] = 'i'; namaMenu[2][8] = 'n'; namaMenu[2][9] = 'o';
    hargaMenu[2] = 30000;
    ketersediaanMenu[2] = 1;

    int penjualan[MAX_MENU][24] = {0};
    char antrianPesanan[100][200];
    int jumlahPesanan = 0;

    int peran;
    do {
        cout << "Selamat datang di Sistem Manajemen Operasional Kedai Kopi (COMS)!\n";
        cout << "Pilih peran Anda:\n1. Pemilik\n2. Kasir\n3. Keluar\nPilihan: ";
        cin >> peran;

        if (peran == 1) {
            int pilihan;
            do {
                cout << "\nMenu Pemilik:\n";
                cout << "1. Manajemen Menu\n";
                cout << "2. Tinjauan Bisnis\n";
                cout << "3. Keluar\n";
                cout << "Pilihan: ";
                cin >> pilihan;

                if (pilihan == 1) {
                    int subPilihan;
                    do {
                        cout << "\nManajemen Menu:\n";
                        cout << "1. Input/Update Menu\n";
                        cout << "2. Lihat Menu Terlaris\n";
                        cout << "3. Keluar\n";
                        cout << "Pilihan: ";
                        cin >> subPilihan;

                        if (subPilihan == 1) {
                            cin.ignore();
                            char nama[50];
                            int harga;

                            cout << "\nMasukkan nama menu baru: ";
                            cin.getline(nama, 50);
                            cout << "Masukkan harga untuk " << nama << ": Rp ";
                            cin >> harga;

                            for (int i = 0; i < 50; i++) namaMenu[jumlahMenu][i] = '\0';
                            for (int i = 0; nama[i] != '\0'; i++) namaMenu[jumlahMenu][i] = nama[i];
                            hargaMenu[jumlahMenu] = harga;
                            ketersediaanMenu[jumlahMenu] = 1;
                            terjualMenu[jumlahMenu] = 0;
                            jumlahMenu++;

                            cout << nama << " telah ditambahkan ke menu dengan harga Rp " << harga << ".\n";
                        } else if (subPilihan == 2) {
                            int indeksTerbaik = -1;
                            for (int i = 0; i < jumlahMenu; ++i) {
                                if (indeksTerbaik == -1 || terjualMenu[i] > terjualMenu[indeksTerbaik]) {
                                    indeksTerbaik = i;
                                }
                            }

                            if (indeksTerbaik != -1) {
                                cout << "\nMenu Terlaris: " << namaMenu[indeksTerbaik] << " (" << terjualMenu[indeksTerbaik] << " terjual)\n";
                            } else {
                                cout << "Belum ada data penjualan.\n";
                            }
                        } else if (subPilihan != 3) {
                            cout << "Pilihan tidak valid. Coba lagi.\n";
                        }
                    } while (subPilihan != 3);
                } else if (pilihan == 2) {
                    int subPilihan;
                    do {
                        cout << "\nTinjauan Bisnis:\n";
                        cout << "1. Lihat Penjualan Harian\n";
                        cout << "2. Lihat Jam Sibuk\n";
                        cout << "3. Keluar\n";
                        cout << "Pilihan: ";
                        cin >> subPilihan;

                        if (subPilihan == 1) {
                            cout << "\nPenjualan Per Jam:\n";
                            for (int jam = 0; jam < 24; ++jam) {
                                bool adaPenjualan = false;
                                for (int i = 0; i < jumlahMenu; ++i) {
                                    if (penjualan[i][jam] > 0) {
                                        adaPenjualan = true;
                                        cout << "Jam " << jam << ": " << namaMenu[i] << " - " << penjualan[i][jam] << " terjual\n";
                                    }
                                }
                                if (!adaPenjualan) {
                                    cout << "Jam " << jam << ": Tidak ada penjualan\n";
                                }
                            }
                        } else if (subPilihan == 2) {
                            int jamSibuk = 0, penjualanTertinggi = 0;
                            for (int jam = 0; jam < 24; ++jam) {
                                int totalPenjualan = 0;
                                for (int i = 0; i < jumlahMenu; ++i) {
                                    totalPenjualan += penjualan[i][jam];
                                }
                                if (totalPenjualan > penjualanTertinggi) {
                                    penjualanTertinggi = totalPenjualan;
                                    jamSibuk = jam;
                                }
                            }
                            cout << "\nJam Sibuk: " << jamSibuk << " dengan " << penjualanTertinggi << " item terjual.\n";
                        } else if (subPilihan != 3) {
                            cout << "Pilihan tidak valid. Coba lagi.\n";
                        }
                    } while (subPilihan != 3);
                } else if (pilihan != 3) {
                    cout << "Pilihan tidak valid. Coba lagi.\n";
                }
            } while (pilihan != 3);
        } else if (peran == 2) {
            int pilihan;
            do {
                cout << "\nMenu Kasir:\n";
                cout << "1. Pemrosesan Pesanan\n";
                cout << "2. Manajemen Layanan\n";
                cout << "3. Keluar\n";
                cout << "Pilihan: ";
                cin >> pilihan;

                if (pilihan == 1) {
                    cout << "\nMenu:\n";
                    for (int i = 0; i < jumlahMenu; ++i) {
                        cout << i + 1 << ". " << namaMenu[i] << " - Rp " << hargaMenu[i];
                        if (ketersediaanMenu[i] == 1) {
                            cout << " (Tersedia)";
                        } else {
                            cout << " (Tidak Tersedia)";
                        }
                        cout << endl;
                    }

                    cin.ignore();
                    char inputMenu[200];
                    cout << "\nMasukkan nomor menu (misal: 1,2,3): ";
                    cin.getline(inputMenu, 200);

                    stringstream ss(inputMenu);
                    string item;

                    int jam;
                    cout << "Masukkan jam pemesanan (0-23): ";
                    cin >> jam;

                    if (jam < 0 || jam > 23) {
                        cout << "Jam tidak valid.\n";
                        continue;
                    }

                    int totalBiaya = 0;
                    char pesananItem[200];
                    for (int i = 0; i < 200; i++) pesananItem[i] = '\0';

                    while (getline(ss, item, ',')) {
                        int pilihanMenu = stoi(item) - 1;
                        if (pilihanMenu < 0 || pilihanMenu >= jumlahMenu || ketersediaanMenu[pilihanMenu] == 0) {
                            cout << "Menu tidak valid atau tidak tersedia: " << pilihanMenu + 1 << "\n";
                            continue;
                        }

                        int jumlah;
                        cout << "Masukkan jumlah untuk " << namaMenu[pilihanMenu] << ": ";
                        cin >> jumlah;

                        terjualMenu[pilihanMenu] += jumlah;
                        penjualan[pilihanMenu][jam] += jumlah;

                        int index = 0;
                        while (pesananItem[index] != '\0') index++;

                        for (int i = 0; namaMenu[pilihanMenu][i] != '\0'; i++) {
                            pesananItem[index++] = namaMenu[pilihanMenu][i];
                        }

                        pesananItem[index++] = ' ';
                        pesananItem[index++] = 'x';

                        string jumlahStr = to_string(jumlah);
                        for (int i = 0; i < jumlahStr.length(); i++) {
                            pesananItem[index++] = jumlahStr[i];
                        }

                        pesananItem[index++] = ',';
                        pesananItem[index++] = ' ';
                        pesananItem[index] = '\0';
                    }

                    int length = 0;
                    while (pesananItem[length] != '\0') length++;
                    if (length > 2) pesananItem[length - 2] = '\0';

                    cout << "\nPesanan selesai. Total Biaya: Rp " << totalBiaya << endl;
                    for (int i = 0; pesananItem[i] != '\0'; i++) {
                        antrianPesanan[jumlahPesanan][i] = pesananItem[i];
                    }
                    antrianPesanan[jumlahPesanan][length] = '\0';
                    jumlahPesanan++;
                } else if (pilihan == 2) {
                    int subPilihan;
                    do {
                        cout << "\nManajemen Layanan:\n";
                        cout << "1. Perbarui Status Pesanan\n";
                        cout << "2. Lihat Antrian Pesanan\n";
                        cout << "3. Keluar\n";
                        cout << "Pilihan: ";
                        cin >> subPilihan;

                        if (subPilihan == 1) {
                            if (jumlahPesanan == 0) {
                                cout << "\nTidak ada pesanan untuk diperbarui.\n";
                                continue;
                            }

                            cout << "\nMemperbarui status untuk pesanan:\n";
                            cout << "Item: " << antrianPesanan[0] << "\n";

                            for (int i = 1; i < jumlahPesanan; ++i) {
                                for (int j = 0; antrianPesanan[i][j] != '\0'; j++) antrianPesanan[i - 1][j] = antrianPesanan[i][j];
                            }
                            jumlahPesanan--;
                            cout << "Status pesanan diperbarui menjadi Selesai.\n";
                        } else if (subPilihan == 2) {
                            if (jumlahPesanan == 0) {
                                cout << "\nTidak ada pesanan dalam antrian.\n";
                                continue;
                            }

                            cout << "\nAntrian Pesanan Saat Ini:\n";
                            for (int i = 0; i < jumlahPesanan; ++i) {
                                cout << i + 1 << ". " << antrianPesanan[i] << "\n";
                            }
                        } else if (subPilihan != 3) {
                            cout << "Pilihan tidak valid. Coba lagi.\n";
                        }
                    } while (subPilihan != 3);
                } else if (pilihan != 3) {
                    cout << "Pilihan tidak valid. Coba lagi.\n";
                }
            } while (pilihan != 3);
        } else if (peran == 3) {
            cout << "Keluar dari sistem. Sampai jumpa!\n";
        } else {
            cout << "Peran tidak valid. Coba lagi.\n";
        }
    } while (peran != 3);

    return 0;
}
