/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>


int x=0;
int orientacao;
char L = 1, R = 1;

int main()
{
    int esquerda =0;
    int direita = 0;
    printf("Posição Inicial do Rover: 0, 0 N\n");
    
    do{
    printf("Digite a orientação desejada: 1(Left) or 2(Right)\n");
    scanf("%i", &orientacao);
    
    if(orientacao == 1) esquerda = esquerda+1;
    if(orientacao == 2) direita = direita+1;
    
    printf("Confirme para sair (3 = confirmar posição, 4 = dar nova orientação)\n");
    scanf("%i", &x);
    
    
    }while(x != 3);
    
    printf("orientação atual do rover é: %i %i ", esquerda, direita);

}
