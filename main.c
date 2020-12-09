#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int gauss(double **mas, int n)
{
    int k = 0, ind, s = 1;

    while (k < n)
    {
        double temp = mas[k][k];

        if(temp == 0)

        {
            for(int i = 0; i < n; i++)

                if(mas[i][k] != 0)
                {
                    ind = i;
                    break;
                }

            for(int i = 0; i < n; i++)

            {

                double t = mas[k][i];

                mas[k][i] = mas[ind][i];

                mas[ind][i] = t;

            }

            if (k != ind)
                s *= -1;
        }

        for (int i = k + 1; i < n; i++)
        {
            double temp = mas[i][k]/mas[k][k];

            for (int j = 0; j < n; j++)
            {
                mas[i][j] -= mas[k][j] * temp;
            }
        }
        k++;
    }
    return s;
}
int main()
{
    setlocale(LC_ALL, "Rus");

    int n, s;
    double d = 1;

    printf("¬ведите количество строк и столбцов матрицы n*n : ");
    scanf("%d", &n);

    double **mas;
    mas = (double**) malloc(n*sizeof(double*));

    for (int i = 0; i < n; ++i)
    {
        mas[i] = (double*) malloc(n*sizeof(double));
    }


    printf("¬ведите саму матрицу: \n");

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        {
          scanf("%lf", &mas[i][j]);
        }


    printf("¬ведЄнна€ матрица :\n");

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            printf("%lf ", mas[i][j]);
        }
        printf("\n");
    }

    s = gauss(mas, n);


    printf("\nƒиагональный вид : \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", mas[i][j]);
        }
        printf("\n");
    }


    for(int i = 0; i < n; i++)
     {
        d *= mas[i][i];
     }

    d *= s;

    printf("\nќпределитель матрицы d = %lf", d);

    return 0;
}

