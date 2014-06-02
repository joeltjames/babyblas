#include <stdio.h>
void mvv_(const int* N,const double* vec,const double* mat, double* vresults)
{
     int i = 0;
     const int m = *N;

     while (i < m)
     {
          double sum0 = 0.0, sum1 = 0.0, sum2 = 0.0, sum3 = 0.0;
          double sum4 = 0.0, sum5 = 0.0, sum6 = 0.0, sum7 = 0.0;
          double sum8 = 0.0, sum9 = 0.0, sum10 = 0.0, sum11 = 0.0;
          double sum12 = 0.0, sum13 = 0.0, sum14 = 0.0, sum15 = 0.0;
          
          int j = 0; 
          const int mod = m % 16;

          while (j < mod)
          {
               sum0 += *(mat + m * j + i    ) * *(vec + j++  );
          }
          do
          {
               sum0 += *(mat + m * j + i    ) * *(vec + j    );
               sum1 += *(mat + m * (j + 1) + i) * *(vec + j + 1);
               sum2 += *(mat + m * (j + 2) + i) * *(vec + j + 2);
               sum3 += *(mat + m * (j + 3) + i) * *(vec + j + 3);
               sum4 += *(mat + m * (j + 4) + i) * *(vec + j + 4);
               sum5 += *(mat + m * (j + 5) + i) * *(vec + j + 5);
               sum6 += *(mat + m * (j + 6) + i) * *(vec + j + 6);
               sum7 += *(mat + m * (j + 7) + i) * *(vec + j + 7);
               sum8 += *(mat + m * (j + 8) + i) * *(vec + j + 8);
               sum9 += *(mat + m * (j + 9) + i) * *(vec + j + 9);
               sum10 += *(mat + m * (j + 10) + i) * *(vec + j + 10);
               sum11 += *(mat + m * (j + 11) + i) * *(vec + j + 11);
               sum12 += *(mat + m * (j + 12) + i) * *(vec + j + 12);
               sum13 += *(mat + m * (j + 13) + i) * *(vec + j + 13);
               sum14 += *(mat + m * (j + 14) + i) * *(vec + j + 14);
               sum15 += *(mat + m * (j + 15) + i) * *(vec + j + 15);
               j += 16;
          } while(j < m);
          
          *(vresults + i) = sum0 + sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8 + sum9 + sum10 + sum11 + sum12 + sum13 + sum14 + sum15;
          
          ++i;
     }
}
