//Awal Code

//Start Include
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//End Include

//Define Variabel
#define MIN_ITEMS 1
#define MAX_ITEMS 5

//Start code struct barang
struct barang {
    char nama[20];
    int harga;
    int jumlah;
};
//End code struct barang

//Start Code Tampilan Awal
void tampilanAwal (struct barang isiBarang[]){
    //Code Tampilan Awal
    printf("Selamat Datang di Toko SKENSA\n");
    printf("Silahkan Pilih Barang yang anda inginkan (Masukkan pilihan dibawah!) \n");
    printf("=============================================\n");
    printf("|No.|Nama Barang     |Harga         |\n");

    //Looping array barang
    for (int i = 0; i < MAX_ITEMS; i++){
        printf("|%-3d|%-16s|Rp. %-10d|\n", i+1, isiBarang[i].nama, isiBarang[i].harga);
    }

    printf("=============================================\n\n");
    printf("1-5. Pilihan Barang\n");
    printf("99.  Struk Pembayaran\n");
    printf("55.  Reset Pilihan\n");
    printf("00.  Keluar\n");
    printf("=============================================\n");

}
//End Code Tampilan Awal

//Start code cetak struk
void cetakNota(struct barang isiBarang[], int uangBayar){
    //Deklarasi Cetak Nota barang
    int totalHarga, diskon = 0;
    int totalSemuaHarga = 0, totalSemuaDiskon = 0, totalBayar, kembalian;
    int j = 1;

    //Deklarasi Time
    //ambil dari library terlebih dahulu dengan time(NULL);
    time_t t = time(NULL);
    //Ambil struct tm dari library dan ganti menjadi tanggal
    //setelah itu ambil pointer *localtime(deklarasi dari time_t yaitu t)
    struct tm tanggal = *localtime(&t);

    //Deklarasi file txt
    char filename[100];
    char id[30];
//    strftime(filename, sizeof(filename), "%Y-%m-%d_%H-%M-%S.txt", &tanggal)
    strftime(filename, sizeof(filename), "Struk_%Y%m%d_%H%M%S.txt", &tanggal);
    strftime(id, sizeof(id), "%Y%m%d%H%M%S", &tanggal);

    //Open file dan pointer
    FILE *f = fopen(filename,"w");

    //Isi txt
    fprintf (f,"|================================================================================|\n");
    fprintf (f,"|                                   Toko Skensa                                  |\n");
    fprintf (f,"|                      Jl. HOS Cokroaminoto No.84, Denpasar                      |\n");
    fprintf (f,"|                                      Bali                                      |\n");
    fprintf (f,"|                                Telp : 0816285791                               |\n");
    fprintf (f,"|ID Struk : %s                                                       |\n",id);
    fprintf (f,"|Tanggal  : %d-%02d-%d %02d:%02d:%02d                                                  |\n", tanggal.tm_mday, tanggal.tm_mon + 1, tanggal.tm_year + 1900, tanggal.tm_hour, tanggal.tm_min, tanggal.tm_sec);
    fprintf (f,"|================================================================================|\n");
    fprintf (f,"| No. |Nama Barang     | Jumlah | * | Harga     | = | Total         | Diskon     |\n");
    fprintf (f,"|=====|================|========|===|===========|===|===============|============|\n");

    //Start Pengulangan untuk barang dan penambahan total
    for (int i = 0; i < MAX_ITEMS; i++){
        if (isiBarang[i].jumlah == 0){
            continue;
        }
        else{
            //Perhitungan Total Harga Per item
            totalHarga = isiBarang[i].jumlah * isiBarang[i].harga;
            //Perhitungan diskon
            if (isiBarang[i].jumlah >= 5){
                diskon = totalHarga * 0.15;
            }
            else if (isiBarang[i].jumlah >= 3){
                diskon = totalHarga * 0.1;
            }
            else{
                diskon = 0;
            }
            fprintf(f,"|  %d  |%-16s|    %-3d | * | Rp. %-6d| = | Rp. %-10d| Rp. %-7d|\n", j, isiBarang[i].nama, isiBarang[i].jumlah, isiBarang[i].harga, totalHarga, diskon);
            //Penambahan No.
            j++;
            //Penambahan totalharga dan diskon
            totalSemuaHarga += totalHarga;
            totalSemuaDiskon += diskon;
        }
    }
    //End Pengulangan untuk barang dan penambahan total
    //Aritmatika Kembalian dan totalbelanja
    totalBayar = totalSemuaHarga - totalSemuaDiskon;
    kembalian = uangBayar - totalBayar;

    fprintf(f,"|================================================================================|\n");
    fprintf(f,"|                                                                                |\n");
    fprintf(f,"|Total Harga  = Rp. %-61d|\n", totalSemuaHarga);
    fprintf(f,"|Total Diskon = Rp. %-61d|\n", totalSemuaDiskon);
    fprintf(f,"|Tagihan      = Rp. %-61d|\n", totalBayar);
    fprintf(f,"|Pembayaran   = Rp. %-61d|\n", uangBayar);
    fprintf(f,"|Kembalian    = Rp. %-61d|\n", kembalian);
    fprintf(f,"|                                                                                |\n");
    fprintf(f,"|================================================================================|\n");





    //Close file
    fclose(f);
    printf("\nStruk sudah disimpan dengan nama '%s'\n" , filename);

}
//End code cetak struk

