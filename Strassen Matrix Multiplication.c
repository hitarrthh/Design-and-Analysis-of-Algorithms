#include <stdio.h>
#include <stdlib.h>
 
#define MAX_SIZE 10
 
void print(char *display, int **matrix, int start_row, int start_column, int end_row, int end_column)
{
    printf("\n%s =>\n", display);
    for (int i = start_row; i <= end_row; i++)
    {
        for (int j = start_column; j <= end_column; j++)
        {
            printf("%10d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}
 
void add_matrix(int **matrix_A, int **matrix_B, int **matrix_C, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
}
 
int **multiply_matrix(int **matrix_A, int **matrix_B, int rows_A, int cols_A, int rows_B, int cols_B)
{
    if (cols_A != rows_B)
    {
        printf("\nError: The number of columns in Matrix A must be equal to the number of rows in Matrix B\n");
        return NULL;
    }
 
    int **result_matrix = (int **)malloc(rows_A * sizeof(int *));
    for (int i = 0; i < rows_A; i++)
        result_matrix[i] = (int *)malloc(cols_B * sizeof(int));
 
    if (cols_A == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];
    else
    {
        for (int i = 0; i < rows_A; i++)
            for (int j = 0; j < cols_B; j++)
            {
                result_matrix[i][j] = 0;
                for (int k = 0; k < cols_A; k++)
                    result_matrix[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
    }
    return result_matrix;
}
 
int main()
{
    int choice, rows_A, cols_A, rows_B, cols_B;
 
    printf("Enter the number of rows for Matrix A: ");
    scanf("%d", &rows_A);
    printf("Enter the number of columns for Matrix A: ");
    scanf("%d", &cols_A);
 
    int **matrix_A = (int **)malloc(rows_A * sizeof(int *));
    for (int i = 0; i < rows_A; i++)
        matrix_A[i] = (int *)malloc(cols_A * sizeof(int));
 
    printf("Enter the elements for Matrix A:\n");
    for (int i = 0; i < rows_A; i++)
        for (int j = 0; j < cols_A; j++)
            scanf("%d", &matrix_A[i][j]);
 
    printf("Enter the number of rows for Matrix B: ");
    scanf("%d", &rows_B);
    printf("Enter the number of columns for Matrix B: ");
    scanf("%d", &cols_B);
 
    int **matrix_B = (int **)malloc(rows_B * sizeof(int *));
    for (int i = 0; i < rows_B; i++)
        matrix_B[i] = (int *)malloc(cols_B * sizeof(int));
 
    printf("Enter the elements for Matrix B:\n");
    for (int i = 0; i < rows_B; i++)
        for (int j = 0; j < cols_B; j++)
            scanf("%d", &matrix_B[i][j]);
 
    do
    {
        printf("\nMenu:\n");
        printf("1. Print Matrix A\n");
        printf("2. Print Matrix B\n");
        printf("3. Add Matrices A and B\n");
        printf("4. Multiply Matrices A and B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch (choice)
        {
        case 1:
            print("Matrix A", matrix_A, 0, 0, rows_A - 1, cols_A - 1);
            break;
        case 2:
            print("Matrix B", matrix_B, 0, 0, rows_B - 1, cols_B - 1);
            break;
        case 3:
            if (rows_A == rows_B && cols_A == cols_B)
            {
                int **result_matrix = (int **)malloc(rows_A * sizeof(int *));
                for (int i = 0; i < rows_A; i++)
                    result_matrix[i] = (int *)malloc(cols_A * sizeof(int));
 
                add_matrix(matrix_A, matrix_B, result_matrix, rows_A, cols_A);
                print("Result of Addition", result_matrix, 0, 0, rows_A - 1, cols_A - 1);
 
                for (int i = 0; i < rows_A; i++)
                    free(result_matrix[i]);
                free(result_matrix);
            }
            else
                printf("\nError: Matrices A and B must have the same dimensions for addition.\n");
            break;
        case 4:
            if (cols_A == rows_B)
            {
                int **result_matrix = multiply_matrix(matrix_A, matrix_B, rows_A, cols_A, rows_B, cols_B);
                if (result_matrix != NULL)
                {
                    print("Result of Multiplication", result_matrix, 0, 0, rows_A - 1, cols_B - 1);
 
                    for (int i = 0; i < rows_A; i++)
                        free(result_matrix[i]);
                    free(result_matrix);
                }
            }
            else
                printf("\nError: The number of columns in Matrix A must be equal to the number of rows in Matrix B for multiplication.\n");
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);
 
    for (int i = 0; i < rows_A; i++)
        free(matrix_A[i]);
    free(matrix_A);
 
    for (int i = 0; i < rows_B; i++)
        free(matrix_B[i]);
    free(matrix_B);
 
    return 0;
}
 