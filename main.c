/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

#include <stdio.h>
 
#define MAXCHAR 1024
int main() {

    int tamanhoX=0;
    int tamanhoY=0;

    //Declara arquivo
    FILE *fp;
    char str[MAXCHAR];
    char filename[MAXCHAR] = ".\\TESTE.RAFAEL.txt";

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Não foi possível abrir o arquivo: %s",filename);
        return 1;
    }

    //lê o arquivo
    fgets(str, MAXCHAR, fp);
    tamanhoX = str[0]- '0';
    tamanhoY = str[2]- '0';
    printf(" %d %d \n",tamanhoX, tamanhoY);
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    fclose(fp);
    return 0;


}
