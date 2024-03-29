// Part 1. (step 1)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Devinisi Variable
#define MAXITEM 5

// (step 2) membuat struct barang
struct barang {
    char nama[30];
    int  harga;
    int  jumlah;
};

// Start Membuat Tampilan Awal (step 3 START.)
void tampilanAwal (struct barang listBarang[]) {

    // Template tampilan awal
    printf ("==================================================\n");
    printf ("         Selamat Datang Di Toko Skensa            \n");
    printf ("   Silahkan Masukkan Barang Yang Anda Inginkan    \n");
    printf ("==================================================\n");
    printf ("|No.| Nama Barang    | Harga                     |\n");
    printf ("--------------------------------------------------\n");

    // Membuat Looping
    for (int i = 0; i < MAXITEM; i++) {
        printf ("|%-3d| %-15s| RP. %-22d|\n", i+1, listBarang[i].nama , listBarang[i].harga);
    }

    printf ("==================================================\n\n");
    printf ("1-5. Silahkan Masukkan Barang Yang Ingin di Beli\n");
    printf ("99.  Struk Pembayaran\n");
    printf ("55.  Reset Pilihan\n");
    printf ("00.  Keluar\n\n");
    printf ("==================================================\n");


} // (step 3. END)







// Part 2. (Step A)  Membuat Cetak Struk
void cetakStruk (struct barang listBarang[], int uangBayar) {

    // (step 1) Deklarasi variable Cetak Nota Barang
    int totalHarga, diskon = 0;
    int totalSemuaHarga = 0, totalSemuaDiskon = 0, totalBayar, kembalian;
    int j = 1;

    // (step 2) Deklarasi Time (langkah awal, ambil dari library dengan time_t t = time(NULL);
    time_t t = time(NULL);

    struct tm tanggal = *localtime(&t); // Mengambil struct dari library time & mengambil lokal time.

    // (step 3) Deklarasi File txt
    char filename [100];
    char id [30];

    strftime(filename, sizeof(filename), "struk_%Y%m%d_%H%M%S.txt", &tanggal); // Membuat time menjadi String agar dapat digunakan.
    strftime(id, sizeof(id), "%Y%m%d%H%M%S", &tanggal);

    FILE *f = fopen(filename,"w");

    // (Step 4) Membuat / mencetak isian dalam struk yang akan menjadi txt.
    fprintf (f,"==================================================================================\n");
    fprintf (f,"|                                  Toko Skensa                                   |\n");
    fprintf (f,"|                      Jl. HOS Cokroaminoto No.84, Denpasar                      |\n");
    fprintf (f,"|                                      Bali                                      |\n");
    fprintf (f,"|                                Telp : 0816285791                               |\n");
    fprintf (f,"|ID Struk : %s                                                       |\n",id);
    fprintf (f,"|Tanggal  : %d-%02d-%d %02d:%02d:%02d|                                                 \n", tanggal.tm_mday, tanggal.tm_mon + 1, tanggal.tm_year + 1900, tanggal.tm_hour, tanggal.tm_min, tanggal.tm_sec);
    fprintf (f,"|================================================================================|\n");
    fprintf (f,"| No. |Nama Barang     | Jumlah | * | Harga     | = | Total         | Diskon     |\n");
    fprintf (f,"|=====|================|========|===|===========|===|===============|============|\n");

    // (Step 5) Membuat perulangan untuk barang dan penambahan total keseluruhan
    for (int i = 0; i < MAXITEM; i++) {

        if (listBarang[i].jumlah == 0){
            continue;
        }
        else {
            // Menghitung total harga per item.
            totalHarga = listBarang[i].jumlah * listBarang[i].harga;

            // Menghitung Diskon.
            if (listBarang[i].jumlah >= 5) {
                diskon = totalHarga * 0.15;
            }
            else if (listBarang[i].jumlah <= 3) {
                diskon = totalHarga * 0.1;
            }
            else {
                diskon = 0;
            }

            fprintf(f,"|  %d  |%-16s|    %-3d | * | Rp. %-6d| = | Rp. %-10d| Rp. %-7d|\n", j, listBarang[i].nama, listBarang[i].jumlah, listBarang[i].harga, totalHarga, diskon);

            // Menambahkan nomor jika pilihannya ada.
            j++;

            // Menghitung / menambahkan total harga dan diskon.
            totalSemuaHarga += totalHarga;
            totalSemuaDiskon += diskon;
        }
} // End Step A (Penutup Void)

    // (Step 6) Membuat Aritmatika kembalian dan total belanja
    totalBayar = totalSemuaHarga - totalSemuaDiskon;
    kembalian = uangBayar - totalBayar;

    // (Step 7) Membuat / mencetak isian footer (tagihan yang harus dibayar)
        fprintf(f,"|================================================================================|\n");
        fprintf(f,"|                                                                                |\n");
        fprintf(f,"|Total Harga  = Rp. %-61d|\n", totalSemuaHarga);
        fprintf(f,"|Total Diskon = Rp. %-61d|\n", totalSemuaDiskon);
        fprintf(f,"|Tagihan      = Rp. %-61d|\n", totalBayar);
        fprintf(f,"|Pembayaran   = Rp. %-61d|\n", uangBayar);
        fprintf(f,"|Kembalian    = Rp. %-61d|\n", kembalian);
        fprintf(f,"|                                                                                |\n");
        fprintf(f,"==================================================================================\n");

    // (Step 8) Membuat Penutup File
    fclose(f);
    printf ("\nStruk telah dibuat dengan nama '%s'\n", filename);


}




