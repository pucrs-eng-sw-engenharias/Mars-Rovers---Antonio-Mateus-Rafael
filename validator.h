int movementValidator(int movement, int tamanhoX, int tamanhoY, char orientation){
    switch (orientation) {
        case 'x':
            if (movement > tamanhoX) {
                return 0;
            } else if(movement < 0) {
                return 0;
            } else {
                return 1;
            }
            break;
        case 'y':
            if (movement > tamanhoY) {
                return 0;
            } else if(movement < 0) {
                return 0;
            } else {
                return 1;
            }
            break;
    }
}