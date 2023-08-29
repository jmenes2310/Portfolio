#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define NUMERO_ESTADO unsigned int

#define ESPACIO_BLANCO ' '
#define SALTO_LINEA '\n'
#define CARACTER_CENTINELA ','

#define Q0_INICIAL 0
#define Q1_TERMINAL 1
#define Q2_TERMINAL 2
#define Q3 3
#define Q4_TERMINAL 4
#define Q5_TERMINAL 5
#define Q6_RECHAZO 6

bool openTextFile(char *name, FILE **file)
{
    *file = fopen(name, "r");
    return *file != NULL;
}

void closeFile(FILE *file)
{
    fclose(file);
}

char readNextChar(FILE *file)
{
    char caracter = fgetc(file);
    // DE ESTA FORMA IGNORAMOS LOS ESPACIOS EN BLANCO Y LOS SALTOS DE LINEA
    if (caracter == ESPACIO_BLANCO || caracter == SALTO_LINEA)
    {
        return readNextChar(file);
    }
    return caracter;
}

void addCharToWord(char caracter, char **palabraActual, unsigned int *longitudPalabra)
{
    (*longitudPalabra)++;

    if (*palabraActual == NULL)
    {
        *palabraActual = malloc(sizeof(char));
        (*palabraActual)[0] = caracter;
    }
    else
    {
        *palabraActual = realloc(*palabraActual, sizeof(char) * (*longitudPalabra));
        (*palabraActual)[(*longitudPalabra) - 1] = caracter;
    }
}

bool esLetraHexa(char caracter)
{
    return (caracter >= 'a' && caracter <= 'f') || (caracter >= 'A' && caracter <= 'F');
}

int obtenerColumnaDeTransicion(char caracter, int estado)
{
    switch (estado)
    {
    case Q0_INICIAL:
    {

        if (caracter == '0')
            return 0;

        if (caracter >= '1' && caracter <= '9')
            return 1; // Puede ser 1 o 2

        return 3;
    }
    case Q1_TERMINAL:
    {
        if (caracter >= '0' && caracter <= '7')
            return 0; // Puede ser 0 o 1

        if (caracter == '8' || caracter == '9')
            return 2;

        // si esta entre a y F contando mayusculas y minusculas
        if (esLetraHexa(caracter))
            return 3;

        if (caracter == 'x' || caracter == 'X')
            return 4;

        return 5;
    }
    case Q2_TERMINAL:
    {
        if (caracter >= '0' && caracter <= '9')
            return 0;

        return 5;
    }
    case Q3:
    {
        if ((caracter >= '0' && caracter <= '9') || esLetraHexa(caracter))
            return 0;
        return 5;
    }
    case Q4_TERMINAL:
    {
        if ((caracter >= '0' && caracter <= '9') || esLetraHexa(caracter))
            return 0;
        return 5;
    }
    case Q5_TERMINAL:
    {
        if (caracter >= '0' && caracter <= '7')
            return 0;

        return 5;
    }
    case Q6_RECHAZO:
        return 5;
    }
}

bool esHexadecimal(int estado)
{
    return estado == Q4_TERMINAL;
}

bool esDecimal(int estado)
{
    return estado == Q2_TERMINAL;
}

bool esOctal(int estado)
{
    return estado == Q5_TERMINAL || estado == Q1_TERMINAL;
}

bool esRechazo(int estado){
    return estado == Q6_RECHAZO;
}

int main()
{
    FILE *file = NULL;
    FILE *salida = NULL;
    char *filename = "entrada.txt";
    char caracter;
    unsigned int longitudPalabra = 0;
    char *palabraActual = NULL;
    bool leerCaracter = true;

    NUMERO_ESTADO estadoActual = Q0_INICIAL;

    NUMERO_ESTADO tablaTransiciones[7][6] = {
        {Q1_TERMINAL, Q2_TERMINAL, Q2_TERMINAL, Q6_RECHAZO, Q6_RECHAZO, Q6_RECHAZO},
        {Q5_TERMINAL, Q5_TERMINAL, Q6_RECHAZO, Q6_RECHAZO, Q3, Q6_RECHAZO},
        {Q2_TERMINAL, Q2_TERMINAL, Q2_TERMINAL, Q6_RECHAZO, Q6_RECHAZO, Q6_RECHAZO},
        {Q4_TERMINAL, Q4_TERMINAL, Q4_TERMINAL, Q4_TERMINAL, Q6_RECHAZO, Q6_RECHAZO},
        {Q4_TERMINAL, Q4_TERMINAL, Q4_TERMINAL, Q4_TERMINAL, Q6_RECHAZO, Q6_RECHAZO},
        {Q5_TERMINAL, Q5_TERMINAL, Q6_RECHAZO, Q6_RECHAZO, Q6_RECHAZO, Q6_RECHAZO},
        {Q6_RECHAZO, Q6_RECHAZO, Q6_RECHAZO, Q6_RECHAZO, Q6_RECHAZO, Q6_RECHAZO}};

    bool fileOpened = openTextFile(filename, &file);


    if (!fileOpened)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    salida = fopen("salida.txt", "w");

    if(salida == NULL){
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // LEE CARACTER POR CARACTER
    caracter = readNextChar(file);
    while (leerCaracter)
    {
        if (caracter != CARACTER_CENTINELA && caracter != EOF)
        {
            // ACA DEBERIAMOS ANALIZAR EL CARACTER Y HACERLO PASAR POR EL AUTOMATA PARA TRANSICIONAR DE ESTADO

            int col = obtenerColumnaDeTransicion(caracter, estadoActual);
            estadoActual = tablaTransiciones[estadoActual][col];
            addCharToWord(caracter, &palabraActual, &longitudPalabra);
        }
        else
        {

            if(palabraActual == NULL){
                fwrite("λ NO RECONOCIDA\n", sizeof(char), strlen("λ NO RECONOCIDA\n"), salida);
            }

            addCharToWord('\0', &palabraActual, &longitudPalabra);

            fwrite(palabraActual, sizeof(char), strlen(palabraActual), salida);

            if (esHexadecimal(estadoActual))
            {
                fwrite(" HEXADECIMAL\n", sizeof(char), strlen(" HEXADECIMAL\n"), salida);
            }

            if (esDecimal(estadoActual))
            {
                fwrite(" DECIMAL\n", sizeof(char), strlen(" DECIMAL\n"), salida);
            }

            if (esOctal(estadoActual))
            {
                fwrite(" OCTAL\n", sizeof(char), strlen(" OCTAL\n"), salida);
            }

            if (esRechazo(estadoActual))
            {
                fwrite(" NO RECONOCIDA\n", sizeof(char), strlen(" NO RECONOCIDA\n"), salida);
            }

            // printf("%s %s\n", palabraActual, tipo); // EN VEZ DEL PRINT TENDRIA QUE GUARDAR LA LINEA EN UN ARCHIVO
            free(palabraActual); // LIBERA LA MEMORIA DE LA PALABRA LEIDA
            longitudPalabra = 0;
            palabraActual = NULL;
            estadoActual = Q0_INICIAL;

            // Si es el final del archivo, no lee mas caracteres
            leerCaracter = caracter != EOF;
        }
        if (leerCaracter)
        {
            caracter = readNextChar(file);
        }
    }
    
    closeFile(file);
    closeFile(salida);
    // PIDO QUE SE PRESIONE UNA TECLA PARA QUE NO SE CIERRE LA CONSOLA
    printf("Presione enter para terminar...");
    getchar();

    return 0;
}