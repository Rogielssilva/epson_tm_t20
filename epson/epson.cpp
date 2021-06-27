//
// Created by Rogiel on 04/06/21.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "epson.h"

extern "C" long IniciaPorta(unsigned char *);
extern "C" long FechaPorta(void);
extern "C" long ImprimeTextoTag(unsigned char *);
extern "C" long Le_Status(void);

void closeConnection()
{
    long iRetorno;

    iRetorno = FechaPorta();

    if (iRetorno);    
    else
        printf("ERROR AO FECHAR A CONEXAO COM A IMPRESSORA\n");
}

long getStatus()
{
    return Le_Status();

    //     switch (iRetorno)
    //     {
    //     case 0:
    //         printf("Error ao imprimir, verifique a impressora\n");
    //         break;

    //     // case 5:
    //     //     printf("Impressora com pouco papel.\r\n");
    //     //     break;

    //     // case 9:
    //     //     printf("Tampa aberta.\r\n");
    //     //     break;

    //     // case 24:
    //     //     printf("Impressora 'ONLINE'.\r\n");
    //     //     break;

    //     // case 32:
    //     //     printf("Impressora sem papel.\r\n");
    //     //     break;
    //     };

    //     // printf("( Pressione <ENTER> para retornar menu principal )\r\n");
    //     // printf("***********************************************\r\n\r\n");

    //     // getchar();
    // }
}

long connectDevice()
{
    //Para Impressora Serial
    //iRetorno = IniciaPorta((unsigned char*)"COM1");

    //Para impressora USB
    //iRetorno = IniciaPorta((unsigned char*)"USB");

    if (getStatus() != (24 || 32))
    {
        return 0;
    }

    return IniciaPorta((unsigned char *)"192.168.0.16");
}

void PrintDevice(char *text)
{
    long iRetorno;
    iRetorno = connectDevice();

    if (iRetorno == 0)
    {
        printf("ERROR AO IMPRIMIR, VERIFIQUE A IMPRESSORA\n");
        return;
    }

    strcat(text, "<c>03/12/2013 15:50:22\n</ce></c><gui></gui>");

    iRetorno = ImprimeTextoTag((unsigned char *)text);

    if (iRetorno)
    {
        closeConnection();
    }
    else
        printf("ERROR AO IMPRIMIR O CUPOM NAO FISCAL.\r\n");
}