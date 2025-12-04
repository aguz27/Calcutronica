#include <stdio.h>
#include <stdlib.h>
#include "../inc/funciones.h"
#include "../inc/graficos.h"

//###################################################################################################################
//################## FUNCION LEY DE OHM #############################################################################
//###################################################################################################################

void Ohm ()
{
    int A;
    float Vol, Cor, Res, Z;

    printf("Que valor es su incognita?\n");
    printf("1- Voltaje (V = I * R)\n");
    printf("2- Corriente (I = V / R)\n");
    printf("3- Resistencia (R = V / I)\n");
    printf("4- Tengo varias incognitas (Explicacion)\n");
    printf("\n... ");
    scanf("%d", &A);

    if (A==1) // Calcular Voltaje
    {
        printf("Ingrese Corriente (I) en Amperes: ");
        scanf("%f", &Cor);
        printf("Ingrese Resistencia (R) en Ohms: ");
        scanf("%f", &Res);
    
        Z = Cor * Res;
        printf(">> El Voltaje es: %.2f V\n", Z); 
    }
    else if (A==2) // Calcular Corriente
    {
        printf("Ingrese Voltaje (V) en Volts: ");
        scanf("%f", &Vol);
        printf("Ingrese Resistencia (R) en Ohms: ");
        scanf("%f", &Res);
        
        if (Res == 0) 
        {
            printf("Error: La resistencia no puede ser 0 (cortocircuito).\n");
        } else 
        {
            Z = Vol / Res;
            printf(">> La Corriente es: %.2f A\n", Z);         
        }
    }
    else if (A==3) // Calcular Resistencia
    {
        printf("Ingrese Voltaje (V) en Volts: ");
        scanf("%f", &Vol);
        printf("Ingrese Corriente (I) en Amperes: ");
        scanf("%f", &Cor);
    
        if (Cor == 0) 
        {
             printf("Error: La corriente no puede ser 0 para calcular resistencia.\n");
        } else 
        {
            Z = Vol / Cor;
            printf(">> La Resistencia es: %.2f Ohms\n", Z);         
        }
    }
    else if (A==4)
    {
        Explicar();
    }
    else
    {
        printf("Opcion invalida\n");
    }
}

//###################################################################################################################
//####################### FUNCION EXPLIACAR #########################################################################
//###################################################################################################################
void Explicar ()
{
    printf("Bueno, vamos de a poco.\n");
    printf("La Ley de Ohm establece que la intensidad de corriente (I)\n");
    printf("en un circuito es directamente proporcional al voltaje (V)\n");
    printf("e inversamente proporcional a la resistencia (R).\n");
    printf("-----------------------------\n");
    printf("   Fórmulas: V = I * R  |  I = V / R  |  R = V / I\n");
    printf("-----------------------------\n");
}

//###################################################################################################################
//################## FUNCION LEY DE KIRCHHOFF #######################################################################
//###################################################################################################################

