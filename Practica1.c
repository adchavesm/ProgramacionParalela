#include <stdio.h>
#include <stdlib.h>

int ancho, alto;

void leerImagen(char *nombreArchivo);

void imprimirImagen(char R[ancho][alto], char G[ancho][alto], char B[ancho][alto]);

int main(int argc, char *argv[])
{
    leerImagen(argv[1]);
    return 0;
}

void leerImagen(char *nombreArchivo)
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r");
    char letra;
    int tipo, maxcolor;
    fscanf(archivo, "%c%d %d %d %d", &letra, &tipo, &ancho, &alto, &maxcolor);
    char R[ancho][alto], G[ancho][alto], B[ancho][alto];
    for (int i = 0; i < ancho; i++)
    {
        for (int j = 0; j < alto; j++)
        {
            fscanf(archivo, "%c%c%c", &R[i][j], &G[i][j], &B[i][j]);
        }
    }
    fclose(archivo);
    imprimirImagen(R, G, B);
}

void imprimirImagen(char R[ancho][alto], char G[ancho][alto], char B[ancho][alto])
{
    FILE *ap;
    ap = fopen("salida.ppm", "w");
    fprintf(ap, "P6\n%d %d\n255", ancho, alto);
    for (int i = 0; i < ancho; i++)
    {
        for (int j = 0; j < alto; j++)
        {
            fprintf(ap, "%c%c%c", R[i][j], G[i][j], B[i][j]);
        }
    }
    fclose(ap);
}