// Part 3. (Step A) Membuat Rekapan Pesanan
void rekapPesanan (struct barang listBarang[]){

    // (Step 1) Deklarasi variable rekap pesanan
    int totalHarga, diskon = 0;
    int totalSemuaHarga = 0, totalSemuaDiskon = 0, totalBayar, kembalian;
    int uangBayar = 0;
    int j = 1;

    // (Step 2) Code tampilan Rekapan Pesanan
    printf ("Rekapan Pesanan Barang\n");
    printf ("=========================================================================\n");
    printf ("|No. | Jumlah |Nama Barang |Harga          |Total Harga     |Diskon     |\n");
    printf ("|====|========|============|===============|================|===========|\n");

    // (Step 3) Membuat looping untuk Array Barang
    for (int i = 0; i < MAXITEM; i++){

        if (listBarang[i].jumlah == 0) {
            continue;
        }

        else {

             // Menghitung total harga per item
            totalHarga = listBarang[i].jumlah * listBarang[i].harga;

            // Menghitung Diskon
            if (listBarang[i].jumlah >= 5) {
                diskon = totalHarga * 0.15;
            }
            else if (listBarang[i].jumlah <= 3) {
                diskon = totalHarga * 0.1;
            }
            else {
                diskon = 0;
            }

            printf("| %-2d | %-7d|%-12s|Rp. %-11d|Rp. %-12d|Rp. %-7d|\n", j, listBarang[i].jumlah, listBarang[i].nama, listBarang[i].harga, totalHarga, diskon);

            // Menambahkan jumlah nomor
            j++;

            // Menghitung / menambahkan total harga dan diskon
            totalSemuaHarga += totalHarga;
            totalSemuaDiskon += diskon;

        }
    } // End step 3 (Penutup void)

    // (Step 4) Membuat isian footer (Menghitung total yang harus di bayar oleh user)
    totalBayar = totalSemuaHarga - totalSemuaDiskon;
    printf ("=========================================================================\n\n");
    printf ("Total Harga  = Rp. %d.-\n", totalSemuaHarga);
    printf ("Total Diskon = Rp. %d.-\n", totalSemuaDiskon);
    printf ("Total Bayar  = Rp. %d.-\n\n", totalBayar);
    printf ("=========================================================================\n\n");

    // (Step 5) Membuat perulangan hingga user menyelesaikannya
    while (1) {

        printf ("Masukkan uang Bayar = Rp.");
        scanf ("%d", &uangBayar);

        kembalian = uangBayar - totalBayar;

        if (kembalian < 0) {
            printf ("Maaf uang anda tidak cukup!\n Silahkan bayar lagi!!\n\n");
            continue;
        }
        else {
            printf ("Kembalian : Rp %d.-\n\n", kembalian);
            printf ("=========================================================================\n");\
            printf ("\nTerimakasih Telah Berbelanja!\n");


            cetakStruk (listBarang, uangBayar);

            break;
        }
    }
}






