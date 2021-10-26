#include <stdio.h>

int main()
{
    int numA;
    int numB;
    scanf("%d%d", &numA, &numB);

    if (!(numA < -10000 || numA > 10000 || numB < -10000 || numB > 10000))
    {    
        printf("Desitkova soustava: %d %d\n", numA, numB);
        printf("Sestnactkova soustava: %x %x\n", numA, numB);
        printf("Soucet: %d + %d = %d\n", numA, numB, (numA+numB));
        printf("Rozdil: %d - %d = %d\n", numA, numB, (numA-numB));
        printf("Soucin: %d * %d = %d\n", numA, numB, (numA*numB));

        if (numB == 0)
        {
            printf("Nedefinovany vysledek!\n");
        }
        else
        {
            printf("Podil: %d / %d = %d\n", numA, numB, (numA/numB));
        }

        printf("Prumer: %.1f\n", (float)(numA+numB)/2);
    }
    else
    {
        printf("Vstup je mimo interval!\n");
    }

    return 0;
}
