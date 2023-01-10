#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void swap (int *a, int *b);

void arr_create(int **arr, int x_size, int y_size);
void arr_fill(int **arr, int x_size, int y_size);
void arr_print_num(int **arr, int x_size, int y_size);
void arr_clear(int **arr, int x_size);

void max_min(int **A, int A_size, int *max_a, int *min_a);
int **arr_transp(int **B, int n_b, int m_b);
int **arr_mult(int **A, int A_size, int **B, int B_rows, int B_columns);
void arr_sort(int **A, int A_size, int var);
int arr_sum(int **A, int A_size, int **B, int B_rows, int B_columns);

#define VARIANT 8

int main()
{
    int min_a, max_a, var;
    const int A_size = VARIANT, B_rows = VARIANT;
    int B_columns = 0;
    char repeat;

    printf("columns = ");
    scanf("%d", &B_columns);
    printf("\n\n");

    //////////////////CREATING////////////////
    int **A = (int **)malloc(sizeof(int *) * A_size);
    for (int i = 0; i < A_size; i++)
        A[i] = (int *)malloc(sizeof(int) * A_size);
    int **B = (int **)malloc(sizeof(int *) * B_rows);
    for (int i = 0; i < B_rows; i++)
        B[i] = (int *)malloc(sizeof(int) * B_columns);
    int **C;
    //////////////////CREATING////////////////

    arr_fill(A, A_size, A_size);      // fill
    arr_print_num(A, A_size, A_size); // print

    arr_fill(B, B_rows, B_columns);      // fill
    arr_print_num(B, B_rows, B_columns); // print

    ///////////////////////MAIN TASK////////////////////
    printf("1|min max\n2|transp\n3|mult\n4|sort\n5|sum\nChoose method ");
    scanf("%d", &var);
    switch (var)
    {
    case 1:
        max_min(A, A_size, &max_a, &min_a);
        printf("min and max number, lower than main diagonal\nmin = %d; max = %d\n", min_a, max_a);
        break;
    case 2:
        C = arr_transp(B, B_rows, B_columns);
        arr_print_num(C, B_columns, B_rows);
        arr_clear(C, B_columns); // clearing
        break;
    case 3:
        C = arr_mult(A, A_size, B, B_rows, B_columns);
        arr_print_num(C, B_rows, B_columns);
        arr_clear(C, B_rows); // clearing
        break;
    case 4:
        printf("enter row for sort, or \"0\", for sort matrix ");
        scanf("%d", &var);
        arr_sort(A, A_size, var);
        arr_print_num(A, A_size, A_size);
        break;
    case 5:
        printf("total_sum = %d\n", arr_sum(A, A_size, B, B_rows, B_columns));
        break;
    }
    ///////////////////////MAIN TASK////////////////////

    arr_clear(A, A_size); // clearing
    arr_clear(B, B_rows); // clearing
    printf("enter \"s\" for stop programm, or \"r\", for repeat all ");
    scanf("%s", &repeat);
    if (repeat == 'r')
        return main();
    getch();
    return 0;
}


void swap(int *a, int *b)
{
    int pp = *b;
    *b = *a;
    *a = pp;
}

void arr_fill(int **arr, int x_size, int y_size)
{
    for (int i = 0; i < x_size; i++)
        for (int j = 0; j < y_size; j++)
            arr[i][j] = 5 - i * j; // fill arr
}

void arr_print_num(int **arr, int x_size, int y_size)
{
    printf("%2d  ", 0);
    for (int j = 1; j <= y_size; j++)
        printf(" %5d", j);
    printf("\n");
    for (int i = 0; i < x_size; i++)
    {
        printf("%2d||", i + 1);
        for (int j = 0; j < y_size; j++)
            printf(" %5d", arr[i][j]);
        printf(" ||\n");
    }
    printf("\n");
}

void arr_clear(int **arr, int x_size)
{
    for (int i = 0; i < x_size; i++)
        free(arr[i]);
    free(arr);
}

////////////////////////////////////////////////////////////

void max_min(int **A, int A_size, int *max_a, int *min_a)
{
    if (A_size > 1)
    {
        *max_a = *min_a = A[1][0];
        for (int i = 2; i < A_size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (A[i][j] < *min_a)
                    *min_a = A[i][j];
                else if (A[i][j] > *max_a)
                    *max_a = A[i][j];
            }
        }
    }
    else
        printf("WRONG MATRIX");
}

int **arr_transp(int **B, int B_rows, int B_columns)
{
    int C_rows = B_columns, C_columns = B_rows;
    int **C = (int **)malloc(sizeof(int *) * C_rows);
    for (int i = 0; i < C_rows; i++)
        C[i] = (int *)malloc(sizeof(int) * C_columns);
    for (int i = 0; i < C_rows; i++)
        for (int j = 0; j < C_columns; j++)
            C[i][j] = B[j][i];
    return C;
}

int **arr_mult(int **A, int A_size, int **B, int B_rows, int B_columns)
{
    if (A_size == B_rows)
    {
        //////////////////INICILISATION//////////////////
        int C_rows = A_size, C_columns = B_columns;
        int **C = (int **)malloc(sizeof(int *) * C_rows);
        for (int i = 0; i < C_rows; i++)
            C[i] = (int *)malloc(sizeof(int) * C_columns);
        //////////////////INICILISATION//////////////////

        //////////////////ONULENNYA////////////
        for (int i = 0; i < C_rows; i++)
            for (int j = 0; j < C_columns; j++)
                C[i][j] = 0;
        //////////////////ONULENNYA////////////

        for (int i = 0; i < C_rows; i++)
            for (int j = 0; j < C_columns; j++)
                for (int t = 0; t < A_size; t++)
                    C[i][j] += A[i][t] * B[t][j];
        return C;
    }
    else
    {
        printf("ne uzgodzheno\n");
        return 0;
    }
}

void arr_sort(int **A, int A_size, int var) // Сортуравання вибором / Selection sort
{
    printf("\n\n");
    if (var == 0)
    {
        int minz = A[0][0], *ind = &A[0][0];
        for (int i = 0; i < A_size; i++)
            for (int j = 0; j < A_size; j++)
            {
                minz = A[i][j];
                ind = &A[i][j];
                for (int ii = i, jj = j; ii < A_size; ii++, jj = 0)
                    for (jj; jj < A_size; jj++)
                        if (A[ii][jj] < minz)
                        {
                            minz = A[ii][jj];
                            ind = &A[ii][jj];
                        }
                swap(&A[i][j], ind);
            }
    }
    else
    {
        int minz = A[var - 1][0], *ind = &A[var - 1][0];
        for (int j = 0; j < A_size; j++)
        {
            minz = A[var - 1][j];
            ind = &A[var - 1][j];
            for (int jj = j; jj < A_size; jj++)
                if (A[var - 1][jj] < minz)
                {
                    minz = A[var - 1][jj];
                    ind = &A[var - 1][jj];
                }
            swap(&A[var - 1][j], ind);
        }
    }
}

int arr_sum(int **A, int A_size, int **B, int B_rows, int B_columns)
{
    int total_sum = 0;
    for (int i = 0; i < A_size; i++)
        for (int j = 0; j < A_size; j++)
            total_sum += A[i][j];
    for (int j = 0; j < B_columns; j++)
        for (int i = 0; i < B_rows; i++)
            total_sum += B[i][j];
    return total_sum;
}