//Start code rekapan Pesanan
void rekapPesanan(struct barang isiBarang[]){
    //Deklarasi Rekapan Pesanan
    int totalHarga, diskon = 0;
    int totalSemuaHarga = 0, totalSemuaDiskon = 0, totalBayar, kembalian;
    int uangBayar = 0;
    int j = 1;

    //Code Rekapan Pesanan
    printf("Rekapan Pesanan Barang\n");
    printf("=============================================================================\n");
    printf("| No. | Jumlah |Nama Barang     |Harga         |Total Harga     |Diskon     |\n");
    printf("|=====|========|================|==============|================|===========|\n");
    //Start Looping array Barang
    for (int i = 0; i < MAX_ITEMS; i++){
        if (isiBarang[i].jumlah == 0){
            continue;
        }
        else{
            //Perhitungan Total Harga Per item
            totalHarga = isiBarang[i].jumlah * isiBarang[i].harga;
            //Perhitungan diskon
            if (isiBarang[i].jumlah >= 5){
                diskon = totalHarga * 0.15;
            }
            else if (isiBarang[i].jumlah >= 3){
                diskon = totalHarga * 0.1;
            }
            else{
                diskon = 0;
            }
            printf("| %-3d | %-7d|%-16s|Rp. %-10d|Rp. %-12d|Rp. %-7d|\n", j, isiBarang[i].jumlah, isiBarang[i].nama, isiBarang[i].harga, totalHarga, diskon);
            //Penambahan No.
            j++;
            //Penambahan totalharga dan diskon
            totalSemuaHarga += totalHarga;
            totalSemuaDiskon += diskon;
        }
    }
    //End Looping array Barang
    //Penambahan Total Bayar
    totalBayar = totalSemuaHarga - totalSemuaDiskon;
    printf("=============================================================================\n\n");
    printf("Total Harga = Rp. %d.-\n", totalSemuaHarga);
    printf("Total Diskon = Rp. %d.-\n", totalSemuaDiskon);
    printf("Total Bayar = Rp. %d.-\n\n", totalBayar);
    printf("=============================================================================\n\n");
    while (1){
        printf("Masukkan uang bayar = Rp.");
        scanf("%d", &uangBayar);
        kembalian = uangBayar - totalBayar;
        if (kembalian < 0){
            printf("Maaf, uang yang anda masukkan tidak cukup!\nSilahkan coba lagi\n\n");
            continue;
        }
        else{
            printf("Kembalian : Rp.%d.-\n", kembalian);
            printf("=============================================================================\n\n");
            printf("\nTerimakasih sudah berbelanja!\n");
            cetakNota(isiBarang, uangBayar);
            break;
        }
    }
}
//End Code Rekapan Pesanan

//Start Code Sorting Item
void sortingItem(struct barang isiBarang[]){
    struct barang temp;
    //Looping Bubble Sort
    for (int i = 0; i < MAX_ITEMS - 1; i++){
        for (int j = 0; j < MAX_ITEMS - i - 1; j++){
            if (isiBarang[j].jumlah < isiBarang[j+1].jumlah){
                temp = isiBarang[j];
                isiBarang[j] = isiBarang[j+1];
                isiBarang[j+1] = temp;
            }
        }
    }
}
//End Code Sorting Item



//Start Code Main
int main(){
    // Deklarasi Variable
    int pilihan = 0;
    int jumlahSemuaBarang = 0;
    int jumlahBeli = 0;
    int tampilkanawal = 1;
    char konfirmasi;

    //Pengisian Array Barang dengan nama isiBarang
    struct barang isiBarang[MAX_ITEMS] = {
    {"Buku Tulis", 5000, 0},
    {"Pensil", 2000, 0},
    {"Penghapus", 1000, 0},
    {"Penggaris", 1000, 0},
    {"Bujur Sangkar", 500, 0}
    };

    //Start Looping Pilihan
    while (1){
        //Ambil code tampilan Awal
        if (tampilkanawal == 1){
            tampilanAwal(isiBarang);
            tampilkanawal = 0;
        }
        printf("\nInput pilihan yang Anda inginkan : ");
        scanf("%d", &pilihan);

        //Start Pengkondisian Pilihan
        //Pilihan Barang
        if (pilihan >=1 && pilihan <= 5){
            printf("Masukkan Jumlah beli %s : ", isiBarang[pilihan - 1].nama);
            scanf("%d", &jumlahBeli);
            if (jumlahBeli <= 0){
                printf("Jumlah Beli Barang Tidak boleh kurang dari 0!");
                continue;
            }
            else{
            }
                isiBarang[pilihan - 1].jumlah += jumlahBeli;
                continue;
            }
        //Pilihan Reset Pilihan
        else if (pilihan == 55){
            for (int i = 0; i < MAX_ITEMS; i++){
                isiBarang[i].jumlah = 0;
            }
            printf("\nPilihan Barang Telah Direset!\n");
            printf("Klik Enter untuk melanjutkan......");
            while (getchar() != '\n');
            getchar();//Untuk menangkap enter
            system("cls");//Membersihkan layar
            tampilkanawal = 1;
            continue;
        }
        //Pilihan Rekapan Pesanan
        else if (pilihan == 99){
            //Pengecekan Jumlah untuk kondisi
            for (int i = 0; i < MAX_ITEMS; i++){
                jumlahSemuaBarang += isiBarang[i].jumlah;
            }
            if (jumlahSemuaBarang == 0){
                printf("\nAnda belum membeli apapun. Silahkan pilih barang terlebih dahulu!\n\n");
                continue;
            }
            else{
                system("cls");
                sortingItem(isiBarang);
                rekapPesanan(isiBarang);
                break;
            }
        }
        //Pilihan Keluar
        else if (pilihan == 00){
            printf("\nMenghentikan Program.........\n");
            break;
        }
        else {
            printf("Input Tidak valid!");
        }
        //End Pengkondisian Pilihan
    }
    //End Looping Pilihan
}
//End Code Main
// Copy Paste Area
//    printf("");
