/*****************************************************
* Arquivo main.c - Exercicio pilha com lista encadeada
*
* Engenharia Eletronica
* Semestre 2015-1
*
* Desenvolvedor: Leonardo Persike Martins
* IFSC 2015
******************************************************/
//#define DEBUG
#define CALCMODE

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    int quantidade_dados = 0;
    Lista* pilha;
    #ifdef DEBUG
    // Adicionando dados na pilha (LIFO - Last in First Out)
    push(&pilha,3.56,&quantidade_dados);
    push(&pilha,10.43,&quantidade_dados);
    push(&pilha,59.4,&quantidade_dados);
    push(&pilha,1.98,&quantidade_dados);

    // Imprime pilha
    imprime_pilha(pilha,quantidade_dados);

    // Retirando dados da pilha
    printf("\n\nUsando pop na pilha!");
    while(quantidade_dados>0)
    {
        printf("\n Dado %d: ",quantidade_dados);
        printf("%.2f",pop(&pilha,&quantidade_dados));
    }
    #endif

    #ifdef CALCMODE
    int aux = 1;
    // Variaveis para calculadora
    float value1,value2;
    char operando;

    //Maximo 20 dados na pilha, definido por functions.c (MAX_DATA)
    while(aux == 1)
    {
        // Adicionando valores na pilha
        printf("\nEntre com os dois valores: ");
        scanf("%f %f",&value1,&value2);
        push(&pilha,value1,&quantidade_dados);
        push(&pilha,value2,&quantidade_dados);
        // Adicionando operador
        printf("\nEntre com a operacao (+,-,*,/): ");
        scanf("%s",&operando);

        // Fazendo calculo
        switch(operando)
        {
            case '+': push(&pilha,(pop(&pilha,&quantidade_dados)+pop(&pilha,&quantidade_dados)),&quantidade_dados);break;
            case '-': push(&pilha,(pop(&pilha,&quantidade_dados)-pop(&pilha,&quantidade_dados)),&quantidade_dados);break;
            case '*': push(&pilha,(pop(&pilha,&quantidade_dados)*pop(&pilha,&quantidade_dados)),&quantidade_dados);break;
            case '/': push(&pilha,(pop(&pilha,&quantidade_dados)/pop(&pilha,&quantidade_dados)),&quantidade_dados);break;
        }

        printf("\nResultado: %.2f",pop(&pilha,&quantidade_dados));
    }
    #endif

    return 0;
}


