void vvm_(int* N, double* vec1, double* vec2, double* rmat)
{
     int i = 0;
     const int m = *N, mod = m % 2;

     while(i < m)
     {
          int j = 0;
          const int mi = i * m;

          const double value = *(vec1 + i);		
          while (j < mod)
          {
               *(rmat + mi + j     ) = value * *(vec2 + j++     );
          }
          
          do
          {
               *(rmat + mi + j    ) = value * *(vec2 + j    );
               *(rmat + mi + j + 1) = value * *(vec2 + j + 1);
               j += 4;
          } while (j < m);

          ++i;
     }
}