void Kirchhoff()
{
    int op;
    int i, n; //Contadores
    float Fuente, Caida, SumaCaidas, Restante; //Variables para Voltaje
    float I_Entrada, I_Salida, SumaSalidas;    //Variables para Corriente

    printf("¿Qué Ley de Kirchhoff deseas aplicar?\n");
    printf("1- Ley de Voltajes (Lazos/Mallas) -> Para calcular caídas de tensión\n");
    printf("2- Ley de Corrientes (Nodos) -> Para calcular distribución de corriente\n");
    printf("\nOpción: ");
    scanf("%d", &op);

    if (op == 1) // --- LEY DE VOLTAJES (KVL) ---
    {
        //LOGICA: V_fuente - V_r1 - V_r2 ... = 0
        SumaCaidas = 0;
        
        printf("\n--- LEY DE VOLTAJES DE KIRCHHOFF ---\n");
        printf("Ingrese el Voltaje Total de la Fuente (V): ");
        scanf("%f", &Fuente);

        printf("¿Cuántos componentes (resistencias/leds) consumen voltaje?: ");
        scanf("%d", &n);

        printf("Vamos a ingresar las caídas de tensión conocidas.\n");
        printf("(Si hay una que NO sabes, ingresa 0 para calcularla al final)\n");

        for(i = 0; i < n; i++)
        {
            printf("Ingrese voltaje en el componente %d: ", i+1);
            scanf("%f", &Caida);
            SumaCaidas = SumaCaidas + Caida;
        }

        Restante = Fuente - SumaCaidas;

        printf("\n---------------- RESULTADOS ----------------\n");
        if (Restante == 0)
        {
            printf(">> El circuito está EQUILIBRADO (La suma de caídas iguala a la fuente).\n");
        }
        else if (Restante > 0)
        {
            printf(">> Faltan caer %.2f Volts en el circuito.\n", Restante);
            printf("   (Ese es el voltaje del componente que te faltaba averiguar)\n");
        }
        else //Si es negativo
        {
            printf(">> ¡CUIDADO! Las caídas superan a la fuente por %.2f Volts.\n", Restante * -1);
            printf("   Esto es físicamente imposible en un circuito simple.\n");
            printf("   Revisa tus mediciones.\n");
        }
    }
    else if (op == 2) // --- LEY DE CORRIENTES (KCL) ---
    {
        //LÓGICA: I_entra = I_sale1 + I_sale2 ...
        SumaSalidas = 0;

        printf("\n--- LEY DE CORRIENTES DE KIRCHHOFF ---\n");
        printf("Imagina un punto (nodo) donde un cable se divide en varios.\n");
        
        printf("Ingrese la Corriente Total que ENTRA al nodo (Amperes): ");
        scanf("%f", &I_Entrada);

        printf("¿En cuántos cables se divide la salida?: ");
        scanf("%d", &n);

        printf("Ingrese la corriente de los caminos conocidos (ponga 0 si es la incógnita):\n");

        for(i = 0; i < n; i++)
        {
            printf("Corriente en el camino de salida %d: ", i+1);
            scanf("%f", &I_Salida);
            SumaSalidas = SumaSalidas + I_Salida;
        }

        Restante = I_Entrada - SumaSalidas;

        printf("\n---------------- RESULTADOS ----------------\n");
        if (Restante > 0)
        {
            printf(">> Por el camino que falta (incógnita) circulan: %.2f A\n", Restante);
        }
        else if (Restante == 0)
        {
            printf(">> Toda la corriente está contabilizada.\n");
        }
        else
        {
            printf(">> Error: Salen %.2f A más de los que entran.\n", Restante * -1);
            printf("   ¡Estás creando energía de la nada! Revisa los valores.\n");
        }
    }
    else
    {
        printf("Opción no válida.\n");
    }
}

//###################################################################################################################
//################## FUNCION THEVENIN (DIVISOR DE VOLTAJE) ##########################################################
//###################################################################################################################

void Thevenin()
{
    float Vin, R1, R2, RLoad;
    float Vth, Rth;
    float Vout_Load, I_Load;
    char opcion;

    printf("\n--- TEOREMA DE THEVENIN ---\n");
    printf("Este calculador convierte un circuito divisor de voltaje\n");
    printf("en su Circuito Equivalente de Thevenin.\n\n");

    printf("Ingrese el Voltaje de la Fuente (Vin): ");
    scanf("%f", &Vin);

    printf("Ingrese el valor de R1 (Serie con fuente): ");
    scanf("%f", &R1);

    printf("Ingrese el valor de R2 (Paralelo a la salida): ");
    scanf("%f", &R2);

    // Vth es el voltaje en R2 (Divisor de voltaje)
    // Vth = Vin * (R2 / (R1 + R2))
    Vth = Vin * (R2 / (R1 + R2));

    // Rth es R1 en paralelo con R2 (Visto desde A-B con fuente en corto)
    // Rth = (R1 * R2) / (R1 + R2)
    Rth = (R1 * R2) / (R1 + R2);

    printf("\n--------------------------------------------\n");
    printf(">> RESULTADOS DEL EQUIVALENTE THEVENIN:\n");
    printf("--------------------------------------------\n");
    printf("1. Voltaje de Thevenin (Vth): %.2f V\n", Vth);
    printf("2. Resistencia de Thevenin (Rth): %.2f Ohms\n", Rth);
    printf("--------------------------------------------\n");
    printf("Esto significa que todo tu circuito anterior se comporta igual\n");
    printf("que una batería de %.2fV con una resistencia de %.2f Ohms.\n", Vth, Rth);

    //Simular Carga
    // Esto es para enseñar por que baja el voltaje cuando conectas algo.
    printf("\n¿Deseas conectar una Resistencia de Carga (RL) entre A y B? (s/n): ");
    while (getchar() != '\n'); 
    scanf("%c", &opcion);

    if (opcion == 's' || opcion == 'S')
    {
        printf("Ingrese el valor de la Carga (RL) en Ohms: ");
        scanf("%f", &RLoad);

        // Calculo con el circuito equivalente
        // I_Load = Vth / (Rth + RLoad)
        I_Load = Vth / (Rth + RLoad);
        Vout_Load = I_Load * RLoad;

        printf("\n>> AL CONECTAR LA CARGA:\n");
        printf(" - La corriente que circula (IL) es: %.4f A (%.2f mA)\n", I_Load, I_Load * 1000);
        printf(" - El voltaje real que le llega a la carga (VL) es: %.2f V\n", Vout_Load);
        
        if (Vout_Load < Vth * 0.9) 
        {
            printf("\n[NOTA]: El voltaje cayó significativamente respecto al Vth.\n");
            printf("Esto pasa porque tu Rth (%.2f) es alta comparada con tu carga.\n", Rth);
        }
    }
}

