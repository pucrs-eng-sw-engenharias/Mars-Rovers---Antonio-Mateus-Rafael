#include "validator.h"

struct rover { //variaveis criadas para armazenar as posicoes e orientacoes do Rover
    int x;
    int y;
    char orientation;
};

struct rover rotateRover(struct rover RoverRobot, char *side) { //recebe o comando de orientacao do Rover
    switch (RoverRobot.orientation) { //ao receber o comando de orientacao desejada do rover, escolhe a movimentacao com base na orientacao atual do rover
        case 'N':
            if (side == "L") { //caso a variavel seja L (movimento para a esquerda), o Rover tera orientacao para West
                RoverRobot.orientation = 'W';
            } else { //caso a variavel seja R (movimento para a direita), o Rover tera orientacao para East
                RoverRobot.orientation = 'E';
            }
            break;
        case 'S':
            if (side == "L") {
                RoverRobot.orientation = 'E';
            } else {
                RoverRobot.orientation = 'W';
            }
            break;
        case 'E':
            if (side == "L") { //caso a variavel seja L (movimento para a esquerda), o Rover tera orientacao para North
                RoverRobot.orientation = 'N';
            } else { //caso a variavel seja R (movimento para a direita), o Rover tera orientacao para South
                RoverRobot.orientation = 'S';
            }
            break;
        case 'W':
            if (side == "L") {
                RoverRobot.orientation = 'S';
            } else {
                RoverRobot.orientation = 'N';
            }
            break;
        default:
            RoverRobot.orientation = RoverRobot.orientation;
    }

    return RoverRobot;
}

struct rover moveRover(struct rover RoverRobot, int tamanhoX, int tamanhoY) {
    switch (RoverRobot.orientation) {
        case 'N':
            movementValidator(RoverRobot.y + 1, tamanhoX, tamanhoY, 'y') ? RoverRobot.y += + 1 : printf("Limit of the field exceeded, movement not registered.\n\n");
            break;
        case 'S':
            movementValidator(RoverRobot.y - 1, tamanhoX, tamanhoY, 'y') ? RoverRobot.y += - 1 : printf("Limit of the field exceeded, movement not registered.\n\n");
            break;
        case 'E':
            movementValidator(RoverRobot.x + 1, tamanhoX, tamanhoY, 'x') ? RoverRobot.x += + 1 : printf("Limit of the field exceeded, movement not registered.\n\n");
            break;
        case 'W':
            movementValidator(RoverRobot.x - 1, tamanhoX, tamanhoY, 'x') ? RoverRobot.x += - 1 : printf("Limit of the field exceeded, movement not registered.\n\n");
            break;
    }

    return RoverRobot;
}