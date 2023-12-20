// Preprocessing Directive
#include <iostream>  //library
#include <conio.h>   // Untuk Getch() {pause}
#include <vector>    // Untuk Tipe Data vector {level atas aray} , aray = kumpulan data
#include <ctime>     // Untuk Waktu saat ini
#include <windows.h> // Untuk Sleep() Dan warna
#ifdef _WIN32        // untuk warna awal
#endif               // untuk warna selesai

using namespace std;

// SEGMEN A:
// vektor ukuran menyesuaikan data yangh diinputkan
// Tipe Data Vector -> Next Level Array
vector<string> rute_terpilih;                   // vector biasa
vector<vector<string>> deskripsi_rute_terpilih; // vector 2 dimensi
vector<vector<string>> opsi_rute_terpilih;      // vector 2 dimensi
vector<vector<string>> riwayat_perjalanan;      // Menyimpan data riwayat perjalanan
vector<string> data_riwayat;                    // vector biasa
// ENDSEGMEN A

// SEGMEN B:
vector<vector<string>> semua_rute = {{"1-2", "1", "2"}, {"1-3", "3", "4", "5"}, {"1-4", "6", "7"}, {"1-5", "8", "9"}, {"2-1", "10", "11"}, {"2-3", "12"}, {"2-4", "13", "14"}, {"2-5", "15"}, {"3-1", "16", "17"}, {"3-2", "18"}, {"3-4", "19", "20"}, {"3-5", "21"}, {"4-1", "22", "23"}, {"4-2", "24", "25"}, {"4-3", "26", "27"}, {"4-5", "28", "29"}, {"5-1", "30", "31"}, {"5-2", "32", "33"}, {"5-3", "34", "35"}, {"5-4", "36"}};
// Semua rute, isinya semua rute perjalanan dan nomor perjalanannya, Formatnya = {"lokasi awal dan tujuan misal 1 itu cibiru, 2 itu setiabudi, jadi tulis 1-2, sesaui index array list lokasi di bawah ditambah 1 angka, jadi kalo mau setiabudi-ujung berung tulisnya 2-4", "opsi kode perjalanannya sesuai sama deskripsi rute, bebas mau ada berapa", "6", "7"}

