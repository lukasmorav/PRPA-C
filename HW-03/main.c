#include <stdio.h>

int jeSude(int num)// 1-je; 0-neni
{
    if ((num % 2) == 0|| num == 0)
    {
        return 1;
    }
    return 0;
}

int jeKladne(int num)// 1-je; 0-neni
{
    if (num > 0)
    {
        return 1;
    }

    return 0;
}

int main ()
{
    int numIN;
    int pocetC = 0;
    int pocetKC = 0;
    int pocetZC = 0;
    int pocetSC = 0;
    int pocetLC = 0;
    int maxC = 0;
    int minC = 0;
    int suma = 0;
    int first = 1;

    while (1)
    {
        if (scanf("%d", &numIN) != 1 )
        {
            printf("\n");
            break;
        }
        
        if (numIN > 10000 || numIN < -10000)
        {
            printf("\n");
            printf("Error: Vstup je mimo interval!\n");
            return 100;
        }

        if (first == 0)
        {
            printf(", %d", numIN);
            if (minC > numIN)
            {
                minC = numIN;
            }

            if (maxC < numIN)
            {
                maxC = numIN;
            }
        }
        else
        {
            printf("%d", numIN);
            first = 0;
            minC = numIN;
            maxC = numIN;
        }
        
        pocetC++;

        suma += numIN;

        pocetSC += jeSude(numIN);
        pocetLC += 1-jeSude(numIN);

        if (numIN != 0)
        {
            pocetKC += jeKladne(numIN);
            pocetZC += 1-jeKladne(numIN);
        }
    }

    printf("Pocet cisel: %d\n", pocetC);
    printf("Pocet kladnych: %d\n", pocetKC);
    printf("Pocet zapornych: %d\n", pocetZC);
    printf("Procento kladnych: %.2f\n", ((float)pocetKC/pocetC)*100);
    printf("Procento zapornych: %.2f\n", ((float)pocetZC/pocetC)*100);
    printf("Pocet sudych: %d\n", pocetSC);
    printf("Pocet lichych: %d\n", pocetLC);
    printf("Procento sudych: %.2f\n", ((float)pocetSC/pocetC)*100);
    printf("Procento lichych: %.2f\n", ((float)pocetLC/pocetC)*100);
    printf("Prumer: %.2f\n", ((float)suma/pocetC));
    printf("Maximum: %d\n", maxC);
    printf("Minimum: %d\n", minC);

    return 0;
}

