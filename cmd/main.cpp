#include "../epson/epson.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main()
{
    char text[200];
    char ip []= "192.168.0.16";
    long result;

    result = StartConnection(ip);
    if (result == 0)
    {
        printf("error while connection to the device ip %s\n", ip);
        exit(EXIT_FAILURE);
    }

    strcat(text, "hello world!!");

    PrintDevice(text);

    return 0;
}
