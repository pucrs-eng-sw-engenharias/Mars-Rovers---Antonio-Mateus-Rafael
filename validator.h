int movementValidator(int movement, int tamanhoX, int tamanhoY, char orientation){ //recebe os valores limites de movimentacao, para validar o movimento desejado
    switch (orientation) {
        case 'x': //movimentacao no eixo x, o switch verifica se o futuro valor de x (posicao de x desejada), nao ultrapassa os limites definidos na entrada de dados
            if (movement > tamanhoX) {
                return 0;
            } else if(movement < 0) {
                return 0;
            } else {
                return 1;
            }
            break;
        case 'y': //movimentacao no eixo y, o switch verifica se o futuro valor de y (posicao de y desejada), nao ultrapassa os limites definidos na entrada de dados.
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