// Part 4. Membuat Sorting Item / Mengurutkan barang
void sortingItem (struct barang listBarang[]) {

    struct barang temp;

    // Membuat looping Bubble Sort
    for (int i = 0; i < MAXITEM - 1; i++) {

        for (int j = 0; j < MAXITEM - i - 1; j++) {
            if (listBarang[j].jumlah < listBarang[j+1].jumlah) {
                temp = listBarang[j];
                listBarang[j] = listBarang[j+1];
                listBarang[j+1] = temp;
            }
        }

    }

}






// Part 5. Membuat int main
int main() {

    // (Step 1) Deklarasi Variable
    int pilihan = 0;
    int jumlahSemuaBarang;
    int jumlahBeli;
    int tampilkanAwal = 1;
    char konfirmasi;

    // (Step 2) Mengisi Array barang dengan listBarang
    struct barang listBarang[MAXITEM] = {
    {"Buku Tulis", 5000, 0},
    {"Pensil", 2000, 0},
    {"Penghapus", 1000, 0},
    {"Penggaris", 1000, 0},
    {"Bujur Sangkar", 500, 0}
    };

    // (Step 3) Membuat Looping pilihan hingga user selesai berbelanja
    while (1) {

        if (tampilkanAwal == 1) {
            tampilanAwal(listBarang);
            tampilkanAwal = 0;
        }
        printf ("\nInput Pilihan Yang Anda Inginkan! : ");
        scanf ("%d", &pilihan);            // Basic Bangettt!


        // (Step 4. Pengkondisisan) \\

        // 1 - 5. Pilihan Barang
        if (pilihan >=1 && pilihan <= 5) {
            printf ("Masukkan Jumlah Beli %s : ", listBarang[pilihan - 1].nama);
            scanf ("%d", &jumlahBeli);

            if (jumlahBeli <= 0 ) {
                printf ("Jumlah Beli barang tidak boleh kurang dari 0!");
                continue;
            }

            else {
                listBarang[pilihan - 1]. jumlah += jumlahBeli;
                continue;
            }
        }

        // 55. Reset Barang
        else if (pilihan == 55) {

            for (int i = 0; i < MAXITEM; i++) {
                listBarang[i].jumlah = 0;
            }
            printf ("\nPilihan Barang Telah Di Reset\n");
            printf ("Klik Enter Untuk Melanjutkan..");

            // Fungsi setelah tombol Enter di tekan
            while (getchar() != '\n');
            getchar (); // Fungsi untuk Menangkap Enter
            system ("cls"); // Fungsi untuk Membersihkan Layar
            tampilkanAwal = 1;
            continue;

        }

        // 99. Rekapan Pesanan
        else if (pilihan == 99) {

            // Pengecekan jumlah untuk kondisi
            for (int i = 0; i < MAXITEM; i++) {
                jumlahSemuaBarang += listBarang[i].jumlah;
            }

                if (jumlahSemuaBarang == 0) {
                    printf ("Anda Belum Memilih Apapun. Silahkan pilih Barang Terlebih Dahulu!!");
                    continue;
                }
                else {

                    system ("cls");
                    sortingItem (listBarang);
                    rekapPesanan (listBarang);

                    break;
                }
        }

        // 00. Keluar
        else if (pilihan == 00) {
            printf ("Terimakasih Telah Berbelanja!! \n");
            break;
        }
        else {
            printf ("Input Tidak Valid!");
        }

    }

