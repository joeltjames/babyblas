void con_(int *N,double *mat,double* vec)
{
     int m = *N;
     double new[m][m], newv[m];
     double p[m][m];
     int i = 0;
     while (i < m)
     {
          int j = 0;
          while (j < m)
          {
               p[i][j] = 0.0;
          }
          p[i][i] = 1.0 / *(mat+(i*m)+i);
     }
     
     mmm_(N,p,mat,new);
     mvv_(N,vec,p,newv);

     i = 0;
     while (i < m)
     {
          *(vec+i) = newv[i];
          int j = 0;
          while (j < m)
          {
               *(mat+(i*m)+j) = new[i][j++];
          }
     }
}
