#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
    printf("\n+---------------------+\n| Jogo da Adivinhacao |\n+---------------------+\n");
}

int gerarNum()
{
    return 0;
}

int main()
{
    int segundos = time(0);
    srand(segundos);
    int numSecreto = rand(), numUser, cout = 1;
    int numMaquina = numSecreto % 100;
    double pontos = 1000;

    while(1){
        printf("\nTentativa %d\n", cout);
        cout++;
        menu();
        printf("Digite um numero: ");
        scanf("%d", &numUser);

        if (numUser < 0)
        {
            printf("numero negativo nao e permitido");
            cout--;
            continue;
        }
        

        int acertou = numUser == numMaquina;
        if (acertou)
        {
            printf("Parabens!! voce acertou o numero\n");
            break;
        }
        else if (numUser > numMaquina)
        {
            printf("%d e maior que o numero gerado\n", numUser);
            pontos -= (numUser - numMaquina)/(double)2;
        }
        else
        {
            pontos -= (numMaquina - numUser)/(double)2;
            printf("%d e menor que o numero gerado\n", numUser);
        }
    }
    printf("Fim de jogo!\n");
    printf("voce acertou em %d tentativas\n", cout-1);
    printf("pontos: %.2f\n", pontos);
    return 0;
}