//###################################################################################################################
//################## FUNCION RESISTENCIA SERIE #########################################################################
//###################################################################################################################

//Funcion RSERIE

int RSerie ()
{
    int RCant;
    float RTotal = 0;
    float RSum;
    int i;
    float * valoresGuardados = NULL;

    printf("Ingrese cuantas Resistencias tiene en SERIE: ");
    scanf("%d", &RCant); 

    if (RCant < 2)
    {
        printf("Necesitamos al menos 2 para poder sumar.\nTe lo explico con manzanas?\n");
        return 1;
    }
    
    valoresGuardados = (float*) malloc (RCant * sizeof (float));
    if (valoresGuardados == NULL)
    {
        printf("No hay memoria suficiente");
        return 1;
    }    

    for (i = 0; i < RCant; i++)
    {
        printf("Ingrese el valor R%d: ", i+1);
        scanf("%f", &RSum);
        
        valoresGuardados[i] = RSum; 
        
        RTotal = RTotal + RSum;
    }
    
    printf("\n>> Su Resistencia Total es de %.2f Ohms\n", RTotal);

    printf("Valores ingresados: ");
    for (i=0; i < RCant; i++)
    {
        printf("%.2f | ", valoresGuardados[i]);
    }
    printf("\n");

    free (valoresGuardados);
    
    return 0;
}

//###################################################################################################################
//################## FUNCION RESISTENCIA PARALELO #########################################################################
//###################################################################################################################

//Funcion RPARALELO

int RParalelo()
{
    int RCant;
    float RTotal = 0; //Acumulador de conductancia
    float RSum;
    int i;

    printf("Ingrese cuantas Resistencias tiene en PARALELO: ");
    scanf("%d", &RCant);

    if (RCant < 2)
    {
        printf("Necesitamos al menos 2 para calcular paralelo.\n");
        return 1;
    }

    for (i = 0; i < RCant; i++)
    {
        printf("Ingrese el valor de R%d: ", i + 1);
        scanf("%f", &RSum);
        
        if(RSum == 0) 
        {
            printf("Error: Resistencia no puede ser 0 en paralelo.\n");
            return 1;
        }
        RTotal = RTotal + (1.0 / RSum);
    }

    RTotal = 1.0 / RTotal; 
    
    printf("Su Resistencia Equivalente es: %.2f Ohms\n", RTotal);
    return 0;
}

//###################################################################################################################
//################## FUNCION CAPACITORES ############################################################################
//###################################################################################################################

