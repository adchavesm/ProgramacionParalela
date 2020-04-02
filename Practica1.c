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

    char Red[ancho][alto], Green[ancho][alto], Blue[ancho][alto];

    for (int i = 0; i < ancho; i++)
    {
        if (i == 0 || i==ancho-1)
        {
             for (int j = 0; j < alto; j++)
            {
                fprintf(ap, "AAA");
            }
        }else{
            for (int j = 0; j < alto; j++)
            {
                if (j == 0 || j==alto-1)
                {
                    fprintf(ap, "AAA");
                }else{
                double c11 = (double)R[i - 1][j - 1] * 0.0625;
                double c12 = (double)R[i - 1][j] * 0.125;
                double c13 = (double)R[i - 1][j + 1] * 0.0625;
                double c21 = (double)R[i][j - 1] * 0.125;
                double c22 = (double)R[i][j] * 0.25;
                double c23 = (double)R[i][j + 1] * 0.125;
                double c31 = (double)R[i + 1][j - 1] * 0.0625;
                double c32 = (double)R[i + 1][j] * 0.125;
                double c33 = (double)R[i + 1][j + 1] * 0.0625;
                double sumc = c11 + c12 + c13 + c21 + c22 + c23 + c31 + c32 + c33;
                int cc = (int)sumc;
                if(cc==0){
                    cc=1;
                }
                Red[i][j] = (char)cc;

                double m11 = (double)G[i - 1][j - 1] * 0.0625;
                double m12 = (double)G[i - 1][j] * 0.125;
                double m13 = (double)G[i - 1][j + 1] * 0.0625;
                double m21 = (double)G[i][j - 1] * 0.125;
                double m22 = (double)G[i][j] * 0.25;
                double m23 = (double)G[i][j + 1] * 0.125;
                double m31 = (double)G[i + 1][j - 1] * 0.0625;
                double m32 = (double)G[i + 1][j] * 0.125;
                double m33 = (double)G[i + 1][j + 1] * 0.0625;
                double summ = m11 + m12 + m13 + m21 + m22 + m23 + m31 + m32 + m33;
                int mm = (int)summ;
                if(mm==0){
                    cc=1;
                }
                Green[i][j] = (char)mm;

                double l11 = (double)B[i - 1][j - 1] * 0.0625;
                double l12 = (double)B[i - 1][j] * 0.125;
                double l13 = (double)B[i - 1][j + 1] * 0.0625;
                double l21 = (double)B[i][j - 1] * 0.125;
                double l22 = (double)B[i][j] * 0.25;
                double l23 = (double)B[i][j + 1] * 0.125;
                double l31 = (double)B[i + 1][j - 1] * 0.0625;
                double l32 = (double)B[i + 1][j] * 0.125;
                double l33 = (double)B[i + 1][j + 1] * 0.0625;
                double suml = l11 + l12 + l13 + l21 + l22 + l23 + l31 + l32 + l33;
                int ll = (int)suml;
                if(ll==0){
                    cc=1;
                }
                Blue[i][j] = (char)ll;
                printf("%d %d %d\n", Red[i][j], Green[i][j], Blue[i][j]);
                
                    fprintf(ap, "%c%c%c", Red[i][j], Green[i][j], Blue[i][j]);
                
                
                }
            
            }
        }
    }
    /*printf("%d %d %d \n",R[1][1], Green[1][1], Blue[1][1]);
    printf("%d %d %d \n",R[1][1], Green[1][1], Blue[1][1]);
    printf("%d %d %d \n",R[1][1], Green[1][1], Blue[1][1]);
    printf("%d %d %d \n",R[1][1], Green[1][1], Blue[1][1]);
    printf("%d %d %d \n",R[1][1], Green[1][1], Blue[1][1]);
    printf("%d %d %d \n",R[1][1], Green[1][1], Blue[1][1]);
    printf("%d %d %d \n",R[1][1], Green[1][1], Blue[1][1]);
    printf("%d %d %d \n",R[1][1], Green[1][1], Blue[1][1]);
    printf("%d %d %d \n",R[1][1], Green[1][1], Blue[1][1]);
    printf("\n\n");
    printf("%d %d %d \n",Red[1][1], Green[1][1], Blue[1][1]);*/
    fclose(ap);
}