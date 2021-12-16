#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows, columns;
    char op;
    int **values;
}Matrix;

int loadMatrix(Matrix *dest, int rows, int columns)
{  
    for (int i = 0; i < rows; i++)
    {
        for (int y = 0; y < columns; y++)
        {
            if (scanf("%i", &dest->values[i][y]) != 1) {return 100;};
        }
    }
    getchar();

    return 0;
}

void freeMatrix(Matrix *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        free(m->values[i]);
    }
    free(m->values);
}

void printMatrix(const Matrix m)
{
    printf("%i %i\n", m.rows, m.columns);
    for (int r = 0; r < m.rows; r++)
    {
        for (int c = 0; c < m.columns; c++)
        {
            (c == 0) ? printf("%i", m.values[r][c]) : printf(" %i", m.values[r][c]);
            
        }
        printf("\n");
    }
}

int callculate(const Matrix m1, const Matrix m2, Matrix *dest)
{
    switch (m2.op)
    {
    case '+':
        if (m1.columns != m2.columns || m1.rows != m2.rows) {return 100;}

        dest->rows = m1.rows;
        dest->columns = m1.columns;
        dest->op = m1.op;
        dest->values = (int**)malloc(m1.rows * sizeof(int*));
        for (int i = 0; i < m1.rows; i++) {dest->values[i] = (int*)malloc(m1.columns * sizeof(int));}

        for (int r = 0; r < m1.rows; r++)
        {
            for (int c = 0; c < m1.columns; c++)
            {
                dest->values[r][c] = m1.values[r][c] + m2.values[r][c];
            }
        }
        break;

    case '-':
        if (m1.columns != m2.columns || m1.rows != m2.rows) {return 100;}

        dest->rows = m1.rows;
        dest->columns = m1.columns;
        dest->op = m1.op;
        dest->values = (int**)malloc(m1.rows * sizeof(int*));
        for (int i = 0; i < m1.rows; i++) {dest->values[i] = (int*)malloc(m1.columns * sizeof(int));}
 
        for (int r = 0; r < m1.rows; r++)
        {
            for (int c = 0; c < m1.columns; c++)
            {
                dest->values[r][c] = m1.values[r][c] - m2.values[r][c];
            }
        }
        break;

    case '*':
        if (m1.columns != m2.rows) {return 100;}

        dest->rows = m1.rows;
        dest->columns = m2.columns;
        dest->op = m1.op;
        dest->values = (int**)malloc(dest->rows * sizeof(int*));
        for (int i = 0; i < dest->rows; i++) {dest->values[i] = (int*)malloc(dest->columns * sizeof(int));}
        for (int dr = 0; dr < dest->rows; dr++)
        {
            for (int dc = 0; dc < dest->columns; dc++)
            {
                dest->values[dr][dc] = 0;
                for (int r = 0; r < m2.rows; r++)
                {
                    dest->values[dr][dc] += m1.values[dr][r] * m2.values[r][dc];
                }
            }
        }
        break;
    
    default:
        break;
    }

    return 1;
}

int main ()
{
    /* Loading  Matrixes */
    int rows, columns;
    int size = 1;
    char op = '+';
    Matrix *matrixes = (Matrix *)malloc(0 * sizeof(Matrix));

    while (scanf("%i %i", &rows, &columns) == 2)
    {
        /* Matrix initialization */
        matrixes = (Matrix *)realloc(matrixes, size * sizeof(Matrix));
        Matrix m1;
        m1.rows = rows;
        m1.columns = columns;
        m1.op = op;
        m1.values = (int**)malloc(rows * sizeof(int*));
        for (int i = 0; i < rows; i++) {m1.values[i] = (int*)malloc(columns * sizeof(int));}
        
        /* Loading values and checking for right input */
        if (loadMatrix(&m1, rows, columns) == 100)
        {
            
            for (int i = 0; i < size; i ++)
            {
                freeMatrix(&matrixes[i]);
            }
            free(matrixes);
            freeMatrix(&m1);

            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }

        
        matrixes[size-1] = m1;
        op = getchar();
        size++;
    }

    /*
    for (int i=0; i < (x-1); i ++)
    {
        printMatrix(matrixes[i]);
        if ((i+1) != (x-1)) {printf("%c\n", matrixes[i+1].op);}
    }
    */

    /* Callculation process */
    Matrix answer;

    /* Only 2 matrixes */
    
    if (callculate(matrixes[0], matrixes[1], &answer) == 100)
    {
        for (int i = 0; i < size-1; i ++)
        {
            freeMatrix(&matrixes[i]);
        }
        free(matrixes);

        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }

    printMatrix(answer);

    for (int i = 0; i < size-1; i ++)
    {
        freeMatrix(&matrixes[i]);
    }
    free(matrixes);
    freeMatrix(&answer);
    
    /* For more matrixes */
    /*
    Matrix *nMatrixes;
    int nSize = 1;
    nMatrixes = (Matrix *)malloc(nSize * sizeof(Matrix));

    for (int i = 0; i < size-2; i++)
    {
        nMatrixes = (Matrix *)realloc(nMatrixes, nSize * sizeof(Matrix));
        if (matrixes[i+1].op == '*')
        {
            if (callculate(matrixes[i-1], matrixes[i], &nMatrixes[i-1]) == 100)
            {
                for (int i = 0; i < size-1; i ++)
                {
                    freeMatrix(&matrixes[i]);
                }
                free(matrixes);

                for (int i = 0; i < nSize; i ++)
                {
                    freeMatrix(&nMatrixes[i]);
                }
                free(nMatrixes);

                fprintf(stderr, "Error: Chybny vstup!\n");
                return 100;
            }
        }
        else
        {
            nMatrixes[i] = matrixes[i];
        }
        nSize ++;
    }

    for (int i = 0; i < nSize-1; i ++)
    {
        printMatrix(nMatrixes[i]);
    }
    


    printMatrix(answer);

    for (int i = 0; i < nSize; i ++)
    {
        freeMatrix(&nMatrixes[i]);
    }
    free(nMatrixes);

    for (int i = 0; i < size-1; i ++)
    {
        freeMatrix(&matrixes[i]);
    }
    free(matrixes);
    freeMatrix(&answer);
    */
    return 0;
}




