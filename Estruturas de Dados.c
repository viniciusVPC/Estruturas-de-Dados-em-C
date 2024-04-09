/*  Programa em C para treinar as fun��es b�sicas de Estruturas de Dados
    Autor: Vin�cius Pereira da Costa
    Ci�ncia da Computa��o
    Universidade Anhembi Morumbi
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

//Procedimento pra inserir no in�cio de uma Lista Encadeada
void inserirNoInicio(No **lista, int num)
{
    No *novo = malloc(sizeof(No));              //Cria e aloca um novo n�
    if(novo)                                    //SE aloca��o bem sucedida
    {
        novo->valor = num;                      //Valor do novo n� � o n�mero
        novo->proximo = *lista;                 //Elo do novo n� � o primeiro n� (*lista = 1� n�)
        *lista = novo;                          //Primeiro n� passa a ser o novo n�
    }
    else printf("Erro ao alocar mem�ria! \n");
}

//Procedimento pra inserir no final de uma Lista Encadeada
void inserirNoFinal(No **lista, int num)
{
    No *novo = malloc(sizeof(No));              //Cria e aloca um novo n�
    No *aux;                                    //Cria uma vari�vel n� auxiliar
    if(novo)                                    //SE aloca��o bem sucedida
    {
        novo->valor = num;                      //Valor do novo n� � o n�mero
        novo->proximo = NULL;                   //Elo do novo n� � NULO (Elo NULO = �ltimo n�)

        if(*lista == NULL)                      //SE a lista estava vazia
        {
            *lista = novo;                      //Primeiro n� = o novo n�
        }
        else                                    //Lista j� cheia
        {
            aux = *lista;                       //N� auxiliar recebe o 1� n� (NUNCA MUDE O PONTEIRO LISTA)
            //ENQUANTO o pr�ximo do auxiliar n�o for NULO = n�o � o �timo n�
            while(aux->proximo)
            {
                aux = aux->proximo;             //Passa pro pr�ximo n�
            }
            //Chegou no �ltimo n�
            aux->proximo = novo;                //Elo do �ltimo n� � o novo n�
        }
    }
    else printf("Erro ao alocar mem�ria! \n");
}

//Procedimento para inserir no meio de uma Lista Encadeada
void inserirNoMeio(No **lista, int ant, int num)
{
    No *novo = malloc(sizeof(No));              //Cria e aloca um novo n�
    No *aux;                                    //Cria uma vari�vel n� auxiliar
    if(novo)                                    //SE aloca��o bem sucedida
    {
        novo->valor = num;                      //Valor do novo n� � o n�mero
        if(*lista == NULL)                      //SE primeiro n� n�o existe = lista vazia
        {
            novo->proximo = NULL;               //Elo do n� � NULO (n� � o �ltimo)
            *lista = novo;                      //Primeiro n� = novo n� (n� � o primeiro)
        }
        else                                    //Lista j� cheia
        {
            aux = *lista;                       //N� auxiliar recebe o 1� n� (NUNCA MUDE O PONTEIRO LISTA)
            //Enquanto o valor do auxiliar for diferente da refer�ncia procurada
            //e aux n�o for o �ltimo n� (pr�ximo != NULO)
            while(aux->valor != ant && aux->proximo)
            {
                aux = aux->proximo;             //Passa pro pr�ximo n�
            }
            //Refer�ncia encontrada OU chegou no fim da lista
            novo->proximo = aux->proximo;       //Elo do novo � o elo da refer�ncia
            aux->proximo = novo;                //Elo da refer�ncia � o novo
        }
    }
    else printf("Erro ao alocar mem�ria! \n");
}

//Procedimento para enfileirar um elemento
void enfileira(No **fila, int num)
{
    No *novo = malloc(sizeof(No));              //Cria e aloca um novo n�
    No *aux;                                    //Cria uma vari�vel n� auxiliar
    if(novo)                                    //SE aloca��o bem sucedida
    {
        novo->valor = num;                      //Valor do novo n� � o n�mero
        novo->proximo = NULL;                   //Elo do novo n� � NULO (Elo NULO = �ltimo n�)
        if(*fila == NULL)                       //SE primeiro n� n�o existe = fila vazia
        {
            *fila = novo;                       //Primeiro n� = novo n� (n� � o primeiro)
        }
        else                                    //Fila j� cheia
        {
            aux = *fila;                        //N� auxiliar recebe o 1� n� (NUNCA MUDE O PONTEIRO LISTA)
            //ENQUANTO aux n�o for o �ltimo n� (pr�ximo != NULO)
            while(aux->proximo)
                aux = aux->proximo;             //Elo do novo � o elo da refer�ncia
            aux->proximo = novo;                //Elo da refer�ncia � o novo
        }
    }
    else printf("Erro ao alocar mem�ria! \n");
}

//Procedimento para desenfileirar um elemento
No *desenfileira(No **fila)
{
    No *remove = NULL;                          //Cria uma vari�vel n� para retornar
    if(*fila)                                   //SE primeiro n� n�o � NULO
    {
        remove = *fila;                         //Vari�vel retornada � o primeiro n�
        *fila = remove->proximo;                //Primeiro n� passa a ser o segundo n�, ou NULO, caso seja o �ltimo
    }
    else printf("\tFila vazia\n");
    return remove;                             //Retorna o n� desenfileirado
}

void limpaEstrutura(No **estrutura)
{
    No *tmp;                                    //Cria vari�vel n� tempor�rio
    while(*estrutura)                           //Enquanto primeiro n� n�o for nulo
    {
        tmp = *estrutura;
        estrutura = estrutura->proximo;
        free(tmp);
    }
}

//Procedimento para imprimir a Estrutura
void imprimir(No *no)
{
    printf("\n\tEstrutura: ");
    //ENQUANTO n� n�o for NULO
    while(no)
    {
        printf("%d ", no->valor);               //Printa o valor do n�
        no = no->proximo;                       //Passa pro pr�ximo n�
    }
    printf("\n\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int estEscolhida, opcao, valor, anterior;
    No *estrutura = NULL;

    do
    {
        limpaEstrutura(estrutura);
        printf("Com qual Estrutura de Dados voc� quer trabalhar?\n");
        printf("\n\t1 - Lista\n\t2 - Fila\n\t0 - Sair\n");
        scanf("%d", &estEscolhida);

        switch(estEscolhida)
        {
        case 1:
            do
            {
                printf("\n\t0 - Sair\n\t1 - InserirInicio\n\t2 - InserirFinal\n\t3 - InserirMeio\n\t4 - Imprimir\n");
                scanf("%d", &opcao);

                switch(opcao)
                {
                case 1:
                    printf("Digite um valor: ");
                    scanf("%d", &valor);
                    inserirNoInicio(&estrutura, valor);
                    break;
                case 2:
                    printf("Digite um valor: ");
                    scanf("%d", &valor);
                    inserirNoFinal(&estrutura, valor);
                    break;
                case 3:
                    printf("Digite um valor: ");
                    scanf("%d", &valor);
                    printf("Digite o valor de refer�ncia: ");
                    scanf("%d", &anterior);
                    inserirNoMeio(&estrutura, anterior, valor);
                    break;
                case 4:
                    imprimir(estrutura);
                    break;
                default:
                    if(opcao != 0)
                    {
                        printf("Op��o inv�lida!\n");
                    }
                }
            }
            while(opcao != 0);
            break;

        case 2:
            do
            {
                printf("\n\t0 - Sair\n\t1 - Enfileirar\n\t2 - Desenfileirar\n\t3 - Imprimir\n");
                scanf("%d", &opcao);

                switch(opcao)
                {
                case 1:
                    printf("Digite um valor: ");
                    scanf("%d", &valor);
                    enfileira(&estrutura, valor);
                    break;
                case 2:
                    printf("O elemento desenfileirado �: %d", desenfileira(&estrutura)->valor);
                case 3:
                    imprimir(estrutura);
                    break;
                default:
                    if(opcao != 0)
                    {
                        printf("Op��o inv�lida!\n");
                    }
                }
            }
            while(opcao != 0);
            break;

        default:
            if(opcao != 0)
            {
                printf("Op��o inv�lida!\n");
            }
        }
    }
    while(estEscolhida != 0);
    return 0;
}