void Capacitores()
{
    int opcion, n, i;
    float C_val, C_total;
    float R_val, Tiempo;

    printf("\n--- CÁLCULOS DE CAPACITANCIA ---\n");
    printf("1- Capacitores en Serie (Suma de inversas)\n");
    printf("2- Capacitores en Paralelo (Suma directa)\n");
    printf("3- Constante de Tiempo RC (Carga/Descarga)\n");
    printf("\nOpción: ");
    scanf("%d", &opcion);

    if (opcion == 1) // --- SERIE ---
    {
        printf("\n[NOTA]: En SERIE, la capacidad total disminuye (como resistencias en paralelo).\n");
        printf("Formula: 1 / (1/C1 + 1/C2 + ...)\n");
        
        printf("¿Cuántos capacitores hay en serie?: ");
        scanf("%d", &n);
        
        if (n < 2) 
        {
            printf("Se necesitan al menos 2 para una serie.\n");
            return;
        }

        C_total = 0;
        for (i = 0; i < n; i++)
        {
            printf("Valor del Capacitor %d (misma unidad para todos): ", i+1);
            scanf("%f", &C_val);
            if (C_val == 0) 
            {
                printf("Error: Un capacitor no puede ser 0.\n");
                return;
            }
            C_total += (1.0 / C_val);
        }
        C_total = 1.0 / C_total;
        printf(">> Capacitancia Equivalente: %.2f (mismas unidades)\n", C_total);
    }
    else if (opcion == 2) // --- PARALELO ---
    {
        printf("\n[NOTA]: En PARALELO, la capacidad se suma (se hace más grande).\n");
        printf("Formula: C1 + C2 + ...\n");

        printf("¿Cuántos capacitores hay en paralelo?: ");
        scanf("%d", &n);

        C_total = 0;
        for (i = 0; i < n; i++)
        {
            printf("Valor del Capacitor %d: ", i+1);
            scanf("%f", &C_val);
            C_total += C_val;
        }
        printf(">> Capacitancia Equivalente: %.2f (mismas unidades)\n", C_total);
    }
    else if (opcion == 3) // --- TIEMPO RC ---
    {
        printf("\n--- CONSTANTE DE TIEMPO (Tau) ---\n");
        printf("Calcula cuánto tarda en cargarse un capacitor a través de una resistencia.\n");
        
        printf("Ingrese Resistencia (en OHMS): ");
        scanf("%f", &R_val);

        printf("Ingrese Capacitancia (en MICROFARADIOS uF): ");
        scanf("%f", &C_val);

        Tiempo = R_val * (C_val / 1000000.0);

        printf("\nRESULTADOS:\n");
        printf(">> 1 Tau (63%% de carga): %.4f Segundos\n", Tiempo);
        printf(">> 5 Tau (99%% de carga - Total): %.4f Segundos\n", Tiempo * 5);
        
        if (Tiempo * 5 < 0.1) 
        {
            printf("(Es un parpadeo muy rápido, casi invisible al ojo)\n");
        } else if (Tiempo * 5 > 1.0) 
        {
            printf("(Es un tiempo claramente visible, bueno para un LED)\n");
        }
    }
    else
    {
        printf("Opción no valida.\n");
    }
}

//###################################################################################################################
//################## DECODIFICADOR DE COLORES (COMPLETO CON TOLERANCIA) #############################################
//###################################################################################################################