vector<vector<vector<string>>> deskripsi_rute = {{{"1"}, {"2"}, {"Angkot dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Terminal Cicaheum", "Cicaheum-Ledeng", "Ledeng", "Pusdikkum TNI AD"}, {"100"}, {"4000"}}, {{"2"}, {"3"}, {"Angkot, Angkot, dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Terminal Cicaheum", "Cicaheum-Ciroyom", "Ciroyom", "RS Hasan Sadikin", "Ciroyom-Lembang", "Lembang", "Pusdikkum TNI AD"}, {"155"}, {"5000"}}, {{"3"}, {"2"}, {"Angkot dan Angkot"}, {"Cibiru-Cicadas", "Cicadas", "UNINUS", "Gede bage-Stasiun Hall", "Stasiun Hall", "Stasiun Bandung"}, {"75"}, {"4000"}}, {{"4"}, {"2"}, {"Angkot dan Kereta"}, {"Cibiru-Cicadas", "Cicadas", "Berkah Jaya Shoes", "Stasiun Kiaracondong-Padalarang", "Padalarang", "Stasiun Bandung"}, {"61"}, {"4500"}}, {{"5"}, {"2"}, {"Angkot dan Angkot"}, {"Cibiru-Cicadas", "Cicadas", "Kadin Jabar", "Antapani-Ciroyom", "Ciroyom", "Ampera Kebon Kawung"}, {"75"}, {"4000"}}, {{"6"}, {"1"}, {"Angkot"}, {"Cicaheum-Cileunyi", "Cileunyi", "Ujung Berung"}, {"41"}, {"2000"}}, {{"7"}, {"2"}, {"Angkot dan Angkot"}, {"Cibiru-Cicadas", "Cicadas", "Eat Boss/Sebrang Gede Bage", "Bumi Panyileukan-Sekemirung", "Sekemirung", "Halte Pusjatan"}, {"66"}, {"4000"}}, {{"8"}, {"2"}, {"Angkot dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Terminal Cicaheum", "Cicaheum-Ciroyom", "Ciroyom", "Geologi"}, {"70"}, {"4000"}}, {{"9"}, {"2"}, {"Angkot dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Terminal Cicaheum", "Cicaheum-Ledeng", "Ledeng", "Lapangan Gasibu B"}, {"76"}, {"4000"}}, {{"10"}, {"2"}, {"Angkot dan Angkot"}, {"Cicaheum-Ledeng", "Cicaheum", "Roti Bakar Cicaheum", "Cicaheum-Cileunyi", "Cileunyi", "Waroeng Nenek Cipadung"}, {"106"}, {"4000"}}, {{"11"}, {"2"}, {"Angkot dan Damri"}, {"Cicaheum-Ledeng", "Cicaheum", "Roti Bakar Cicaheum", "Lewipanjang-Cibiru", "Cibiru", "Halte SDN Cipadung"}, {"70"}, {"5000"}}, {{"12"}, {"1"}, {"Angkot"}, {"Abdul Muis-Ledeng", "Abdul Muis", "Stasiun Bandung"}, {"42"}, {"2000"}}, {{"13"}, {"3"}, {"Angkot, Angkot, dan Angkot"}, {"Abdul Muis-Ledeng", "Abdul Muis", "Kembang Hotel", "Cicaheum-Ciroyom", "Cicaheum", "Roti Bakar Cicaheum", "Bumi Panyileukan-Sekemirung", "Bumi Panyileukan", "SMAN 24 Bandung"}, {"81"}, {"6000"}}, {{"14"}, {"2"}, {"Angkot dan Damri"}, {"Cicaheum-Ledeng", "Cicaheum", "Roti Bakar Cicaheum", "Leuwipanjang-Cibiru", "Cibiru", "UPTD Laboratorium Lingkungan Hidup Bandung"}, {"105"}, {"5000"}}, {{"15"}, {"1"}, {"Angkot"}, {"Abdul Muis-Ledeng", "Abdul Muis", "Gedung Sate"}, {"39"}, {"2000"}}, {{"16"}, {"2"}, {"Angkot dan Angkot"}, {"Abdul Muis-Cicaheum Via Aceh", "Cicaheum Via Aceh", "Roti Bakar Cicaheum", "Cicaheum-Cileunyi", "Cileunyi", "Waroen Nenek Cipadung"}, {"119"}, {"4000"}}, {{"17"}, {"2"}, {"Kereta dan Angkot"}, {"Stasiun Bandung-Stasiun Kiaracondong", "Stasiun Kiaracondong", "Kiaracondong", "Cibiru-Cicadas", "Cibiru", "Mc Donalds Cibiru"}, {"90"}, {"4500"}}, {{"18"}, {"1"}, {"Angkot"}, {"Abdul Muis-Ledeng", "Ledeng", "Museum Upi Setiabudi"}, {"35"}, {"2000"}}, {{"19"}, {"2"}, {"Angkot dan Angkot"}, {"Stasiun Hall-Dago", "Dago", "Kartika Sari A", "Bumi Panyileukan-Sekemirung", "Bumi Panyileukan", "SMAN 24 Bandung"}, {"64"}, {"4000"}}, {{"20"}, {"2"}, {"Angkot dan Angkot"}, {"Stasiun Hall-Sadang Serang", "Sadang Serang", "Alfamart Supratman 104", "Bumi Panyileukan-Sekemirung", "Bumi Panyileukan", "SMAN 24 Bandung"}, {"65"}, {"4000"}}, {{"21"}, {"1"}, {"Angkot"}, {"Abdul Muis-Dago", "Dago", "Moxy Bandung"}, {"38"}, {"2000"}}, {{"22"}, {"2"}, {"Angkot dan Angkot"}, {"Cicaheum-Ciroyom", "Cicaheum", "Roti Bakar Cicaheum", "Cicaheum-Cileunyi", "Cileunyi", "Waroeng Nenek Cipadung"}, {"75"}, {"4000"}}, {{"23"}, {"2"}, {"Angkot dan Damri"}, {"Cicaheum-Ledeng", "Cicaheum", "Roti Bakar Cicaheum", "Leuwipanjang-Cibiru", "Cibiru", "Halte SDN Cipadung"}, {"105"}, {"5000"}}, {{"24"}, {"2"}, {"Angkot dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Terminal Cicaheum", "Cicaheum-Ledemg", "Ledeng", "Museum UPI Setiabudi"}, {"89"}, {"4000"}}, {{"25"}, {"3"}, {"Angkot, Angkot dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Terminal Cicaheum", "Cicaheum-Ciroyom", "Ciroyom", "Paskal", "Ciroyom-Lembang", "Lembang", "Museum UPI Setiabudi"}, {"115"}, {"6000"}}, {{"26"}, {"3"}, {"Angkot, Angkot dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Terminal Cicaheum", "Cicaheum-Ciroyom", "Ciroyom", "Citroengros Kitchen", "Stasiun Hall-Dago", "Stasiun Hall", "Stasiun Bandung"}, {"66"}, {"6000"}}, {{"27"}, {"2"}, {"Damri dan Angkot"}, {"Leuwipanjang-Cibiru", "Leuwipanjang", "Alun-Alun Bandung", "Abdul Muis-Elang", "Elang", "Stasiun Timur"}, {"75"}, {"3000"}}, {{"28"}, {"2"}, {"Angkot dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Terminal Cicaheum", "Cicaheum-Ciroyom", "Ciroyom", "Geologi"}, {"52"}, {"4000"}}, {{"29"}, {"2"}, {"Angkot dan Angkot"}, {"Cicaheum-Cileunyi", "Cicaheum", "Terminal Cicaheum", "Cicaheum-Ledeng", "Ledeng", "Lapangan Gasibu B"}, {"57"}, {"4000"}}, {{"30"}, {"2"}, {"Angkot dan Angkot"}, {"Bumi Panyileukan-Sekemirung", "Bumi Panyileukan", "Holland Bakerry Ujung Berung", "Cicaheum-Cileunyi", "Cileunyi", "Waroeng Nenek Cipadung"}, {"70"}, {"4000"}}, {{"31"}, {"2"}, {"Angkot dan Damri"}, {"Cicaheum-Ciroyom", "Cicaheum", "Roti Bakar Cicaheum", "Leuwipanjang-Cibiru", "Cibiru", "Halte SDN Cipadung"}, {"100"}, {"5000"}}, {{"32"}, {"1"}, {"Angkot"}, {"Cicaheum-Ledeng", "Ledeng", "Museum UPI Setiabudi"}, {"36"}, {"2000"}}, {{"33"}, {"1"}, {"Angkot"}, {"Abdul Muis-Ledeng", "Ledeng", "Gerbang Utama UPI Setiabudi"}, {"36"}, {"2000"}}, {{"34"}, {"1"}, {"Angkot"}, {"Stasiun Hall-Sadang Serang", "Stasiun Hall", "Stasiun Bandung"}, {"23"}, {"2000"}}, {{"35"}, {"2"}, {"Angkot dan Angkot"}, {"Abdul Muis-Ledeng", "Abdul Muis", "Hotel Merdeka Angela", "Gede Bage-Stasiun Hall", "Stasiun Hall", "Stasiun Bandung"}, {"23"}, {"4000"}}, {{"36"}, {"1"}, {"Angkot"}, {"Bumi Panyileukan-Sekemirung", "Bumi Panyileukan", "SMAN 24 Bandung"}, {"34"}, {"2000"}}}; // vector 3 dimensi
// Deskripsi rute, tambah data sebelum '}' terakhir, formatnya {{"nomor rute, mulai lagi dari 3"}, {"Jumlah kendaraan, berapa kali ganti, misal 2 angkor dan 1 bis, jadi tulis 3"}, {"Apa aja dari jumlah kendaraan, misal 2 angkot 1 bis, tulus => angkot, angkot, dan bis"}, {Jurusannya, urutan 0,3,6 dst adalah nama trayeknya, urutan 1,4,7,dst adalah trayek tsb dengan tujuan ke-, 2,5,8,dst adalah tempat berhenti atau turun, perhatikan contoh"}, {"Durasi dalam menit"}, {"tarif"}}. semua pake string.
// ENDSEGMEN B

