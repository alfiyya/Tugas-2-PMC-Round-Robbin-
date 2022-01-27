// Putri Alfiyyahdianti
// 18320041
// PMC K02

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, limit, total = 0, x, counter = 0, time_quantum;
    int waktu_tunggu = 0, waktu_penyelesaian = 0, waktu_kedatangan[500], waktu_eksekusi[500], temp[500];
    float average_waktu_kedatangan, average_waktu_penyelesaian;
    printf("Masukkan total nomor proses :");
    scanf("%d", &limit);
    x = limit;
    for(i = 0; i < limit; i++)
       {
           printf("\nMasukkan data proses [%d]\n", i + 1);

           printf("waktu kedatangan:\t");

           scanf("%d", &waktu_kedatangan[i]);

           printf("waktu eksekusi:\t");

           scanf("%d", &waktu_eksekusi[i]);

           temp[i] = waktu_eksekusi[i];
      }

      printf("\nMasukkan waktu kuantum:\t");
      scanf("%d", &time_quantum);
      printf("\nProcess ID\t\tWaktu Eksekusi \t\t Waktu Penyelesaian\t\t Waktu Tunggu");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess No[%d]\t\t%d\t\t\t\t%d\t\t\t%d", i + 1, waktu_eksekusi[i], total - waktu_kedatangan[i], total - waktu_kedatangan[i] - waktu_eksekusi[i]);
                  waktu_tunggu = waktu_tunggu + total - waktu_kedatangan[i] - waktu_eksekusi[i];
                  waktu_penyelesaian = waktu_penyelesaian + total - waktu_kedatangan[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(waktu_kedatangan[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }

      average_waktu_kedatangan = waktu_tunggu * 1.0 / limit;
      average_waktu_penyelesaian = waktu_penyelesaian * 1.0 / limit;
      printf("\n\nRata Rata Kedatangan Waktu:t%f", average_waktu_kedatangan);
      printf("\nRata Rata Penyelesaian Waktu:t%f\n", average_waktu_penyelesaian);
      return 0;
}