void ColoresResistencia()
{
    int cantBandas;
    int d1, d2, d3 = 0;
    int multIdx;        //indice Multiplicador
    int tolIdx;         //indice Tolerancia
    double valor;
    double tolerancia = 0;
    
    double multiplicadores[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

    printf("\n--- DECODIFICADOR DE RESISTENCIAS ---\n");
    
    //PREGUNTAR CANTIDAD DE BANDAS
    do 
    {
        printf("¿Tu resistencia tiene 4 o 5 bandas?\n");
        printf("Opción: ");
        scanf("%d", &cantBandas);
    } 
    while(cantBandas != 4 && cantBandas != 5);

    printf("\n--- REFERENCIA DE COLORES ---\n");
    int i;
    for(i=0; i<=9; i++) 
    {
        printf("%d:", i);
        ImprimirNombreColor(i);
        printf(" ");
        if (i==4) printf("\n"); 
    }
    printf("\n(Para Tolerancia: 10=Plata, 11=Oro)\n");
    printf("-----------------------------\n");

    //PEDIR DIGITOS
    
    // BANDA 1
    do 
    {
        printf("\nIngrese color BANDA 1 (Dígito): ");
        scanf("%d", &d1);
    } 
    while(d1 < 0 || d1 > 9);

    // BANDA 2
    do 
    {
        printf("Ingrese color BANDA 2 (Dígito): ");
        scanf("%d", &d2);
    } 
    while(d2 < 0 || d2 > 9);

    // BANDA 3 (Dígito si es de 5 bandas, o Multiplicador si es de 4)
    if (cantBandas == 5)
    {
        do 
        {
            printf("Ingrese color BANDA 3 (3er Dígito): ");
            scanf("%d", &d3);
        } 
        while(d3 < 0 || d3 > 9);
        
        printf("Ingrese color BANDA 4 (Multiplicador): ");
    }
    else 
    {
        printf("Ingrese color BANDA 3 (Multiplicador): ");
    }

    // PEDIR MULTIPLICADOR
    do 
    {
        scanf("%d", &multIdx);
        if (multIdx > 7 || multIdx < 0) printf("Multiplicador estándar (0-7). Intente de nuevo: ");
    } 
    while(multIdx < 0 || multIdx > 7);

    // PEDIR TOLERANCIA (ULTIMA BANDA)
    if (cantBandas == 4) printf("Ingrese color BANDA 4 (Tolerancia):\n");
    else printf("Ingrese color BANDA 5 (Tolerancia):\n");
    
    printf("  [1=Marrón(1%%), 2=Rojo(2%%), 5=Verde(0.5%%), 10=Plata(10%%), 11=Oro(5%%)]\n  Color: ");
    scanf("%d", &tolIdx);

    switch(tolIdx) 
    {
        case 1: tolerancia = 1; break;  // Marrón
        case 2: tolerancia = 2; break;  // Rojo
        case 5: tolerancia = 0.5; break; // Verde
        case 6: tolerancia = 0.25; break; // Azul
        case 7: tolerancia = 0.1; break;  // Violeta
        case 10: tolerancia = 10; break; // Plata
        case 11: tolerancia = 5; break;  // Oro
        default: 
            tolerancia = 20;
            printf("(Color no estándar, asumiendo 20%%)\n");
            break;
    }

    // CALCULOS
    if (cantBandas == 4)
        valor = (d1 * 10 + d2) * multiplicadores[multIdx];
    else
        valor = (d1 * 100 + d2 * 10 + d3) * multiplicadores[multIdx];

    double minVal = valor - (valor * (tolerancia/100.0));
    double maxVal = valor + (valor * (tolerancia/100.0));

    // MOSTRAR RESULTADO
    printf("\n********************************************\n");
    printf("  VALOR NOMINAL: ");
    
    if (valor >= 1000000) printf("%.2f MOhms", valor / 1000000.0);
    else if (valor >= 1000) printf("%.2f kOhms", valor / 1000.0);
    else printf("%.0f Ohms", valor);
    
    printf(" (+/- %.1f%%)\n", tolerancia);
    printf("********************************************\n");
    printf("Rango real medible: %.2f a %.2f Ohms\n", minVal, maxVal);
    printf("********************************************\n");
}

//###################################################################################################################
//################## VISUALIZADOR DE PINOUTS ########################################################################
//###################################################################################################################

void VerPinout(int chipID)
{
    if (chipID == 1) // --- NE555 ---
    {
        printf("\n--- PINOUT NE555 (Visto desde arriba) ---\n");
        printf("      +--U--+\n");
        printf(" GND -|1   8|- VCC (+)\n");
        printf("TRIG -|2   7|- DISCH\n");
        printf(" OUT -|3   6|- THRES\n");
        printf(" RST -|4   5|- CTRL\n");
        printf("      +-----+\n");
        
        printf("\nEXPLICACIÓN DE PINES:\n");
        printf("1. GND (Tierra): Conectar al negativo de la batería.\n");
        printf("2. TRIGGER (Disparo): Activa el ciclo cuando recibe < 1/3 del voltaje.\n");
        printf("3. OUTPUT (Salida): Aquí conectas tu LED o Parlante (Salen pulsos).\n");
        printf("4. RESET: Debe ir al POSITIVO para que el chip funcione. Si toca tierra, se apaga.\n");
        printf("5. CONTROL: Usualmente se pone un capacitor pequeño (10nF) a tierra para estabilidad.\n");
        printf("6. THRESHOLD (Umbral): Termina el ciclo cuando el voltaje supera 2/3.\n");
        printf("7. DISCHARGE (Descarga): Ayuda a descargar el capacitor de tiempo.\n");
        printf("8. VCC (+): Alimentación positiva (4.5V a 15V).\n");
        printf("----------------------------------------------------\n");
    }
    else if (chipID == 2) // --- LM741 / LM358 (OpAmp Generico de 8 pines) ---
    {
        printf("\n--- PINOUT LM741 (OpAmp Simple) ---\n");
        printf("      +--U--+\n");
        printf("NC/OF-|1   8|- NC\n");
        printf(" IN(-)-|2   7|- VCC (+)\n");
        printf(" IN(+)-|3   6|- OUT\n");
        printf(" VEE(-)|4   5|- OFF/NC\n");
        printf("      +-----+\n");

        printf("\nEXPLICACIÓN DE PINES:\n");
        printf("2. INVERSORA (-): La señal que entra aquí sale invertida.\n");
        printf("3. NO INVERSORA (+): La señal aquí mantiene su fase.\n");
        printf("4. VEE (-): Alimentación negativa o Tierra (GND) en circuitos simples.\n");
        printf("6. OUTPUT: Aquí sale tu señal amplificada.\n");
        printf("7. VCC (+): Alimentación positiva.\n");
        printf("----------------------------------------------------\n");
        printf("NOTA: Si usas un LM358 (Doble), el pinout cambia:\n");
        printf("Pin 4 es GND y Pin 8 es VCC. ¡Revisa tu chip!\n");
    }
}

//###################################################################################################################
//################## MENU DE MICROCHIPS #############################################################################
//###################################################################################################################

void Microchips()
{
    int opcionChip, subMenu;
    
    // Variables 555
    float R1, R2, C, Frecuencia, Duty, Periodo;
    // Variables OpAmp
    float R_in, R_feed, Vin, Vout, Ganancia;

    printf("\n--- LABORATORIO DE MICROCHIPS ---\n");
    printf("Selecciona el chip:\n");
    printf("1- NE555 (Oscilador)\n");
    printf("2- LM741 / OpAmp (Amplificador)\n");
    printf("3- Volver\n");
    printf("Opción: ");
    scanf("%d", &opcionChip);

    if (opcionChip == 3) return;

    // --- SUB MENU: ¿QUE HACER CON EL CHIP? ---
    printf("\n¿Qué deseas hacer con este chip?\n");
    printf("1- Ver Pinout (Explicación de patas)\n");
    printf("2- Realizar Cálculos\n");
    printf("Opción: ");
    scanf("%d", &subMenu);

    if (subMenu == 1)
    {
        VerPinout(opcionChip);
        return;
    }
    
    if (opcionChip == 1) // --- CALCULOS NE555 ---
    {
        printf("\n--- CÁLCULO NE555 ASTABLE ---\n");
        printf("Configuración típica: R1 a VCC, R2 al medio, C a Tierra.\n");
        
        printf("Ingrese R1 (Ohms): ");
        scanf("%f", &R1);
        printf("Ingrese R2 (Ohms): ");
        scanf("%f", &R2);
        printf("Ingrese C (MicroFaradios): ");
        scanf("%f", &C);

        float C_Farads = C / 1000000.0;
        Frecuencia = 1.44 / ((R1 + 2 * R2) * C_Farads);
        Periodo = 1.0 / Frecuencia;
        Duty = (R1 + R2) / (R1 + 2 * R2) * 100;

        printf("\n>>> RESULTADOS:\n");
        printf("Frecuencia: %.2f Hz | Periodo: %.4fs | Duty: %.1f %%\n", Frecuencia, Periodo, Duty);
    }
    else if (opcionChip == 2) // --- CALCULOS OPAMP ---
    {
        printf("\n--- CÁLCULO GANANCIA (NO INVERSOR) ---\n");
        printf("Formula: G = 1 + (R_feed / R_in)\n");

        printf("Ingrese R_in (Ohms): ");
        scanf("%f", &R_in);
        printf("Ingrese R_feed (Ohms): ");
        scanf("%f", &R_feed);
        printf("Ingrese Voltaje de Entrada: ");
        scanf("%f", &Vin);

        Ganancia = 1 + (R_feed / R_in);
        Vout = Vin * Ganancia;

        printf("\n>>> RESULTADOS:\n");
        printf("Ganancia: %.2f x | Salida: %.2f V\n", Ganancia, Vout);
    }
}

//###################################################################################################################
//################## CALCULADORA DE LEDS ############################################################################
//###################################################################################################################

void CalcularLED()
{
    float Vfuente, Vled, Iled, Rcal, Potencia;
    int colorOption;

    printf("\n--- CALCULADORA DE RESISTENCIA PARA LED ---\n");
    printf("   (A)      (K)\n");
    printf("   +|        |-\n");
    printf("   ( )-------( )  [LED]\n");
    printf("    |   / /   |\n\n");

    //Pedir voltaje de la fuente
    printf("Ingrese el Voltaje de su Fuente (V): ");
    scanf("%f", &Vfuente);

    //Determinar voltaje del LED según color
    printf("\nSeleccione el color del LED (para estimar su voltaje):\n");
    printf("1- Rojo (Estándar) [~2.0V]\n");
    printf("2- Verde / Amarillo [~2.2V]\n");
    printf("3- Azul / Blanco / UV [~3.2V]\n");
    printf("4- Otro (Ingresar voltaje manual)\n");
    printf("Opción: ");
    scanf("%d", &colorOption);

    switch(colorOption) 
    {
        case 1: Vled = 2.0; break;
        case 2: Vled = 2.2; break;
        case 3: Vled = 3.2; break;
        case 4: 
            printf("Ingrese el voltaje del LED (Vf): ");
            scanf("%f", &Vled);
            break;
        default: Vled = 2.0; printf("(Opción no valida, asumiendo Rojo 2V)\n"); break;
    }

    if (Vfuente <= Vled) 
    {
        printf("\n[ERROR] ¡El voltaje de la fuente (%.1fV) es muy bajo para este LED (%.1fV)!\n", Vfuente, Vled);
        printf("El LED no encenderá.\n");
        return;
    }

    printf("\nIngrese la corriente deseada en miliamperios (mA):\n");
    printf("(Estándar: 20mA, Bajo brillo: 10mA, Alto brillo: 30mA)\n");
    printf("Corriente: ");
    scanf("%f", &Iled);

    // Cálculo: R = (Vcc - Vf) / I
    // Convertir mA a Amperes dividiendo por 1000
    Rcal = (Vfuente - Vled) / (Iled / 1000.0);
    
    // Calculo de Potencia de la Resistencia: P = I^2 * R
    Potencia = (Iled/1000.0) * (Iled/1000.0) * Rcal;

    printf("\n>>> RESULTADOS PARA TU LED:\n");
    printf("----------------------------------------\n");
    printf("Resistencia necesaria: %.2f Ohms\n", Rcal);
    printf("Valor comercial cercano: %.0f o %.0f Ohms\n", Rcal * 0.95, Rcal * 1.05);
    printf("Potencia disipada: %.4f Watts\n", Potencia);
    printf("----------------------------------------\n");
}

//###################################################################################################################
//################## LEY DE WATT (POTENCIA) #########################################################################
//###################################################################################################################

void LeyWatt()
{
    int op;
    float V, I, R, P;

    printf("\n--- LEY DE WATT (POTENCIA Y CALOR) ---\n");
    printf("Determina cuánta energía consume un componente y si se va a quemar.\n");
    printf("Fórmulas: P = V*I  |  P = I²*R  |  P = V²/R\n\n");
    
    printf("¿Qué datos conoces?\n");
    printf("1- Voltaje (V) y Corriente (I)\n");
    printf("2- Corriente (I) y Resistencia (R)\n");
    printf("3- Voltaje (V) y Resistencia (R)\n");
    printf("Opción: ");
    scanf("%d", &op);

    P = 0;

    if (op == 1) 
    {
        printf("Ingrese Voltaje (V): "); scanf("%f", &V);
        printf("Ingrese Corriente (A): "); scanf("%f", &I);
        P = V * I;
    }
    else if (op == 2) 
    {
        printf("Ingrese Corriente (A): "); scanf("%f", &I);
        printf("Ingrese Resistencia (Ohms): "); scanf("%f", &R);
        P = I * I * R;
    }
    else if (op == 3) 
    {
        printf("Ingrese Voltaje (V): "); scanf("%f", &V);
        printf("Ingrese Resistencia (Ohms): "); scanf("%f", &R);
        if (R == 0) { printf("Error: Resistencia 0.\n"); return; }
        P = (V * V) / R;
    }
    else 
    {
        printf("Opción no válida.\n");
        return;
    }

    printf("\n>>> RESULTADO:\n");
    printf("Potencia: %.4f Watts (%.2f mW)\n", P, P * 1000);

    printf("\nRECOMENDACIÓN DE COMPONENTE:\n");
    if (P < 0.125) printf("-> Puedes usar una resistencia pequeña de 1/8 Watt.\n");
    else if (P < 0.25) printf("-> Usa una resistencia común de 1/4 Watt.\n");
    else if (P < 0.5) printf("-> Usa una resistencia de 1/2 Watt.\n");
    else if (P < 1.0) printf("-> ¡Cuidado! Necesitas resistencia de 1 Watt (Son grandecitas).\n");
    else printf("-> ¡ALERTA! Esto calienta mucho (>1W). Usa resistencia de cerámica/cemento.\n");
}

//###################################################################################################################
//################## CALCULADORA DE AUTONOMIA (BATERIAS) ############################################################
//###################################################################################################################

void AutonomiaBaterias()
{
    float mAh, mA, HorasTeoricas, HorasReales;
    int h_final, m_final;

    printf("\n--- CALCULADORA DE AUTONOMÍA DE BATERÍAS ---\n");
    printf("Calcula cuánto tiempo durará encendido tu proyecto.\n");
    
    //Pedir Capacidad
    printf("\nIngrese la CAPACIDAD de la batería en mAh:\n");
    printf("(Ej: Una pila común AA tiene ~2000 mAh, una LiPo de celular ~3000 mAh)\n");
    printf("Capacidad (mAh): ");
    scanf("%f", &mAh);

    //Pedir Consumo
    printf("\nIngrese el CONSUMO del circuito en mA:\n");
    printf("(Si no lo sabes, usa un multímetro en serie o suma el consumo de tus componentes)\n");
    printf("Consumo (mA): ");
    scanf("%f", &mA);

    if (mA <= 0) 
    {
        printf("Error: El consumo no puede ser 0 o negativo.\n");
        return;
    }

    //Calculos
    HorasTeoricas = mAh / mA;
    HorasReales = HorasTeoricas * 0.8;

    h_final = (int)HorasReales;
    m_final = (int)((HorasReales - h_final) * 60);

    printf("\n>>> RESULTADOS ESTIMADOS:\n");
    printf("----------------------------------------\n");
    printf("Tiempo Teórico (Ideal): %.2f Horas\n", HorasTeoricas);
    printf("----------------------------------------\n");
    printf("TIEMPO REAL SEGURO (Factor 0.8):\n");
    printf(">> %d Horas y %d Minutos <<\n", h_final, m_final);
    printf("----------------------------------------\n");
    
    if (HorasReales < 1.0) 
    {
        printf("[CONSEJO] Tu batería dura muy poco. Considera:\n");
        printf("1. Aumentar la capacidad (mAh).\n");
        printf("2. Usar modos de 'Sleep' en tu microcontrolador.\n");
    } else if (HorasReales > 24.0) 
    {
        printf("[CONSEJO] ¡Excelente autonomía! Dura más de un día completo.\n");
    }
}

//###################################################################################################################
//################## DIVISOR DE TENSIÓN INVERSO #####################################################################
//###################################################################################################################

void DivisorInverso()
{
    float Vin, Vout;
    float R1, R2_user;
    int opcion;
    
    float R2_comunes[] = {1000, 2200, 4700, 10000, 100000};
    int i;

    printf("\n--- DIVISOR DE TENSIÓN (CÁLCULO DE RESISTENCIAS) ---\n");
    printf("Calcula qué resistencias necesitas para bajar un voltaje.\n\n");

    printf("        Vin (+)\n");
    printf("         |\n");
    printf("       [ R1 ]  (Resistencia Superior)\n");
    printf("         |\n");
    printf("         +---------> Vout (Voltaje deseado)\n");
    printf("         |\n");
    printf("       [ R2 ]  (Resistencia Inferior/A Tierra)\n");
    printf("         |\n");
    printf("        GND\n\n");

    printf("Ingrese el Voltaje de Entrada (Vin): ");
    scanf("%f", &Vin);

    printf("Ingrese el Voltaje Deseado (Vout): ");
    scanf("%f", &Vout);

    if (Vout >= Vin) 
    {
        printf("\n[ERROR] Imposible. Un divisor resistivo solo puede BAJAR el voltaje.\n");
        return;
    }

    while (getchar() != '\n'); 

    printf("\nSeleccione el modo de cálculo:\n");
    printf("1- Sugerirme pares comunes (Basado en R2 estándar)\n");
    printf("2- Yo tengo una resistencia R2, calcula R1\n");
    printf("Opción: ");

    scanf("%d", &opcion);

    printf("\n>>> RESULTADOS:\n");
    printf("------------------------------------------------\n");

    if (opcion == 1)
    {
        printf("Probando con valores comunes de R2...\n\n");
        
        for(i = 0; i < 5; i++) 
        {
            float R2_temp = R2_comunes[i];
            
            float R1_calc = R2_temp * ((Vin / Vout) - 1.0);
            
            printf("Opción %d: Si usas R2 = %.0f Ohms -> Necesitas R1 = %.2f Ohms\n", 
                   i+1, R2_temp, R1_calc);
        }
        printf("\n(Busca en tu cajón el valor de R1 más cercano)\n");
    }
    else if (opcion == 2)
    {
        printf("Ingrese el valor de la resistencia R2 que tiene (Ohms): ");
        scanf("%f", &R2_user);
        
        if (R2_user <= 0) 
        { 
            printf("Error: Resistencia inválida.\n"); return;
        }

        R1 = R2_user * ((Vin / Vout) - 1.0);

        printf("\nPara lograr %.2fV con tu resistencia de %.0f Ohms:\n", Vout, R2_user);
        printf(">> NECESITAS UNA R1 DE: %.2f Ohms\n", R1);
        printf("------------------------------------------------\n");
        printf("[Tip]: Si usas una R1 comercial cercana, verifica\n");
        printf("el voltaje real con la opción 3 del menú principal (Thevenin).\n");
    }
    
    printf("------------------------------------------------\n");
}