// SEGMEN C:
//  Deklarasi Variabel
int awal, akhir, pilihan, pilihan_panduan, pilihan_tiket_saya, pilihan_opsi_rute, kode_rute_terpilih, pindai_total, pindai_sementara, pemindaian;
string nama_pelanggan, rute, pesan, kode_perjalanan, tanggal_sekarang, konfirmasi;
bool punya_tiket;
// ENDSEGMEN C

// Array
string lokasi[] = {"Cibiru", "Setiabudi", "Stasiun bandung", "Ujung Berung", "Gedung Sate"}; // Array List Lokasi, kalo mau ditambah lagi juga boleh

// SEGMEN D:
//  Prototipe Fungsi, void gaperlu return . return = hasil dikeluarkan
void tampilMenuUtama();
void mulaiPerjalanan();
void tiketSaya();
void panduanInformasiPerjalanan();
void riwayatperjalanan();
void pelaporanKeamanan();
void tentangBetra();
void resetWarnaKonsol();
void aturWarnaKonsol(int depan, int belakang);
// ENDSEGMEN D

enum ConsoleColor
{ // Mendefinisikan daftar warna konsol dengan memberikan nama pada setiap warna
    HITAM = 0,
    BIRU = 1,
    HIJAU = 2,
    CYAN = 3,
    MERAH = 4,
    MAGENTA = 5,
    KUNING = 6,
    PUTIH = 7,
    ABU_ABU = 8,
    BIRU_MUDA = 9,
    HIJAU_MUDA = 10,
    CYAN_MUDA = 11,
    MERAH_MUDA = 12,
    MAGENTA_MUDA = 13,
    KUNING_MUDA = 14,
    PUTIH_TERANG = 15
};
// goto adalah lebel

int main()
{
    // SEGMEN E:
    //  Inisiasi Variabel
    punya_tiket = false, pemindaian, pilihan_tiket_saya, pilihan_opsi_rute, pilihan = 0, pilihan_panduan = 0;
    // ENDSEGMEN E

    // SEGMEN F:
    do
    {

    menu_utama:
        system("cls");
        tampilMenuUtama(); // Memanggil fungsi
        cout << endl;

        // SEGMEN Z: Rincian di dokumentasi
        while (true) // pengecekan validasi tipe data input, akan digunakan di berbagai tempat
        {
            aturWarnaKonsol(MAGENTA, HITAM);
            cout << "Silahkan pilih menu mana yang ingin anda gunakan: ";
            resetWarnaKonsol();
            if (cin >> pilihan) // jika ketika melakukan input sesuai atau diterima tipe datanya dan tidak ada error, maka menghasilkan boolean true.
            {
                break;
            }
            else
            {
                aturWarnaKonsol(MERAH, HITAM);
                cout << "Input tidak valid" << endl << endl;
                resetWarnaKonsol();
                cin.clear();
                cin.ignore();
            }
        }
        // ENDSEGMEN Z
        cin.ignore();

        if (pilihan == 1)
        {
            system("cls");
            mulaiPerjalanan();
            getch();
            system("cls");
        }
        else if (pilihan == 2)
        {
            system("cls");
            tiketSaya();
            cout << "\nTekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls");
        }
        else if (pilihan == 3)
        {
            system("cls");
            panduanInformasiPerjalanan();
            system("cls");
        }
        else if (pilihan == 4)
        {
            system("cls");
            riwayatperjalanan();
            cout << endl
                 << "\nTekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls");
        }
        else if (pilihan == 5)
        {
            system("cls");
            pelaporanKeamanan();
            cout << "\nTekan Apapun untuk melanjutkan" << endl;
            getch();
            system("cls");
        }
        else if (pilihan == 6)
        {
            system("cls");
            tentangBetra();
            cout << "\ntekan apapun untuk melanjutkan\n";
            getch();
            system("cls");
        }
        else if (pilihan == 7)
        {
            system("cls");
            aturWarnaKonsol(BIRU, HITAM);
            cout << "\n\n\n\n\t\t\t\t\t\t\t<3 ";
            aturWarnaKonsol(MERAH, HITAM);
            cout << "Terimakasih telah menggunakan aplikasi betra ";
            aturWarnaKonsol(BIRU, HITAM);
            cout << " <3 " << endl;
            resetWarnaKonsol();
        }
        else
        {
            system("cls");
            cout << "Pilihan tidak valid, silakan ulangi" << endl;
        }

    } while (pilihan != 7);
    // ENDSEGMEN F
    cin.get();
    return 0;
}

