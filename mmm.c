#include <stdio.h>
void mmm_(const int* N, double* mat1, double* mat2, double* rmat)
{
	int i = 0, m = *N;
	for ( ; i < m ; ++i)
	{
		int mi = m * i;
		int j = 0;
		do
		{
			int mij = mi + j;
			int k = 0;
			double sum1 = 0.0;
			for ( ; k < m % 16; ++k)
			{
				sum1 += *(mat1 + mi + k) * *(mat2 + m * k + j);
				k++;
			}
			do
			{
				int mik = mi + k, mkj = m * k + j ,test = 1;
				sum1  += *(mat1+ mik     ) * *(mat2 + mkj     )
				      +  *(mat1+ mik +  test) * *(mat2 + mkj +  test++)
                                      +  *(mat1+ mik +  test) * *(mat2 + mkj +  test++)
                                      +  *(mat1+ mik +  test) * *(mat2 + mkj +  test++)
                                      +  *(mat1+ mik +  test) * *(mat2 + mkj +  test++)
                                      +  *(mat1+ mik +  test) * *(mat2 + mkj +  test++)
                                      +  *(mat1+ mik +  test) * *(mat2 + mkj +  test++)
                                      +  *(mat1+ mik +  test) * *(mat2 + mkj +  test++)
                                      +  *(mat1+ mik +  test) * *(mat2 + mkj +  test++)
                                      +  *(mat1+ mik +  test) * *(mat2 + mkj +  test++)
                                      +  *(mat1+ mik + test) * *(mat2 + mkj  + test++) 
                                      +  *(mat1+ mik + test) * *(mat2 + mkj  + test++) 
                                      +  *(mat1+ mik + test) * *(mat2 + mkj  + test++) 
                                      +  *(mat1+ mik + test) * *(mat2 + mkj  + test++) 
                                      +  *(mat1+ mik + test) * *(mat2 + mkj  + test++) 
                                      +  *(mat1+ mik + test) * *(mat2 + mkj  + test); 
				k += 16;
			} while ( k < m ) ;
			*(rmat + mij) = sum1 ;
			++j;
		} while ( j < m );
	}
}
