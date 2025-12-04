#include <stdio.h>
#include "../inc/graficos.h"

#define ANSI_RESET   "\x1b[0m"
#define ANSI_BLACK   "\x1b[30m"
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"
#define ANSI_WHITE   "\x1b[37m"

//####################################################################################################################

void ImprimirLogo()
{
    printf("\033[1;32m"); 
    printf("   _____      _                       \n");
    printf("  / ____|    | |          By Aguz     \n");
    printf(" | |     __ _| | ___ _   _            \n");
    printf(" | |    / _` | |/ __| | | |           \n");
    printf(" | |___| (_| | | (__| |_| |           \n");
    printf("  \\_____\\__,_|_|\\___|\\__,_| v1.0  \n");
    printf("\033[0m"); // Resetear color
    printf("--------------------------------------\n");
}

//#####################################################################################################################

void ImprimirNombreColor(int codigo)
{
    switch (codigo) 
    {
        case 0: printf(ANSI_WHITE "NEGRO (0)" ANSI_RESET); break;
        case 1: printf(ANSI_CYAN "MARRON (1)" ANSI_RESET); break;
        case 2: printf(ANSI_RED "ROJO (2)" ANSI_RESET); break;
        case 3: printf(ANSI_YELLOW "NARANJA (3)" ANSI_RESET); break;
        case 4: printf(ANSI_YELLOW "AMARILLO (4)" ANSI_RESET); break;
        case 5: printf(ANSI_GREEN "VERDE (5)" ANSI_RESET); break;
        case 6: printf(ANSI_BLUE "AZUL (6)" ANSI_RESET); break;
        case 7: printf(ANSI_MAGENTA "VIOLETA (7)" ANSI_RESET); break;
        case 8: printf(ANSI_WHITE "GRIS (8)" ANSI_RESET); break;
        case 9: printf(ANSI_WHITE "BLANCO (9)" ANSI_RESET); break;
        default: printf("Desconocido"); break;
    }
}