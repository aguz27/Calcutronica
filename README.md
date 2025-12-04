# Calcutrónica

Calculadora de electrónica en terminal escrita en C.
Actualmente funcional en modo CLI (Línea de comandos).

## Estructura del Proyecto
El código ha sido refactorizado para separar la lógica de la interfaz:
- `src/`: Código fuente (.c)
- `inc/`: Cabeceras y definiciones (.h)
- `bin/`: Ejecutables generados

## Compilación
El proyecto incluye un Makefile para facilitar la compilación.
```bash
make
./bin/Calcutronica

make run compila y ejecuta