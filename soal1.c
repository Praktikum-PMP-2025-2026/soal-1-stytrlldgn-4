/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
*   Modul               : 3 - Structures and Dynamic Arrays
*   Hari dan Tanggal    : rabu, 29 April 2026
*   Nama (NIM)          : I Ketut Satya Adnyana (13224076)
*   Nama File           : soal1.c
*   Deskripsi           : Arsip Artefak terkategori
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { 
   char nama[100];
   char kategori[100];
   int tahun;
   int nilai;
} Artefak;

int compare(const void *a, const void *b){
    Artefak *m1 = (Artefak *)a;
    Artefak *m2 = (Artefak *)b;

    //kategori alfabetis naik, dari terkecil
    if (strcmp(m1->kategori, m2->kategori )!=0) {
       return m2->kategori - m1->kategori;
    }

    //jikasama, tahun naik, dari terbesar
    if (m1->tahun != m2->tahun) {
       return m1->tahun - m2->tahun;
    }

    //jikasama, nilai turun, dari terkecil
    if (m1->nilai != m2->nilai) {
       return m2->nilai - m1->nilai;
    }

    //jikasama, nama lebih kecil lebih baik
    return strcmp(m1->nama, m2->nama);
}
 
int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    if (n <= 0) {
        return 0;
    }
    Artefak *dataArtefak = (Artefak *)malloc(n * sizeof(Artefak));
    if (dataArtefak == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %d", dataArtefak[i].nama, dataArtefak[i].kategori, &dataArtefak[i].tahun, &dataArtefak[i].nilai);
    }
    qsort(dataArtefak, n, sizeof(Artefak), compare);
    for (int i = 0; i < n ; i++) {
        printf("%s %s %d %d\n", dataArtefak[i].nama, dataArtefak[i].kategori, dataArtefak[i].tahun, dataArtefak[i].nilai);
    }
   free(dataArtefak);
   return 0;
}