// SEGMEN G
//  Penjabaran Fungsi
void tampilMenuUtama()
{
    aturWarnaKonsol(MAGENTA_MUDA, HITAM);
    cout << "================================\n";
    aturWarnaKonsol(HITAM, BIRU_MUDA);
    cout << "SELAMAT DATANG DI APLIKASI BETRA\n";
    aturWarnaKonsol(MAGENTA_MUDA, HITAM);
    cout << "================================\n";
    aturWarnaKonsol(CYAN_MUDA, HITAM);
    cout << "MENU UTAMA\n";
    resetWarnaKonsol();
    cout << endl;
    cout << "1. Mulai perjalanan\n";
    cout << "2. Tiket Saya\n";
    cout << "3. Panduan dan Informasi Perjalanan\n";
    cout << "4. Riwayat Perjalanan\n";
    cout << "5. Laporan Keamanan\n";
    cout << "6. Tentang Betra\n";
    cout << "7. Keluar\n\n";
}

void mulaiPerjalanan()
{
    // SEGMEN H
    if (punya_tiket) // if (punya tiket == true)
                     // if (!punya tiket == false) hanya untuk tipe data bool
    {
        cout << "Anda sudah memiliki tiket, batalkan tiket untuk memesan tiket baru" << endl;
        getch();
        system("cls");
    }
    else
    {
        // SEGMEN I
        rute_terpilih.clear();
        deskripsi_rute_terpilih.clear();
        opsi_rute_terpilih.clear();
        // ENDSEGMEN I
    memilih_lokasi:
        system("cls");
        // SEGMEN J
        aturWarnaKonsol(BIRU, HITAM);
        cout << "=== Daftar Lokasi Tersedia ===" << endl;
        resetWarnaKonsol();
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". " << lokasi[i] << endl;
        }
        cout << endl;
        // ENDSEGMEN J

        // SEGMEN K
        aturWarnaKonsol(KUNING, HITAM);
        cout << "=== Mulai Perjalanan ===" << endl;
        resetWarnaKonsol();
        while (true) // pengecekan validasi tipe data input
        {
            cout << "Pilih Lokasi Awal: ";
            if (cin >> awal)
            {
                break;
            }
            else
            {
                aturWarnaKonsol(MERAH, HITAM);
                cout << "Input tidak valid" << endl
                     << endl;
                resetWarnaKonsol();
                cin.clear();
                cin.ignore();
            }
        }
        while (true) // pengecekan validasi tipe data input
        {
            cout << "Pilih Lokasi Tujuan: ";
            if (cin >> akhir)
            {
                break;
            }
            else
            {
                aturWarnaKonsol(MERAH, HITAM);
                cout << "Input tidak valid" << endl
                     << endl;
                resetWarnaKonsol();
                cin.clear();
                cin.ignore();
            }
        }
        if (awal == akhir || awal > 5 || awal < 1 || akhir > 5 || akhir < 1)
        {
            system("cls");
            cout << "Tidak Valid, Ulangi!" << endl;
            getch();
            goto memilih_lokasi;
        }
        cout << "Yakin? (y/n): ";
        cin >> konfirmasi;
        if (konfirmasi == "n" || konfirmasi == "N")
        {
            goto memilih_lokasi;
        }
        else if (konfirmasi == "y" || konfirmasi == "Y")
        {
        }
        else
        {
            system("cls");
            cout << "Tidak Valid, Ulangi!" << endl;
            getch();
            goto memilih_lokasi;
        }
        // ENDSEGMEN K

        // SEGMEN L: Secara rinci di dokumentasi
        rute = to_string(awal) + '-' + to_string(akhir);

        // Mencari rute di data dan memindahkannya ke vektor yang baru
        for (int i = 0; i < semua_rute.size(); i++)
        { // i = kesamaan rute dipilindan data rute yg dimiliki
            if (semua_rute[i][0] == rute)
            {
                for (int j = 0; j < semua_rute[i].size(); j++)
                { // untuk midahin rute yang terpilih ke vektor yang baru
                    rute_terpilih.push_back(semua_rute[i][j]);
                }
            }
        }
        // ENDSEGMEN L
    memilih_opsi:
        system("cls");

        // SEGMEN M: Secara rinci ada di dokumentasi
        cout << "Berikut informasi untuk  perjalanan dengan rute " << lokasi[awal - 1] << '-' << lokasi[akhir - 1] << endl; // -1 agar kembali di awal , karna aray dimulai dari 0
        cout << "Terdapat " << (rute_terpilih.size() - 1) << " opsi rute: " << endl;

        // untuk memunculkan semua opsi
        for (int i = 0; i < rute_terpilih.size() - 1; i++)
        {
            deskripsi_rute_terpilih = deskripsi_rute[stoi(rute_terpilih[i + 1]) - 1]; // stoi = string to integer
            aturWarnaKonsol(MERAH, HITAM);
            cout << "=====================================================================================" << endl;
            aturWarnaKonsol(HITAM, HIJAU);
            cout << "\t\t\t\t\tOpsi Ke-" << i + 1 << endl;
            aturWarnaKonsol(MERAH, HITAM);
            cout << "=====================================================================================" << endl;
            aturWarnaKonsol(MAGENTA, HITAM);
            cout << "Perjalanan dengan kode R" << deskripsi_rute_terpilih[0][0] << endl;
            resetWarnaKonsol();
            cout << "Akan menggunakan " << deskripsi_rute_terpilih[1][0] << " kendaraan berbeda dengan jenis moda yaitu " << deskripsi_rute_terpilih[2][0] << ". Berikut rinciannya: " << endl;
            for (int k = 0; k < stoi(deskripsi_rute_terpilih[1][0]); k++)
            {
                cout << "\t" << k + 1 << ". Jurusan " << deskripsi_rute_terpilih[3][k * 3] << " tujuan " << deskripsi_rute_terpilih[3][k * 3 + 1] << " berhenti di " << deskripsi_rute_terpilih[3][k * 3 + 2] << endl;
            }
            cout << "Waktu Perjalanan: " << stoi(deskripsi_rute_terpilih[4][0]) / 60 << " Jam " << stoi(deskripsi_rute_terpilih[4][0]) % 60 << " Menit" << endl;
            aturWarnaKonsol(BIRU_MUDA, HITAM);
            cout << "Tarif: Rp" << deskripsi_rute_terpilih[5][0] << endl;
            resetWarnaKonsol();
            cout << endl;
        }

        while (true) // pengecekan validasi tipe data input
        {
            cout << "Pilih Opsi Rute: ";
            if (cin >> pilihan_opsi_rute)
            {
                break;
            }
            else
            {
                aturWarnaKonsol(MERAH, HITAM);
                cout << "Input tidak valid" << endl
                     << endl;
                resetWarnaKonsol();
                cin.clear();
                cin.ignore();
            }
        }
        if (pilihan_opsi_rute < 1 || pilihan_opsi_rute > rute_terpilih.size() - 1)
        {
            system("cls");
            aturWarnaKonsol(MERAH, HITAM);
            cout << "Input tidak valid" << endl
                 << endl;
            resetWarnaKonsol();
            getch();
            goto memilih_opsi;
        }
        cout << "Yakin? (y/n): ";
        cin >> konfirmasi;
        if (konfirmasi == "n" || konfirmasi == "N")
        {
            goto memilih_opsi;
        }
        else if (konfirmasi == "y" || konfirmasi == "Y")
        {
            system("cls");
            opsi_rute_terpilih = deskripsi_rute[stoi(rute_terpilih[pilihan_opsi_rute]) - 1];
        // ENDSEGMEN M
        konfirmasi_pembayaran:
            // SEGMEN N
            aturWarnaKonsol(MAGENTA_MUDA, HITAM);
            cout << "Anda memilih perjalanan dengan kode R" << opsi_rute_terpilih[0][0] << " dengan tarif Rp" << opsi_rute_terpilih[5][0] << endl;
            resetWarnaKonsol();
            cout << endl;
            cout << "Lakukan Pembayaran" << endl;
            cout << "Konfirmasi Pembayaran (y/n): ";
            cin >> konfirmasi;
            if (konfirmasi == "n" || konfirmasi == "N")
            {
                system("cls");
                cout << "Kembali ke menu utama" << endl;
            }
            else if (konfirmasi == "y" || konfirmasi == "Y")
            {
                system("cls");
                aturWarnaKonsol(HIJAU, HITAM);
                cout << "Pembayaran Berhasil!" << endl;
                resetWarnaKonsol();
                punya_tiket = true;
                pindai_total = stoi(opsi_rute_terpilih[1][0]) * 2;
                pindai_sementara = 0;
                data_riwayat.clear();

                // dapatkan waktu
                time_t my_time = time(NULL); // waktu sekarang
                tanggal_sekarang = ctime(&my_time);
                //{"cibiru", "ujung berung", "4500", "aktif", "tanggal"}
                data_riwayat.push_back(lokasi[awal - 1]);
                data_riwayat.push_back(lokasi[akhir - 1]);
                data_riwayat.push_back("Rp" + opsi_rute_terpilih[5][0]); // Harga tiket
                data_riwayat.push_back("Aktif");
                data_riwayat.push_back(tanggal_sekarang);
                riwayat_perjalanan.push_back(data_riwayat);
            }
            else
            {
                cout << "Pilihan tidak valid" << endl;
                getch();
                goto konfirmasi_pembayaran;
            }
            // ENDSEGMEN N
        }
        else
        {
            system("cls");
            cout << "Tidak Valid, Ulangi!" << endl;
            getch();
            goto memilih_opsi;
        }
    }
    // ENDSEGMEN F
}

