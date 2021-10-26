#include <stdio.h>
#include <string.h>


int main()
{
    //message loader
    int inputLength, scanfRet;
    if (scanf("%i", &inputLength) != 1)
    {
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }

    char inputData, decodedMessage, encodedMessage;
    while (scanfRet = scanf("%s", &inputData) != EOF)
    {
        printf("%li", strlen(&inputData));
        if (strlen(&inputData) != inputLength)
        {
            fprintf(stderr, "Error: Chybna delka vstupu!\n");
            return 101;
        }
        
        if (&encodedMessage == NULL)
        {
            encodedMessage = inputLength;
            continue;
        }
        else
        {
            decodedMessage = inputData;
            continue;
        }
    }

    return 0;
}