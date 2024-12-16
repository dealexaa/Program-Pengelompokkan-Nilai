#include <stdio.h>


int main() {
    // Variabel untuk menyimpan nilai
    float nilaiKehadiran, nilaiTugas, nilaiUTS, nilaiUAS, nilaiAkhir;
    char nama[100], NIM[100], prodi[100], fakultas[100], grade;
    char *keterangan;
    char pilihan; // Variabel untuk mengulangi atau keluar
    
    do {
        // Meminta input nilai
        printf("Masukkan Nama Anda : ");
        fgets(nama, sizeof(nama), stdin);
       
        printf("Masukkan NIM Anda : ");
        fgets(NIM, sizeof(NIM), stdin);

        printf("Masukkan Prodi Anda : ");
        fgets(prodi, sizeof(prodi), stdin);
       
        printf("Masukkan Fakultas Anda : ");
        fgets(fakultas, sizeof(fakultas), stdin);
       
       // Meminta input nilai dengan validasi
        do {
            printf("Masukkan nilai kehadiran (0-100): ");
            scanf("%f", &nilaiKehadiran);
            if (nilaiKehadiran < 0 || nilaiKehadiran > 100) {
                printf("Peringatan: Nilai kehadiran harus di antara 0-100!\n");
            }
        } while (nilaiKehadiran < 0 || nilaiKehadiran > 100);

        do {
            printf("Masukkan nilai tugas (0-100): ");
            scanf("%f", &nilaiTugas);
            if (nilaiTugas < 0 || nilaiTugas > 100) {
                printf("Peringatan: Nilai tugas harus di antara 0-100!\n");
            }
        } while (nilaiTugas < 0 || nilaiTugas > 100);

        do {
            printf("Masukkan nilai UTS (0-100): ");
            scanf("%f", &nilaiUTS);
            if (nilaiUTS < 0 || nilaiUTS > 100) {
                printf("Peringatan: Nilai UTS harus di antara 0-100!\n");
            }
        } while (nilaiUTS < 0 || nilaiUTS > 100);

        do {
            printf("Masukkan nilai UAS (0-100): ");
            scanf("%f", &nilaiUAS);
            if (nilaiUAS < 0 || nilaiUAS > 100) {
                printf("Peringatan: Nilai UAS harus di antara 0-100!\n");
            }
        } while (nilaiUAS < 0 || nilaiUAS > 100);
        // Menghitung nilai akhir
        nilaiAkhir = (nilaiKehadiran * 0.2) + (nilaiTugas * 0.2) + (nilaiUTS * 0.25) + (nilaiUAS * 0.35);

        // Menentukan grade dan keterangan
        if (nilaiAkhir >= 0 && nilaiAkhir <= 55) {
            grade = 'E';
            keterangan = "Maaf, anda tidak lulus!";
        } else if (nilaiAkhir >= 56 && nilaiAkhir <= 65) {
            grade = 'D';
            keterangan = "Maaf, anda tidak lulus!";
        } else if (nilaiAkhir >= 66 && nilaiAkhir <= 75) {
            grade = 'C';
            keterangan = "Anda lulus, tingkatkan lagi untuk kedepannya!";
        } else if (nilaiAkhir >= 76 && nilaiAkhir <= 85) {
            grade = 'B';
            keterangan = "Anda lulus dengan baik, tingkatkan terus belajarnya!";
        } else if (nilaiAkhir >= 86 && nilaiAkhir <= 100) {
            grade = 'A';
            keterangan = "Selamat! Anda lulus dengan nilai yang sangat memuaskan!";
        } else {
            printf("Terjadi kesalahan pada perhitungan! \n");
            return 1; // Keluar dari program jika nilai tidak valid
        }

        // Menampilkan output
        printf("\n----------------------------------\n");
        printf("\tNILAI AKHIR ANDA");
        printf("\n----------------------------------\n");
        printf(" NAMA            : %s", nama);
        printf(" NIM             : %s", NIM);
        printf(" PRODI           : %s", prodi);
        printf(" FAKULTAS        : %s ", fakultas);
        printf("Nilai Akhir     : %.2f\n", nilaiAkhir);
        printf(" Grade           : %c\n", grade);
        printf(" Keterangan      : %s\n", keterangan);

        // Tanya untuk melanjutkan
        printf("\nApakah Anda ingin memasukkan data mahasiswa lain? (y/t): ");
        getchar();
        scanf("%c", &pilihan);
        getchar();
       
    } while (pilihan == 'y' || pilihan == 'Y'); // Ulang jika jawabannya 'y' atau 'Y'

    printf("Terima kasih telah menggunakan program ini!\n");
    return 0;
}