#include <stdio.h>
#include <stdlib.h>

void apppend (int *numbers, int new, int i)
{
    if (i == 0)
    {
        numbers[i] = new;
    }
    else if (new > numbers[i-1])
    {
        numbers[i] = new;
    }
    else
    {
        numbers[i] = numbers[i-1];
        apppend(numbers, new, --i);
    }
}

void findEValues(float *eValues, const float size, const int min, int n)
{
    eValues[n] = (float)(min + n * size);
    if (n != 0) {findEValues(eValues, size, min, --n);}
}

int calcBins(int *numbers, int i1, int i2, const int min, const float size)
{
    if (i2 == -1)
    {
        return 0;
    }
    else if (i1 == (int)((numbers[i2] - min)/size))
    {
        return calcBins(numbers, i1, --i2, min, size) + 1;
    }
    else
    {
        return calcBins(numbers, i1, --i2, min, size);
    }
}

int main ()
{
    int rows;
    if (scanf("%i", &rows) != 1)
    {
        fprintf(stderr, "Error: Chyba histogramu!\n");
        return 100;
    }

    int i = 0;
    int *numbers = (int *)malloc(1 * sizeof(int));
    int max, min;

    while(1)
    {
        int holder;
        numbers = (int *)realloc(numbers, (i+1) * sizeof(int));
        if (scanf("%i", &holder) != 1)
        {
            break;
        }

          ////////////
         // PART A //
        ////////////

        if (i == 0) {max = min = holder;}
        else if (max < holder) {max = holder;}
        else if (min > holder) {min = holder;}

        apppend(numbers, holder, i);
        i++;
    }

    
    float medianPos = i/2;
    if (medianPos - (int)medianPos == 0)
    {
        printf("Median %.2f\n", (float)numbers[(int)medianPos]);
    }
    else
    {
        printf("Median %.2f\n", (float)(numbers[(int)medianPos] + numbers[(int)medianPos+1])/2);
    }
    
    printf("Pocet cisel: %i\n", i);
    printf("Min. hodnota: %i\n", min);
    printf("Max. hodnota: %i\n", max);

      ////////////
     // PART B //
    ////////////

    float size = (float)(max - min)/rows;

    float *eValues = (float*)malloc(rows * sizeof(float));
    findEValues(eValues, size, min, rows);
    int *fractions = (int *)malloc(rows * sizeof(int));
    int lBin;

    for (int x = 0; x < rows; x++)
    {
        fractions[x] = calcBins(numbers, x, i, min, size);
        if (fractions[lBin] < fractions[x]){lBin = x;}
    }


    printf("Histogram:\n");

    for (int i = 0; i < rows; i++)
    {
        if (eValues[i] < 10) {printf("  %.1f", eValues[i]);}
        else if (eValues[i] < 100) {printf(" %.1f", eValues[i]);}
        else {printf("%.1f", eValues[i]);}

        printf(" - ");

        if (eValues[i+1] < 10) {printf("  %.1f |", eValues[i+1]);}
        else if (eValues[i+1] < 100) {printf(" %.1f |", eValues[i+1]);}
        else {printf("%.1f |", eValues[i+1]);}

        
        if (fractions[i] != 0)
        {
            for (int y = 0; y < 25/(float)fractions[lBin] * fractions[i]; y++)
            {
                printf("=");
            } 
        }

        printf("\n");
    }

    free(numbers);
    free(eValues);
    free(fractions);

    return 0;
}
