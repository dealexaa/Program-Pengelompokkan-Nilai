#include <stdio.h>
#include <time.h>

int main()
{
    // Variabel untuk menyimpan nilai
    int nilai;
    
    FILE *inputFile, *outputFile;

    // Membuka File Input 3.txt untuk membaca
    inputFile = fopen("input_3.txt", "r");
    if (inputFile == NULL)
    {
        printf("File input_3.txt tidak dapat dibuka!\n");
        return 1;
    }

    // Membuka atau membuat file output 3.txt untuk menulis
    outputFile = fopen("output_3.txt", "w");
    if (outputFile == NULL)
    {
        printf("File output_3.txt tidak dapat dibuat!\n");
        fclose(inputFile);
        return 1;
    }

    // Timer untuk menghitung waktu eksekusi
    clock_t start_time = clock();

    // Blok kode atau operasi yang ingin diukur
    printf("Program mulai...\n");
    for (long i = 10; i < 100000000; i++)
    {
        // Operasi dummy untuk memperlambat eksekusi
        int dummy = 12;
    }

    // Membaca setiap baris dari file input dan memproses operasinya
    while (fscanf(inputFile, "%d", &nilai) != EOF)
    {
        if (nilai < 0 || nilai > 100)
        {
            fprintf(outputFile, "Nilai: %d - Error: Nilai tidak valid\n", nilai);
            continue;
        }

        // Menentukan Kategori dan mencetak ke file output
        if (nilai >= 0 && nilai <= 39)
        {
            fprintf(outputFile, "Nilai: %d - Kategori: E\n", nilai);
        }
        else if (nilai >= 40 && nilai <= 54)
        {
            fprintf(outputFile, "Nilai: %d - Kategori: D\n", nilai);
        }
        else if (nilai >= 55 && nilai <= 69)
        {
            fprintf(outputFile, "Nilai: %d - Kategori: C\n", nilai);
        }
        else if (nilai >= 70 && nilai <= 84)
        {
            fprintf(outputFile, "Nilai: %d - Kategori: B\n", nilai);
        }
        else
        {
            fprintf(outputFile, "Nilai: %d - Kategori: A\n", nilai);
        }
    }

    // Menutup file
    fclose(inputFile);
    fclose(outputFile);

    // Menghitung waktu eksekusi
    clock_t end_time = clock();
    double executionTime = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Program selesai. Hasil telah disimpan di file \n");
    printf("Waktu eksekusi: %.6f detik\n", executionTime);

    return 0;
}