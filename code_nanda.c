//Start Include
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
//End Include

//Start Define and Typedef
#define MAX_ITEMS 5
typedef struct barang kotakBarang;
//End Define and Typedef

//Start Array barang
struct barang {
    char nama[30];
    int harga;
    int jumlah;
};
//End Array barang

//Start Main
int main(){
    //Deklarasi Variable
    int totalHargaBarang = 0, uangBayar = 0, kembalian, j = 1, totalSemuaHargaBarang = 0, totalSemuaDiskonBarang = 0,
    totalBayar, pilihan, jumlahBeliBarang, jumlahSemuaBarang, perluTampilanAwal = 1;

    //Isian Array barang
    kotakBarang isiBarang[MAX_ITEMS] = {
        {"Buku Tulis", 5000, 0},
        {"Pensil", 2000, 0},
        {"Penghapus", 1000, 0},
        {"Penggaris", 1000, 0},
        {"Bujur Sangkar", 500, 0}
    };
    //Start Looping dan Pengkondisian pilihan
    while (1){
        if (perluTampilanAwal == 1){
            tampilanAwal(isiBarang);
            perluTampilanAwal = 0;
        }
        printf("\nInput Pilihan yang anda inginkan : ");
        scanf("%d", &pilihan);
        //jika pilihan barang dipilih run code dibawah
        if (pilihan >=1 && pilihan <=5){
            printf("Masukkan Jumlah beli %s : ", isiBarang[pilihan - 1].nama);
            scanf ("%d" ,&jumlahBeliBarang);
            if (jumlahBeliBarang <= 0){
                printf("Jumlah yang anda masukkan tidak valid!\n");
            }
            else{
                isiBarang[pilihan - 1].jumlah += jumlahBeliBarang;
            }
        }
        //jika pilihan 99 dipilih run code dibawah
        else if(pilihan == 99){
            for (int i = 0; i< MAX_ITEMS; i++){
                jumlahSemuaBarang += isiBarang[i].jumlah;
            }
            if (jumlahSemuaBarang == 0)
            {
                printf("Anda belum membeli apapun......\n");
            }
            else{
                system("cls");
                sortingBarang(isiBarang);
                rekapanPesanan(isiBarang);
                cetakStruk(isiBarang);
                break;
            }
        }
        //jika pilihan 55 dipilih run code dibawah
        else if(pilihan == 55){
            for (int i = 0; i < MAX_ITEMS; i++){
                isiBarang[i].jumlah = 0;
            }
            printf("Pilihan barang telah direset!\n\n");
            //looping untuk clear screen
            printf("Tekan Enter untuk melanjutkan......");
            while (getchar() != '\n');
            getchar();//menangkap enter
            system("cls");
            perluTampilanAwal = 1;
        }
        //jika pilihan 00 dipilih run code dibawah
        else if(pilihan == 00){
            printf("Menghentikan program......");
            break;
        }
        //Selain itu
        else{
            printf("Input Tidak Valid!\n\n");
        }
    }
    //End Looping dan Pengkondisian pilihan
}
//End Main

//Start Tampilan Awal (class Main, method tampilanAwal())
void tampilanAwal(kotakBarang isiBarang[]){
    printf("Selamat Datang di toko SKENSA\n");
    printf("Silahkan pilih barang yang anda inginkan : \n\n");
    printf("===================================================\n");
    printf("| No. | Barang               | Harga              |\n");
    printf("|-------------------------------------------------|\n");

    //Start Looping pemanggilan array barang
    for (int i = 0; i < MAX_ITEMS; i++){
        printf("| %-3d | %-20s | Rp.%-15d |\n", i+1, isiBarang[i].nama, isiBarang[i].harga);

    }
    //End Looping pemanggilan array barang
    printf("===================================================\n\n");
    printf("1-5. Pilihan Barang\n");
    printf("99.  Pembayaran\n");
    printf("55.  Reset Pilihan\n");
    printf("00.  Keluar\n\n");
    printf("===================================================\n\n");
}
//End Tampilan Awal

