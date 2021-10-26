#include <stdio.h>

int zaokrouhli(float num)
{
    int a = (int)num;

    if ((num - a) >= 0.5)
    {
        a ++;
    }

    return a;
}

void drawStrecha(int sirka, int vyska)
{
    for (int y = 0; y <= (sirka/2-1); y++)
    {   
        int count = 0;

        for (int x = 1; x <= sirka; x ++)
        {
            if (y == 0)
            {
                if (x == zaokrouhli((float)sirka/2))
                {
                    putchar('X');
                    break;
                }
                else 
                {
                    putchar(' ');
                }
            }
            else
            {
                
                if ((x-y) == zaokrouhli((float)sirka/2) || (x+y) == zaokrouhli((float)sirka/2))
                {
                    putchar('X');
                    count ++;
                    if (count == 2) {break;}
                }
                else
                {
                    putchar(' ');
                }
            }
        }
        putchar('\n');
    }
}

void drawCtverec(int sirka, int vyska, int isFull, int plot)
{   
    char inside = 'o';
    char cPlot;

    for (int y = vyska; y >= 1; y--)
    {
        if ((plot % 2) == 0)
        {
            if (y == 1 || y == plot)
            {
                cPlot = '-';
            }
            else
            {
                cPlot = ' ';
            }
        }
        else
        {
            cPlot = '|';
        }

        for (int x = 1; x <= (sirka + plot); x++)
        {
            if (x <= sirka)
            {
                if (y == 1 || x == 1 || y == vyska || x == sirka)
                {
                    putchar('X');
                }
                else
                {
                    if (isFull)
                    {
                        putchar(inside);
                        if (inside == 'o')
                        {
                            inside = '*';
                        }
                        else
                        {
                            inside = 'o';
                        }
                    }
                    else
                    {
                        putchar(' ');
                    }
                }
            }
            else if (y <= plot)
            {
                if (y == plot || y == 1)
                {
                    putchar(cPlot);

                    if (cPlot == '|')
                    {
                        cPlot = '-';
                    }
                    else
                    {
                        cPlot = '|';
                    }
                }
                else
                {
                    putchar(cPlot);

                    if (cPlot == '|')
                    {
                        cPlot = ' ';
                    }
                    else
                    {
                        cPlot = '|';
                    }
                }
                
            }
            
        }
        putchar('\n');
    }
}

int main ()
{
    int input;
    int rozmery[] = {0, 0, 0};

    for (int i = 0; i <= 2; i++)
    {
        int scanRet = scanf("%i", &input);

        if (scanRet == EOF)
        {
            break;
        }
        else if (scanRet !=1)
        {
            fprintf(stderr, "Error: Chybny vstup!\n");
            return 100;
        }
        else if (input > 69 || input < 3)
        {
            fprintf(stderr, "Error: Vstup mimo interval!\n");
            return 101;
        }
        
        rozmery[i] = input;
    }


    for (int i = 2; i >= 0; i--)
    {
        if (rozmery[i] != 0)
        {
            if (i == 2)
            {
                if (rozmery[2] > rozmery[1])
                {
                    fprintf(stderr, "Error: Neplatna velikost plotu!\n");
                    return 103;
                }

                drawStrecha(rozmery[0], rozmery[1]);
                drawCtverec(rozmery[0], rozmery[1], rozmery[0] == rozmery[1], rozmery[2]);
            }
            else if (i == 1) //domecek i=0>sirka; i=1>vyska
            {
                         
                if (rozmery[0] % 2 == 0)
                {
                    fprintf(stderr, "Error: Sirka neni liche cislo!\n");
                    return 102;
                }
                
                drawStrecha(rozmery[0], rozmery[1]);
                drawCtverec(rozmery[0], rozmery[1], rozmery[0] == rozmery[1], 0);
            }
            else if (i == 0) //ctverec
            {
                drawCtverec(rozmery[0], rozmery[0], 0, 0);
            }

            break;
        }
    }

    
    return 0;
}

