#include <stdio.h>



int main()
{
    //message loader
    int messageSize;
    char *codedMessage, *halfDecodedMessage;
    scanf("%i%s%s", &messageSize, &codedMessage, &halfDecodedMessage);

    printf("%s\n", halfDecodedMessage);
    return 0;
}