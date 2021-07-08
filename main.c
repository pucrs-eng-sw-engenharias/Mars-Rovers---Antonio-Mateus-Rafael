/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "rover.h"

#define MAXCHAR 1024


int main() {

    int tamanhoX = 0;
    int tamanhoY = 0;

    //Declara arquivo
    FILE *fp;
    char str[MAXCHAR];
    char filename[MAXCHAR] = "..\\test_input.txt";

    struct rover RoverRobot;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo: %s", filename);
        return 1;
    }

    //lê o arquivo
    fgets(str, MAXCHAR, fp);
    tamanhoX = str[0] - '0';
    tamanhoY = str[2] - '0';

    int aux = 2;

    while (fgets(str, MAXCHAR, fp) != NULL) {
        if (aux % 2 == 0) {
            for (int i = 0; i < sizeof(str); ++i) {
                if (str[i] != 32){
                    if (i == 0){
                        RoverRobot.x = str[i] - '0';
                    } else if (i == 2) {
                        RoverRobot.y = str[i] - '0';
                    } else if (i == 4) {
                        RoverRobot.orientation = str[i];
                    }
                }
            }
        } else {
            for (int j = 0; str[j] == 'L' || str[j] == 'R' || str[j] == 'M'; ++j) {
                switch (str[j]) {
                    case 'L':
                        //Calculo de rotacao para esquerda
                        RoverRobot = rotateRover(RoverRobot, "L");
                        break;
                    case 'R':
                        //Calculo de rotacao para direita
                        RoverRobot = rotateRover(RoverRobot, "R");
                        break;
                    case 'M':
                        //Calculo de movimentacao
                        RoverRobot = moveRover(RoverRobot, tamanhoX, tamanhoY);
                        break;
                }
            }

            printf("%i %i %c\n\n", RoverRobot.x, RoverRobot.y, RoverRobot.orientation);

        }
        ++aux;
    }

    fclose(fp);

    return 0;

}
