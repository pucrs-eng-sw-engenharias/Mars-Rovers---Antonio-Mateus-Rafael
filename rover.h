#include "validator.h"

struct rover {
    int x;
    int y;
    char orientation;
};

struct rover rotateRover(struct rover RoverRobot, char *side) {
    switch (RoverRobot.orientation) {
        case 'N':
            if (side == "L") {
                RoverRobot.orientation = 'W';
            } else {
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
            if (side == "L") {
                RoverRobot.orientation = 'N';
            } else {
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