void tiketSaya()
{

tiket_saya:
    system("cls");
    // SEGMEN O
    if (punya_tiket)
    {
        // SEGMEN P
        do
        {
            system("cls");
            aturWarnaKonsol(HITAM, HIJAU_MUDA);
            cout << "Tiket Saya: " << endl;
            aturWarnaKonsol(KUNING, HITAM);
            cout << "Kode perjalanan R" << rute_terpilih[pilihan_opsi_rute] << " dengan rute " << lokasi[awal - 1] << '-' << lokasi[akhir - 1] << endl;
            cout << endl;
            resetWarnaKonsol();
            cout << "1. Lihat detail tiket" << endl;
            cout << "2. Pindai Tiket" << endl;
            cout << "3. Batalkan tiket" << endl;
            cout << "4. Kembali\n"
                 << endl;
            ;

            while (true) // pengecekan validasi tipe data input
            {
                cout << "Pilihan anda: ";
                if (cin >> pilihan_tiket_saya)
                {
                    break;
                }
                else
                {
                    aturWarnaKonsol(MERAH, HITAM);
                    cout << "Input tidak valid" << endl
                         << endl;
                    resetWarnaKonsol();
                    cin.clear();
                    cin.ignore();
                }
            }
            if (pilihan_tiket_saya == 1)
            {
                // SEGMEN Q
                system("cls");
                aturWarnaKonsol(MERAH, HITAM);
                cout << "=====================================================================================" << endl;
                aturWarnaKonsol(HITAM, HIJAU);
                cout << "\t\t\t\tDetail tiket anda" << endl;
                aturWarnaKonsol(MERAH, HITAM);
                cout << "=====================================================================================" << endl;
                aturWarnaKonsol(MAGENTA, HITAM);
                cout << "Perjalanan dengan kode R" << opsi_rute_terpilih[0][0] << endl;
                resetWarnaKonsol();
                cout << "Akan menggunakan " << opsi_rute_terpilih[1][0] << " kendaraan berbeda dengan jenis moda yaitu " << opsi_rute_terpilih[2][0] << ". Berikut rinciannya: " << endl;
                for (int k = 0; k < stoi(opsi_rute_terpilih[1][0]); k++)
                {
                    cout << "\t" << k + 1 << ". Jurusan " << opsi_rute_terpilih[3][k * 3] << " tujuan " << opsi_rute_terpilih[3][k * 3 + 1] << " berhenti di " << opsi_rute_terpilih[3][k * 3 + 2] << endl;
                }
                cout << "Waktu Perjalanan: " << stoi(opsi_rute_terpilih[4][0]) / 60 << " Jam " << stoi(opsi_rute_terpilih[4][0]) % 60 << " Menit" << endl;
                aturWarnaKonsol(BIRU, HITAM);
                cout << "Tarif: Rp" << opsi_rute_terpilih[5][0] << endl;
                aturWarnaKonsol(CYAN, HITAM);
                cout << "Dipesan pada " << data_riwayat[4] << endl;
                resetWarnaKonsol();
                cout << endl;
                cout << "Tekan apapun untuk kembali" << endl;
                getch();
                // ENDSEGMEN Q
            }
            else if (pilihan_tiket_saya == 2)
            {
            // SEGMEN R: Secara rinci ada di dokumentasi
            pemindaian:
                system("cls");
                aturWarnaKonsol(MAGENTA_MUDA, HITAM);
                cout << "Pindai Tiket" << endl;
                resetWarnaKonsol();
                cout << "Lakukan " << pindai_total << "x pemindaian ketika memasuki kendaraan" << endl;
                cout << pindai_total / 2 << "x ketika akan memasuki dan " << pindai_total / 2 << "x ketika akan keluar" << endl;
                cout << endl;
                cout << "Pemindaian ke-" << pindai_sementara + 1 << " : ";
                if (pindai_sementara % 2 == 0)
                {
                    aturWarnaKonsol(HITAM, HIJAU);
                    cout << " Check In Kendaraan " << endl;
                }
                else
                {
                    aturWarnaKonsol(HITAM, MERAH);
                    cout << " Check Out Kendaraan " << endl;
                }
                resetWarnaKonsol();
                cout << "1. Pindai sekarang." << endl;
                cout << "2. Kembali" << endl;

                while (true) // pengecekan validasi tipe data input
                {
                    cout << "Pilih: ";
                    if (cin >> pemindaian)
                    {
                        break;
                    }
                    else
                    {
                        aturWarnaKonsol(MERAH, HITAM);
                        cout << "Input tidak valid" << endl
                             << endl;
                        resetWarnaKonsol();
                        cin.clear();
                        cin.ignore();
                    }
                }
                if (pemindaian == 1)
                {
                    // SEGMEN S:
                    system("cls");
                    aturWarnaKonsol(HITAM, KUNING);
                    cout << "Memindai Tiket" << endl;
                    resetWarnaKonsol();
                    Sleep(2000);
                    if (pindai_sementara % 2 == 0)
                    {
                        aturWarnaKonsol(HIJAU, HITAM);
                        cout << "Anda berhasil melakukan Check-In pada kendaraan" << endl;
                    }
                    else
                    {
                        aturWarnaKonsol(MERAH, HITAM);
                        cout << "Anda berhasil melakukan Check-Out pada kendaraan" << endl;
                    }

                    pindai_sementara++;
                    resetWarnaKonsol();

                    // SEGMEN T: Secara rinci ada di dokumentasi
                    if (pindai_sementara == pindai_total)
                    {
                        punya_tiket = false;

                        // update riwayat
                        riwayat_perjalanan.pop_back();
                        data_riwayat[3] = "Selesai";
                        riwayat_perjalanan.push_back(data_riwayat);
                        getch();
                        system("cls");
                        aturWarnaKonsol(HIJAU, HITAM);
                        cout << "Anda sudah mencapai destinasi" << endl;
                        resetWarnaKonsol();
                        cout << "Terima kasih telah mempercayakan perjalanan Anda kepada kami" << endl;
                        getch();
                        goto tiket_saya;
                    }
                    // ENDSEGMEN T
                    getch();
                    goto pemindaian;
                    // ENDSEGMEN S
                }
                else if (pemindaian == 2)
                {
                    system("cls");
                }
                else
                {
                    cout << "Ulangi!" << endl;
                    goto pemindaian;
                }
                // ENDSEGMEN R
            }
            else if (pilihan_tiket_saya == 3)
            {
            // SEGMEN U
            konfirmasi_pembatalan:
                system("cls");
                cout << "Tiket Saya: \n"
                     << endl;
                aturWarnaKonsol(KUNING, HITAM);
                cout << "Kode perjalanan R" << rute_terpilih[pilihan_opsi_rute] << " dengan rute " << lokasi[awal - 1] << '-' << lokasi[akhir - 1] << endl;
                cout << endl;
                resetWarnaKonsol();
                cout << "Tiket akan dibatalkan, pengembalian uang pembayaran akan dilakukan sesuai ketentuan" << endl;
                cout << "Yakin? (y/n): ";
                cin >> konfirmasi;
                if (konfirmasi == "Y" || konfirmasi == "y")
                {
                    // SEGMEN V: Secara rinci ada di dokumentasi
                    //  Proses pembatalan tiket
                    punya_tiket = false;
                    riwayat_perjalanan.pop_back();
                    aturWarnaKonsol(HITAM, MERAH);
                    data_riwayat[3] = "Dibatalkan"; // mengubah status tiket dari aktif menjadi batal
                    resetWarnaKonsol();
                    riwayat_perjalanan.push_back(data_riwayat);
                    aturWarnaKonsol(HITAM, MERAH);
                    cout << "\nTiket dibatalkan" << endl;
                    resetWarnaKonsol();
                    cout << endl;
                    cout << "Tekan apapun untuk kembali ke menu" << endl;
                    getch();
                    goto tiket_saya;
                    // ENDSEGMEN V
                }
                else if (konfirmasi == "N" || konfirmasi == "n")
                {
                    cout << "Tekan apapun untuk kembali" << endl;
                    getch();
                }
                else
                {
                    cout << "Tidak Valid" << endl;
                    goto konfirmasi_pembatalan;
                }
            }
            // ENDSEGMEN U
            else if (pilihan_tiket_saya == 4)
            {
                system("cls");
            }
            else
            {
                cout << "Pilihan tidak valid" << endl;
            }
        } while (pilihan_tiket_saya != 4);
        // ENDSEGMEN P
    }
    else
    {
        aturWarnaKonsol(MERAH, HITAM);
        cout << "Anda tidak memiliki tiket" << endl;
        resetWarnaKonsol();
    }
    // ENDSEGMEN O
}

