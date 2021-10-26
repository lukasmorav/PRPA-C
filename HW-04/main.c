#include <stdio.h>

int main()
{
    char pismeno, prePismeno;
    int count = 0;
    int superCount = 0;
    int codedCount = 0;

    while (1)
    {
        if (scanf("%c", &pismeno) != 1)
        {
            break;
            printf("\n");
        }

        superCount++;

        if (pismeno < 'A' || pismeno > 'Z')
        {
            fprintf(stderr, "Error: Neplatny symbol!\n");
            return 100;
        }

        if (&prePismeno == NULL || prePismeno == pismeno)
        {
            if (count == 255)
            {
                printf("%c%d", prePismeno, count);
                count = 1;
                codedCount += 4;
            }
            else
            {
                count ++;
            }
        }
        else if (prePismeno != pismeno)
        {
            if (count < 3)
            {
                for(int i = 0; i < count; i++)
                {
                    printf("%c", prePismeno);
                    codedCount++;
                }
                count = 1;
            }
            else
            {
                printf("%c%d", prePismeno, count);
                if (count < 10)
                {
                    codedCount += 2;
                }
                else if (count < 100)
                {
                    codedCount += 3;
                }
                else
                {
                    codedCount += 4;
                }
                count = 1;
            }
        }

        prePismeno = pismeno;
    }

    fprintf(stderr, "Pocet vstupnich symbolu: %d\n", superCount);
    fprintf(stderr, "Pocet zakodovanych symbolu: %d\n", codedCount);
    fprintf(stderr, "Kompresni pomer: %.2f\n", (float)superCount/codedCount);
    

    return 0;
}

