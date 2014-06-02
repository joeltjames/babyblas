#include <math.h>
#include <stdio.h>

void ils_(const int* N,const double* mat,const double* vec, double* rvec)
{
     int k = 0, MAX_ITERS = 1000, m = *N;
     double x0[m];
     double tol = 1E-16;

     k = 0;

     while(k < MAX_ITERS)
     {
          int i = 0; 
          double maxnorm = -1;
          while ( i < m)
          {
               int j = 0; 
               double sum = 0.0;
               while (j < i)
               {
                    sum -=  *(mat+i*m+j) * x0[j++];
               }
               j++;
               while (j < m)
               {
                    sum -=  *(mat+i*m+j) * x0[j++];
               }
               *(rvec+i) = ((sum) + *(vec+i))/ *(mat+i*m+i);
               maxnorm = fmax(maxnorm, fabs( *(rvec+i) - x0[i] ));
               i++;
          }
          if (maxnorm < tol)
          {
               return;
          }
          i = 0;
          while (i < m)
          {
               x0[i] = *(rvec+i);
               i++;
          }
          k++;
     }
}
