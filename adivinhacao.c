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
    int acertou;
    int tentativas;
    int nivel;
    printf("Nivel de dificuldade\n[1]Fácil\n[2]Médio\n[3]Dificil\nEscolha: \n");
    scanf("%d", &nivel);
    switch (nivel)
    {
    case 1:
        tentativas = 20;
        break;
    case 2:
        tentativas = 15;
        break;
    case 3:
        tentativas = 6;
        break;
    
    default:
    printf("Opção inválida");
        break;
    }

    for (int i = 1; i <= tentativas; i++)
    {
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

        acertou = numUser == numMaquina;
        if (acertou)
        {

            break;
        }
        else if (numUser > numMaquina)
        {
            printf("%d e maior que o numero gerado\n", numUser);
            pontos -= (numUser - numMaquina) / (double)2;
        }
        else
        {
            pontos -= (numMaquina - numUser) / (double)2;
            printf("%d e menor que o numero gerado\n", numUser);
        }
    }
    printf("Fim de jogo!\n");
    if (acertou)
    {
        printf("Parabens!! voce acertou o numero\n");
        printf("voce acertou em %d tentativas\n", cout - 1);
        printf("pontos: %.2f\n", pontos);
    }
    else
    {
        printf("VocÊ perdeu! Tente novamente!\n");
    }

    return 0;
}