void panduanInformasiPerjalanan()
{
label_panduan:
    aturWarnaKonsol(HITAM, KUNING);
    cout << "Panduan dan Informasi Perjalanan\n"
         << endl;
    resetWarnaKonsol();
    cout << "1. Panduan\n";
    cout << "2. Informasi Perjalanan\n";
    cout << "3. Keluar\n\n";

    while (true) // pengecekan validasi tipe data input
    {
        cout << "pilihan anda: ";
        if (cin >> pilihan_panduan)
        {
            break;
        }
        else
        {
            aturWarnaKonsol(MERAH, HITAM);
            cout << "Input tidak valid" << endl
                 << endl;
            resetWarnaKonsol();
            cin.clear();
            cin.ignore();
        }
    }
    if (pilihan_panduan == 1)
    {
        system("cls");
        aturWarnaKonsol(HITAM, CYAN);
        cout << "PANDUAN PEMAKAIAN APLIKASI BETRA\n\n";
        resetWarnaKonsol();
        cout << "1. Sambungkan ke koneksi internet\n";
        cout << "2. buka aplikasi betra\n";
        cout << "3. jika anda ingin memulai pejalanan pilih menu no 1\n";
        cout << "4. jika anda ingin melihat tiket anda pilih menu no 2\n";
        cout << "5. jika anda ingin butuh panduan dan informasi pilih menu no 3\n";
        cout << "6. jika anda ingin melihat riwayat perjalanan anda ada di menu no 4\n";
        cout << "7. jika ada kendala atau masalah laporkan di menu no 5\n";
        cout << "8. jika anda ingin membayar di menu no 6\n";
        cout << "9. ada beberapa informasi di aplikasi betra di menu no 7\n";
        cout << endl
             << "Tekan apapun untuk kembali" << endl;
        getch();
        system("cls");
        goto label_panduan;
    }
    else if (pilihan_panduan == 2)
    {
        // SEGMEN W: Secara rinci ada di dokumentasi
        system("cls");
        aturWarnaKonsol(HITAM, CYAN_MUDA);
        cout << "informasi perjalanan\n\n";
        aturWarnaKonsol(MERAH, HITAM);
        cout << "============================================================================" << endl;
        aturWarnaKonsol(HITAM, HIJAU);
        cout << "No.\t\tRelasi\t\t\tOpsi Rute\tKode Perjalanan" << endl;
        aturWarnaKonsol(MERAH, HITAM);
        cout << "============================================================================" << endl;
        resetWarnaKonsol();
        // nampilin data rutenya
        for (int i = 0; i < semua_rute.size(); i++)
        {
            cout << i + 1 << ".\t";
            cout << lokasi[int(semua_rute[i][0][0]) - 48 - 1] << "-" << lokasi[int(semua_rute[i][0][2]) - 48 - 1] << "\t\t";

            cout << semua_rute[i].size() - 1 << " Opsi\t\t";
            for (int j = 1; j < semua_rute[i].size(); j++)
            {
                cout << "R" << semua_rute[i][j] << ", ";
            }
            cout << endl;
        }
        aturWarnaKonsol(MERAH, HITAM);
        cout << "============================================================================" << endl;
        resetWarnaKonsol();
        // ENDSEGMEN W
        getch();
        system("cls");
        goto label_panduan;
    }
    else if (pilihan_panduan == 3)
    {
        system("cls");
    }
    else
    {
        system("cls");
        cout << "kode yang anda inputkan tidak ada silahkan ulangi";
        goto label_panduan;
    }
}

