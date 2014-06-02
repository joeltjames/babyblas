#include <math.h>
void dls_(const int* N, double* mat, double* vec, double* rvec)
{
     const int m = *N;
     int i = 0;
     while (i < m)
     {
          int j;
          j = i;
          int max_row = i;
          while (j < m)
          {
               double val = fabs( *(mat+j*m+j) );
               int k = j + 1;
               while (k < m)
               {
                    double newv = fabs(*(mat+k*m+j));
                    if ( newv > val )
                    {
                         max_row = k;
                         val = newv;
                    }
                    ++k;
               }
               ++j;
          }
          j = i;
          double temp = *(vec+j);
          *(vec+j) = *(vec+max_row);
          *(vec+max_row) = temp;
          while (j < m)
          {
               temp = *(mat+i*m+j);
               *(mat+i*m+j) = *(mat+max_row*m+j);
               *(mat+max_row*m+j) = temp;
               ++j;
          }
          j = i + 1;
          while (j < m)
          {
               double ratio = *(mat+j*m+i) / *(mat+i*m+i);
               int k = i;
               *(vec+j) -= *(vec+i) * ratio;
               while (k < m)
               {
                    *(mat+j*m+k) -= ratio * *(mat+i*m+k);
                    k++;
               }
               ++j;
          }
          ++i;
     }
     i = m - 1;
     while (i >= 0)
     {
          *(rvec+i) = *(vec+i);
          int j = i + 1;
          while (j < m)
          {
               *(rvec+i) -= *(mat+i*m+j) * *(rvec+j);
               j++;
          }
          *(rvec+i) /= *(mat+i*m+i);
          --i;
     }
}
