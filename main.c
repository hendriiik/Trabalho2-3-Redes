#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define ACK 1
#define NACK 0
#define NAO_RECEBIDO 2

#define TAM_JANELA 5
#define TAM_TOTAL 20
#define TAM_DADO_ENVIADO 5

int envia_dado(int mensagem_atual) {
    int dado = mensagem_atual;

    for (int i=0; i < TAM_DADO_ENVIADO; i++) {
        //cria um dado aleatório de 6 dígitos, sendo o primeiro o número da mensagem atual
        dado = dado + rand()%10 * pow(10,i+1);
    }

    printf("Enviando a mensagem %d: %d\n",mensagem_atual,dado);

    return dado;
}

int recebe_dado(int mensagem_atual, int dado) {
    int resultado = rand() % 10;

    if (resultado < 1) {
        printf("A mensagem %d retornou NACK\n",mensagem_atual);
        return NACK;
    } else if (resultado < 2) {
        printf("A mensagem %d não foi recebida\n",mensagem_atual);
        return NAO_RECEBIDO;
    } else {
        printf("A mensagem %d retornou ACK, e seu valor é: %d\n",mensagem_atual,dado);
        return ACK;
    }
}

int main(void) {
    int enviados[TAM_JANELA];
    int terminou = 0;
    int comeco_janela = 0;
    int i;

    srand( (unsigned)time(NULL) );

    while (terminou != 1) {
        int j = 0;
        for (i = comeco_janela; i< comeco_janela + TAM_JANELA; i++) {
            if (i > TAM_TOTAL) {
                break;
            }

            enviados[j]=envia_dado(i);
            j++;

        }
        printf("\n");

        j = 0;
        for (i = comeco_janela; i< comeco_janela + TAM_JANELA; i++) {

            int resposta = recebe_dado(i,enviados[j]);
            j++;
            if (resposta != ACK) {
                comeco_janela = i;
                printf("A mensagem %d não retornou ACK, vamos reenviar os dados da janela, a partir da mensagem %d\n",i,i);
                break;
            }

            if (i == TAM_TOTAL && resposta == ACK) {
                //Enviamos todos os dados corretamente
                printf("\nTerminou\n");
                terminou = 1;
                break;
            }
        }
        printf("\n");

        comeco_janela = i;

    }   
}