void riwayatperjalanan()
{
    // SEGMEN X
    aturWarnaKonsol(HITAM, BIRU_MUDA);
    cout << "Riwayat perjalanan anda \n"
         << endl;
    // Menampilkan header tabel
    aturWarnaKonsol(MERAH, HITAM);
    cout << "==========================================================================================================" << endl;
    aturWarnaKonsol(HITAM, HIJAU);
    cout << "No.  |   Lokasi Awal   |  Lokasi Tujuan    |    Harga Tiket   |    Status     |       Tanggal Pembelian   " << endl;
    aturWarnaKonsol(MERAH, HITAM);
    cout << "==========================================================================================================" << endl;
    resetWarnaKonsol();
    // Menampilkan data riwayat perjalanan dengan melakukan looping pada setiap dimensi array riwayat_perjalanan
    for (int i = 0; i < riwayat_perjalanan.size(); i++) // looping dimensi satu berisi data tiap perjalanan
    {
        cout << i + 1 << "\t";
        for (int j = 0; j < riwayat_perjalanan[i].size(); j++) // looping dimensi dua berisi data detail dari tiap perjalanan
        {
            cout << riwayat_perjalanan[i][j] << "\t\t";
        }
        cout << endl;
    }
    aturWarnaKonsol(MERAH, HITAM);
    cout << endl
         << "==========================================================================================================" << endl;
    resetWarnaKonsol();
    // ENDSEGMEN X
}

