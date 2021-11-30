#include <stdio.h>
#include <stdlib.h>

int checkABC(char c)
{
   if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
   {
       return 0;
   }

    return 1;
}

int loadMessage(char *message, int messageSize)
{
    int index = 0;
    while(index <= messageSize)
    {
        char c;
        scanf("%c", &c);
        //printf("%c\n", c);

        if (c != '\n')
        {
            if (checkABC(c)) return 100;
            message[index] = c;    
            index ++;
        }
        else
        {
            break;
        }
    }
    
    //printf("%i\n", index);
    message[index+1] = '\0';
    if (index < messageSize)  return 101;

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

void stringShift(const char* text, char* dest, int offset, int messageSize)
{
    for (int i=0; i<=messageSize; i++)
    {
        if (messageSize == i) dest[i] = '\0'; else dest[i] = charShift(text[i], offset);
    }
}

int compareStr(const char* text1, const char* text2, int messageSize)
{
    int correctChars = 0;
    for (int i=0; i<messageSize; i++)
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
    int messageSize, retVal;
    
    if (scanf("%i\n", &messageSize) != 1)
    {
        fprintf(stderr, "Error: Chybny vstup!");
        return 100;
    }

    char codedMessage[messageSize+1], receivedMessage[messageSize+1];

    retVal = loadMessage(codedMessage, messageSize);
    if (retVal != 1)
    {
        if (retVal==100) fprintf(stderr, "Error: Chybny vstup!"); else fprintf(stderr, "Error: Chybna delka vstupu!");
        return retVal;
    }

    retVal = loadMessage(receivedMessage, messageSize);
    if (retVal != 1)
    {
        if (retVal==100) fprintf(stderr, "Error: Chybny vstup!"); else fprintf(stderr, "Error: Chybna delka vstupu!");
        return retVal;
    }

    //decoding process
    int bestCorrectChars, correctChars, bestOffset;
    char testMessage[messageSize+1], decodedMessage[messageSize+1];

    bestCorrectChars = -1;

    for (int i=1; i<=52; i++)
    {
        stringShift(codedMessage, testMessage, i, messageSize);
        correctChars = compareStr(testMessage, receivedMessage, messageSize);
        if (bestCorrectChars < correctChars)
        {
            bestCorrectChars = correctChars;
            bestOffset = i;
        }
    }

    stringShift(codedMessage, decodedMessage, bestOffset, messageSize);
    printf("%s\n", decodedMessage);
    
    return 0;
}

