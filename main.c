/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "rover.h"

#define MAXCHAR 100


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

    int aux = 2; //variavel criada para fazer a leitura dos dados de entrada. Valor escolhido foi o 2 para que o codigo não busque espaço nos dados de input

    while (fgets(str, MAXCHAR, fp) != NULL) {
        if (aux % 2 == 0) {
            for (int i = 0; i < sizeof(str); ++i) { //fazendo varredura dos dados de entrada
                if (str[i] != 32){
                    if (i == 0){
                        RoverRobot.x = str[i] - '0'; //atualiza a variavel do eixo x da struct do Rover. A struct foi escolhida pois agrupa variaveis do mesmo tipo de dado
                    } else if (i == 2) {
                        RoverRobot.y = str[i] - '0'; //atualiza a variavel do eixo y da struct do Rover.
                    } else if (i == 4) {
                        RoverRobot.orientation = str[i]; //atualiza a variavel que armazena a orientacao do Rover
                    }
                }
            }
        } else {
            for (int j = 0; str[j] == 'L' || str[j] == 'R' || str[j] == 'M'; ++j) { //faz a varredura dos comandos de orientacao do Rover
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

            printf("%i %i %c\n\n", RoverRobot.x, RoverRobot.y, RoverRobot.orientation); //printa a posicao atualizada do Rover no eixo x e y, alem de sua orientacao

        }
        ++aux;
    }

    fclose(fp);

    return 0;

}