void pelaporanKeamanan()
{
    aturWarnaKonsol(HITAM, MAGENTA);
    cout << "Pelaporan Keamanan\n"
         << endl;
    resetWarnaKonsol();
    cout << "Nama Anda: ";
    getline(cin, nama_pelanggan);
    cout << "Kode perjalanan: ";
    getline(cin, kode_perjalanan);
    cout << "Tulis Laporan Anda: ";
    getline(cin, pesan);
    aturWarnaKonsol(CYAN, HITAM);
    cout << "Laporan anda akan segera kami proses, Mohon maaf atas ketidaknyamanan nya\nHormat kami Bandung Ekayatra :)" << endl;
    resetWarnaKonsol();
}

void tentangBetra()
{
    aturWarnaKonsol(HITAM, MERAH);
    cout << "Tentang Betra\n"
         << endl;
    resetWarnaKonsol();
    cout << "Betra adalah sebuah nama yang disingkat dari nama kota bandung dan bahasa sunda dan sansakerta.\nyaitu eka berarti satu, yatra berarti perjalanan. \n";
    cout << "Betra menyajikan pengalaman perjalanan yang menyeluruh.\nDengan fitur rute, manajemen, dan pembayaran yang terpadu,\n\n";
    cout << "\nBetra memastikan setiap perjalanan menjadi lebih efisien dan tak terlupakan.\n";
    cout << "Betra dibuat untuk mengintegrasikan semua angkutan umum menjadi satu dalam sebuah aplikasi\n";
    cout << "mempermudah masyarakat untuk berpergian, dan mengurangi kemacetan karena berhenti sembarangan\n";
    aturWarnaKonsol(KUNING, HITAM);
    cout << "program ini dibuat oleh Darrel, Rifqi, Chandra" << endl;
    resetWarnaKonsol();
}

// SEGMEN Y: Secara rinci ada di dokumentasi
// Mengatur warna pada konsol
void aturWarnaKonsol(int depan, int belakang)
{
#ifdef _WIN32
    int warna = depan + (belakang << 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), warna);
#endif
}

void resetWarnaKonsol()
{
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Kembalikan ke warna default
#endif
}
// ENDSEGMEN Y
// ENDSEGMEN G
