#include "../epson/epson.h"
#include "stdio.h"
#include "string.h"


int main(){
    char text[200];

    strcat(text, "hello world!!");

    PrintDevice(text);

    return 0;    
}

