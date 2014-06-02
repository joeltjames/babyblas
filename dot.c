double dot_(const int *N,const double* vec1,const double* vec2)
{
     int i = 0;
     
     const int m = *N, mod = m % 16;
     
     double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
     double sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0;
     double sum9 = 0, sum10 = 0, sum11 = 0, sum12 = 0;
     double sum13 = 0, sum14 = 0, sum15 = 0, sum16 = 0;

     while (i < mod)
     {
          sum1 += *(vec1+i) * *(vec2 + i++);
     }

     while (i < m)
     {
          sum1  += *(vec1 + i     )  * *(vec2 + i     );
          sum2  += *(vec1 + i +  1)  * *(vec2 + i +  1);
          sum3  += *(vec1 + i +  2)  * *(vec2 + i +  2);
          sum16 += *(vec1 + i +  3)  * *(vec2 + i +  3);
          sum4  += *(vec1 + i +  4)  * *(vec2 + i +  4);
          sum5  += *(vec1 + i +  5)  * *(vec2 + i +  5);
          sum6  += *(vec1 + i +  6)  * *(vec2 + i +  6);
          sum7  += *(vec1 + i +  7)  * *(vec2 + i +  7);
          sum8  += *(vec1 + i +  8)  * *(vec2 + i +  8);
          sum9  += *(vec1 + i +  9)  * *(vec2 + i +  9);
          sum10  += *(vec1 + i +  10)  * *(vec2 + i +  10);
          sum11  += *(vec1 + i +  11)  * *(vec2 + i +  11);
          sum12  += *(vec1 + i +  12)  * *(vec2 + i +  12);
          sum13  += *(vec1 + i +  13)  * *(vec2 + i +  13);
          sum14  += *(vec1 + i +  14)  * *(vec2 + i +  14);
          sum15  += *(vec1 + i +  15)  * *(vec2 + i +  15);

          i += 16;
     }

     return sum1 + sum2 + sum3 + sum4 + sum5 + sum6 + sum7 + sum8 + sum9 + sum10 + sum11 + sum12 + sum13 + sum14 + sum15 + sum16;
}
