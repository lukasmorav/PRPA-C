#include <stdio.h>

int vyhodnoceni(char prePismeno, char pismeno, int count, int superCount, int compressCount)
{
    //printf("%c\n", prePismeno);
    if (pismeno != 10 && pismeno != EOF) {superCount ++;}
    if (pismeno == EOF)
    {
        fprintf(stderr, "Pocet vstupnich symbolu: %i\n", superCount);
        fprintf(stderr, "Pocet zakodovanych symbolu: %i\n", compressCount);
        fprintf(stderr, "Kompresni pomer: %.2f\n", compressCount/(float)superCount);
        
        return 0;
    }
    
    if (prePismeno == 1 || prePismeno == pismeno)
    {

        if ((pismeno < 'A' || pismeno > 'Z') && pismeno != 10)
        {
            fprintf(stderr, "Error: Neplatny symbol!\n");
            return 100;
        }

        if (count == 255)
        {
            fprintf(stdout, "%c%i", prePismeno, count);
            compressCount += 4;

            return vyhodnoceni(pismeno, getchar(), 1, superCount, compressCount);
        }

        return vyhodnoceni(pismeno, getchar(), (count+1), superCount, compressCount);
        
    }
    else if (prePismeno != pismeno)
    {
        if (count < 3)
        {
            for (int i = count; i > 0; i--)
            {
                fprintf(stdout, "%c", prePismeno);
                compressCount ++;
            }

            if ((pismeno < 'A' || pismeno > 'Z') && pismeno != 10)
            {
                
                fprintf(stderr, "Error: Neplatny symbol!\n");
                return 100;
            }

            return vyhodnoceni(pismeno, getchar(), 1, superCount, compressCount);
        }

        if (count < 10)
        {
            compressCount += 2;
        }
        else if (count < 100)
        {
            compressCount += 3;
        }
        else 
        {
            compressCount += 4;
        }

        fprintf(stdout, "%c%i", prePismeno, count);
        return vyhodnoceni(pismeno, getchar(), 1, superCount, compressCount);
    }

    return 100;
}

int main()
{
    int retVal = vyhodnoceni(1, getchar(), 0, 0, 0);
    
    if (retVal == 0)
    {
        fprintf(stdout, "\n");
    }

    return retVal;
}

