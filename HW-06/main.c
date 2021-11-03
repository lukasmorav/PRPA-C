#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkABC(char *text)
{
    for (int i=0; i<strlen(text); i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || text[i] >= 'a' && text[i] <= 'z')
        {
            continue;
        }

        return 0;
    }

    return 1;
}

char charShift(char original, int offset)
{
    
    for (int i=1; i<=offset; i++)
    {
        switch (original)
        {
            case 'Z':
                original = 'a';
                break;
            
            case 'z':
                original = 'A';
                break;
            
            default:
                original++;
                break;
        }
    }

    return original;
}

void stringShift(const char* text, char* dest, int offset)
{
    for (int i=0; i<strlen(text); i++)
    {
        dest[i] = charShift(text[i], offset);
    }
}

int compareStr(const char* text1, const char* text2)
{
    int correctChars = 0;
    for (int i=0; i<strlen(text1); i++)
    {
        if(text1[i] == text2[i])
        {
            correctChars ++;
        }
    }

    return correctChars;
}

int main()
{
    //message loader
    int messageSize;
    
    if (scanf("%i", &messageSize) != 1)
    {
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }

    char codedMessage[messageSize], halfDecodedMessage[messageSize];
    scanf("%s%s", codedMessage, halfDecodedMessage);
    
    if (strlen(codedMessage) != messageSize || strlen(halfDecodedMessage) != messageSize) //check correct size
    {
        fprintf(stderr, "Error: Chybna delka vstupu!\n");
        return 101;
    }

    if (!checkABC(codedMessage) || !checkABC(halfDecodedMessage)) //check A-Z or a-z
    {
        fprintf(stderr, "Error: Chybny vstup!\n");
        return 100;
    }

    //decoding process
    int bestCorrectChars, correctChars, bestOffset;
    char testMessage[messageSize], decodedMessage[messageSize];

    for (int i=1; i<=52; i++)
    {
        stringShift(codedMessage, testMessage, i);
        correctChars = compareStr(testMessage, halfDecodedMessage);
        if (&bestCorrectChars == NULL)
        {
            bestOffset = i;
            bestCorrectChars = correctChars;
        }
        else if (bestCorrectChars < correctChars)
        {
            bestCorrectChars = correctChars;
            bestOffset = i;
        }
    }

    stringShift(codedMessage, decodedMessage, bestOffset);
    printf("%s\n", decodedMessage);

    return 0;
}