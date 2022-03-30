#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    printf("[----- [정준호]  [2020069046] -----]\n");

    int row, col;
    srand(time(NULL));

    printf("Input row and col : ");
    scanf("%d %d", &row, &col);
    int** matrix_a = create_matrix(row, col);
    int** matrix_b = create_matrix(row, col);
    int** matrix_a_t = create_matrix(col, row);

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;}

    do{
        printf("\n----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch(command) {
        case 'z': case 'Z':
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;
        case 'p': case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A':
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S':
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T':
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M':
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    }while(command != 'q' && command != 'Q');

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
    int** dptr;
    int i;

    for (i = 0; i < row; i++)
        dptr = (int **)malloc(row * sizeof(int *));

    for (i = 0; i < row; i++) {
        *(dptr + i) = (int *)malloc(col * sizeof(int));
    }
    return dptr;
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
    int i, j;

/* printing table */
    // printing first horizontal line of table
    for (j = 0; j < col; j++) {
        printf("--------");
    }
    printf("-\n");

    // printing contents of matrix and remaining table
    for (i = 0; i < row; i ++) {
        for (j = 0; j < col; j++) {
            printf("|       ");
        }
        printf("|\n");
        for (j = 0; j < col; j++) {
            printf("|%7d", matrix[i][j]);
        }
        printf("|\n");
        for (j = 0; j < col; j++) {
            printf("|       ");
        }
        printf("|\n");
        for (j = 0; j < col; j++) {
            printf("--------");
        }
        printf("-\n");
    }
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            matrix[i][j] = rand() % 20;
        }
    }
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int i, j;
    int** matrix_temp;
    matrix_temp = create_matrix(row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            matrix_temp[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }
    printf("The result is..\n");
    print_matrix(matrix_temp, row, col);
    free_matrix(matrix_temp, row, col);
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int i, j;
    int** matrix_temp;
    matrix_temp = create_matrix(row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            matrix_temp[i][j] = matrix_a[i][j] - matrix_b[i][j];
        }
    }
    printf("The result is..\n");
    print_matrix(matrix_temp, row, col);
    free_matrix(matrix_temp, row, col);
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
    
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
    int i, j, k;
    int** matrix_temp;
    int sum = 0;
    matrix_temp = create_matrix(row, row);
    for (i = 0; i < row; i++) {
        for (j = 0; j < row; j++) {
            for (k = 0; k < col; k++) {
                sum += matrix_a[i][k] * matrix_t[k][j];
            }
            matrix_temp[i][j] = sum;
        }
    }
    printf("The result is..\n");
    print_matrix(matrix_temp, row, row);
    free_matrix(matrix_temp, row, row);
}


// additional custom functions