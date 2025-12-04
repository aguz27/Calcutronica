#include <stdio.h>
#include <stdlib.h>
#include "../inc/funciones.h"
#include "../inc/graficos.h"

void Pausar() 
{
    printf("\n\n>> Presiona ENTER para volver al menu principal...");
    while (getchar() != '\n'); 
    getchar();
}

//###################################################################################################################
//######################## FUNCION MAIN #############################################################################
//###################################################################################################################

int main ()
{
    int A = 0; //Menu principal
    int RAM;   //Opcion del menu de resistencias

    do 
    {
        system("clear");

        printf("################################################\n");
        printf("#    SISTEMA DE AYUDA AL ELECTRONICO (v1.0)    #\n");
        printf("################################################\n");
        ImprimirLogo();
        
        printf("\nBienvenido, con que desea trabajar?\n");
        printf("1- Ley de Ohm\n");
        printf("2- Ley de Kirchhoff\n");
        printf("3- Nodos de Thevenin\n");
        printf("4- Suma de resistencias (Serie/Paralelo)\n");
        printf("5- Calculos de Capacitancia\n");
        printf("6- Codigo de Colores (Resistencias)\n");
        printf("7- Laboratorio de Microchips\n");
        printf("8- Calculadora de LED (Resistencia)\n");
        printf("9- Ley de Watt (Potencia)\n");
        printf("10- Autonomia de Baterias\n");
        printf("11- Divisor de Tensión (Calcular Resistencias)\n");

        printf("\n0- Salir del programa\n");
        printf("\nOpción: ");
        
        scanf("%d", &A);

        switch (A) 
        {
            case 1:
                printf("\n--- LEY DE OHM ---\n");
                Ohm();
                Pausar();
                break;

            case 2:
                printf("\n--- LEY DE KIRCHHOFF ---\n");
                Kirchhoff ();
                Pausar();
                break;

            case 3:
                printf("\n--- THEVENIN ---\n");
                Thevenin();
                Pausar();
                break;

            case 4:
                printf("\n--- SUMA DE RESISTENCIAS ---\n");
                printf("¿Cálculo en Serie o Paralelo?\n");
                printf("1- Serie\n");
                printf("2- Paralelo\n");
                printf("Opción: ");
                scanf("%d", &RAM);
                
                if (RAM == 1) 
                {
                    RSerie();
                } 
                else if (RAM == 2) 
                {
                    RParalelo();
                } 
                else 
                {
                    printf("Opción de resistencia no válida.\n");
                }
                Pausar();
                break;

            case 5:
                printf("\n--- CAPACITANCIA ---\n");
                Capacitores ();
                Pausar();
                break;

            case 6:
                ColoresResistencia();
                Pausar();
                break;
            
            case 7:
                Microchips(); 
                Pausar();
                break;

            case 8:
                CalcularLED();
                Pausar();
                break;

            case 9:
                LeyWatt();
                Pausar();
                break;

            case 10:
                AutonomiaBaterias();
                Pausar();
                break;

            case 11:
                DivisorInverso();
                Pausar();
                break;

            case 0:
                printf("\nGuardando herramientas... ¡Adios!\n");
                break;

            default:
                printf("\n¡Esa opción no existe! Intenta de nuevo.\n");
                Pausar();
                break;
        }

    } 
    while (A != 0);
    return 0;
}

 