//Start Function Diskon
int diskon(int jumlah, int totalHarga){
    //Jika jumlah barang >=3
    if(jumlah >= 5){
        //diskon 15%
        return totalHarga * 0.15;
    }
    else if(jumlah >= 3){
        //diskon 10%
        return totalHarga * 0.1;
    }
    else{
        return 0;
    }
}
//End Function Diskon

//Start Bubble Sort
void sortingBarang(kotakBarang isiBarang[]){
    //Penyimpanan sementara array
    kotakBarang temp;
    for (int i = 0; i < MAX_ITEMS - 1; i++){
        for (int j = 0; j < MAX_ITEMS - i - 1; j++){
            //jika array pertama lebih kecil jumlahnya dari array selanjutnya maka
            if(isiBarang[j].jumlah < isiBarang[j+1].jumlah){
                //tukar array pertama ke array selanjutnya
                temp = isiBarang[j];
                isiBarang[j] = isiBarang[j+1];
                isiBarang[j+1] = temp;
            }
        }
    }
}
//End Bubble Sort

//Start Rekapan Pesanan
void rekapanPesanan(kotakBarang isiBarang[]){
    //Tampilan rekapan pesanan barang
    printf("Rekapan Pesanan Barang\n");
    printf("=====================================================================================\n");
    printf("| No. | Jumlah  | Nama Barang     | Harga         | Total Harga        | Diskon     |\n");
    printf("|-----------------------------------------------------------------------------------|\n");
    //Start Looping pemanggilan array dan pengecekan jumlah barang
    for (int i = 0; i < MAX_ITEMS; i++){
        if (isiBarang[i].jumlah == 0){
            continue;
        }
        else{
            //Aritmatika total harga per barang
            totalHargaBarang = isiBarang[i].jumlah * isiBarang[i].harga;
            printf("| %-3d | %-7d | %-15s | Rp.%-10d | %-18d | %-10d |\n", j, isiBarang[i].jumlah, isiBarang[i].nama, isiBarang[i].harga, totalHargaBarang, diskon(isiBarang[i].jumlah, totalHargaBarang) );
            //Auto Increment nomor
            j++;
            //Penambahan pada Total Harga dan Total Diskon semua barang
            totalSemuaHargaBarang += totalHargaBarang;
            totalSemuaDiskonBarang += diskon(isiBarang[i].jumlah, totalHargaBarang);
        }
    }
    //End Looping pemanggilan array dan pengecekan jumlah barang

    //Aritmatika totalBayar
    totalBayar = totalSemuaHargaBarang - totalSemuaDiskonBarang;

    //Lanjutan Tampilan rekapan pesanan barang
    printf("=====================================================================================\n\n");
    printf("Total Harga : Rp.%d\n", totalSemuaHargaBarang);
    printf("Total Diskon : Rp.%d\n", totalSemuaDiskonBarang);
    printf("Total Bayar : Rp.%d\n\n", totalBayar);
    printf("=====================================================================================\n\n");

    //Start Pengecekan dan pengkondisian uang bayar
    while (1){
        printf("Masukkan Uang Bayar : Rp.");
        scanf ("%d",&uangBayar);

        //Aritmatika kembalian
        kembalian = uangBayar - totalBayar;

        //Kondisi ketika uang yang dibayar kurang dari total harga
        if (kembalian < 0){
            printf("Maaf, uang yang anda masukkan tidak cukup! Silahkan coba lagi\n\n");
            continue;
        }
        else{
            printf("Kembalian : Rp.%d\n\n", kembalian);
            break;
        }
    }
    //End Pengecekan dan pengkondisian uang bayar
    printf("Terimakasih sudah berbelanja di Toko SKENSA!\n");
    printf("=====================================================================================\n\n");
}
//End Rekapan Pesanan

//Start Cetak Struk
void cetakStruk(kotakBarang isiBarang[]){
}
//End Cetak Struk


