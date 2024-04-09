/*  Programa em C para treinar as funções básicas de Estruturas de Dados
    Autor: Vinícius Pereira da Costa
    Ciência da Computação
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

//Procedimento pra inserir no início de uma Lista Encadeada
void inserirNoInicio(No **lista, int num)
{
    No *novo = malloc(sizeof(No));              //Cria e aloca um novo nó
    if(novo)                                    //SE alocação bem sucedida
    {
        novo->valor = num;                      //Valor do novo nó é o número
        novo->proximo = *lista;                 //Elo do novo nó é o primeiro nó (*lista = 1º nó)
        *lista = novo;                          //Primeiro nó passa a ser o novo nó
    }
    else printf("Erro ao alocar memória! \n");
}

//Procedimento pra inserir no final de uma Lista Encadeada
void inserirNoFinal(No **lista, int num)
{
    No *novo = malloc(sizeof(No));              //Cria e aloca um novo nó
    No *aux;                                    //Cria uma variável nó auxiliar
    if(novo)                                    //SE alocação bem sucedida
    {
        novo->valor = num;                      //Valor do novo nó é o número
        novo->proximo = NULL;                   //Elo do novo nó é NULO (Elo NULO = último nó)

        if(*lista == NULL)                      //SE a lista estava vazia
        {
            *lista = novo;                      //Primeiro nó = o novo nó
        }
        else                                    //Lista já cheia
        {
            aux = *lista;                       //Nó auxiliar recebe o 1º nó (NUNCA MUDE O PONTEIRO LISTA)
            //ENQUANTO o próximo do auxiliar não for NULO = não é o útimo nó
            while(aux->proximo)
            {
                aux = aux->proximo;             //Passa pro próximo nó
            }
            //Chegou no último nó
            aux->proximo = novo;                //Elo do último nó é o novo nó
        }
    }
    else printf("Erro ao alocar memória! \n");
}

//Procedimento para inserir no meio de uma Lista Encadeada
void inserirNoMeio(No **lista, int ant, int num)
{
    No *novo = malloc(sizeof(No));              //Cria e aloca um novo nó
    No *aux;                                    //Cria uma variável nó auxiliar
    if(novo)                                    //SE alocação bem sucedida
    {
        novo->valor = num;                      //Valor do novo nó é o número
        if(*lista == NULL)                      //SE primeiro nó não existe = lista vazia
        {
            novo->proximo = NULL;               //Elo do nó é NULO (nó é o último)
            *lista = novo;                      //Primeiro nó = novo nó (nó é o primeiro)
        }
        else                                    //Lista já cheia
        {
            aux = *lista;                       //Nó auxiliar recebe o 1º nó (NUNCA MUDE O PONTEIRO LISTA)
            //Enquanto o valor do auxiliar for diferente da referência procurada
            //e aux não for o último nó (próximo != NULO)
            while(aux->valor != ant && aux->proximo)
            {
                aux = aux->proximo;             //Passa pro próximo nó
            }
            //Referência encontrada OU chegou no fim da lista
            novo->proximo = aux->proximo;       //Elo do novo é o elo da referência
            aux->proximo = novo;                //Elo da referência é o novo
        }
    }
    else printf("Erro ao alocar memória! \n");
}

//Procedimento para enfileirar um elemento
void enfileira(No **fila, int num)
{
    No *novo = malloc(sizeof(No));              //Cria e aloca um novo nó
    No *aux;                                    //Cria uma variável nó auxiliar
    if(novo)                                    //SE alocação bem sucedida
    {
        novo->valor = num;                      //Valor do novo nó é o número
        novo->proximo = NULL;                   //Elo do novo nó é NULO (Elo NULO = último nó)
        if(*fila == NULL)                       //SE primeiro nó não existe = fila vazia
        {
            *fila = novo;                       //Primeiro nó = novo nó (nó é o primeiro)
        }
        else                                    //Fila já cheia
        {
            aux = *fila;                        //Nó auxiliar recebe o 1º nó (NUNCA MUDE O PONTEIRO LISTA)
            //ENQUANTO aux não for o último nó (próximo != NULO)
            while(aux->proximo)
                aux = aux->proximo;             //Elo do novo é o elo da referência
            aux->proximo = novo;                //Elo da referência é o novo
        }
    }
    else printf("Erro ao alocar memória! \n");
}

//Procedimento para desenfileirar um elemento
No *desenfileira(No **fila)
{
    No *remove = NULL;                          //Cria uma variável nó para retornar
    if(*fila)                                   //SE primeiro nó não é NULO
    {
        remove = *fila;                         //Variável retornada é o primeiro nó
        *fila = remove->proximo;                //Primeiro nó passa a ser o segundo nó, ou NULO, caso seja o último
    }
    else printf("\tFila vazia\n");
    return remove;                             //Retorna o nó desenfileirado
}

void limpaEstrutura(No **estrutura)
{
    No *tmp;                                    //Cria variável nó temporário
    while(*estrutura)                           //Enquanto primeiro nó não for nulo
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
    //ENQUANTO nó não for NULO
    while(no)
    {
        printf("%d ", no->valor);               //Printa o valor do nó
        no = no->proximo;                       //Passa pro próximo nó
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
        printf("Com qual Estrutura de Dados você quer trabalhar?\n");
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
                    printf("Digite o valor de referência: ");
                    scanf("%d", &anterior);
                    inserirNoMeio(&estrutura, anterior, valor);
                    break;
                case 4:
                    imprimir(estrutura);
                    break;
                default:
                    if(opcao != 0)
                    {
                        printf("Opção inválida!\n");
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
                    printf("O elemento desenfileirado é: %d", desenfileira(&estrutura)->valor);
                case 3:
                    imprimir(estrutura);
                    break;
                default:
                    if(opcao != 0)
                    {
                        printf("Opção inválida!\n");
                    }
                }
            }
            while(opcao != 0);
            break;

        default:
            if(opcao != 0)
            {
                printf("Opção inválida!\n");
            }
        }
    }
    while(estEscolhida != 0);
    return 0;
}
