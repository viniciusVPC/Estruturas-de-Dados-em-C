/* Programa em C para treinar as fun��es b�sicas de Estruturas de Dados */
#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

//Procedimento pra inserir no in�cio de uma Lista Encadeada
void inserirNoInicio(No **lista, int num)
{
    No *novo = malloc(sizeof(No));          //Cria e aloca um novo n�
    if(novo)                                //SE aloca��o bem sucedida
    {
        novo->valor = num;                  //Valor do novo n� � o n�mero
        novo->proximo = *lista;             //Elo do novo n� � o primeiro n� (*lista = 1� n�)
        *lista = novo;                      //Primeiro n� passa a ser o novo n�
    }
    else printf("Erro ao alocar mem�ria! \n");
}

//Procedimento pra inserir no final de uma Lista Encadeada
void inserirNoFinal(No **lista, int num)
{
    No *novo = malloc(sizeof(No));          //Cria e aloca um novo n�
    No *aux;                                //Cria uma vari�vel n� auxiliar
    if(novo)                                //SE aloca��o bem sucedida
    {
        novo->valor = num;                  //Valor do novo n� � o n�mero
        novo->proximo = NULL;               //Elo do novo n� � NULO (Elo NULO = �ltimo n�)

        if(*lista == NULL)                  //SE a lista estava vazia
        {
            *lista = novo;                  //Primeiro n� = o novo n�
        }
        else                                //Lista j� cheia
        {
            aux = *lista;                   //N� auxiliar recebe o 1� n� (NUNCA MUDE O PONTEIRO LISTA)
            //ENQUANTO o pr�ximo do auxiliar n�o for NULO = n�o � o �timo n�
            while(aux->proximo)
            {
                aux = aux->proximo;     //Passa pro pr�ximo n�
            }
            //Chegou no �ltimo n�
            aux->proximo = novo;            //Elo do �ltimo n� � o novo n�
        }
    }
    else printf("Erro ao alocar mem�ria! \n");
}

//Procedimento para inserir no meio de uma Lista Encadeada
void inserirNoMeio(No **lista, int ant, int num)
{
    No *novo = malloc(sizeof(No));          //Cria e aloca um novo n�
    No *aux;                                //Cria uma vari�vel n� auxiliar
    if(novo)                                //SE aloca��o bem sucedida
    {
        novo->valor = num;                  //Valor do novo n� � o n�mero
        if(*lista == NULL)                  //SE primeiro n� n�o existe = lista vazia
        {
            novo->proximo = NULL;           //Elo do n� � NULO (n� � o �ltimo)
            *lista = novo;                  //Primeiro n� = novo n� (n� � o primeiro)
        }
        else                                //Lista j� cheia
        {
            aux = *lista;                   //N� auxiliar recebe o 1� n� (NUNCA MUDE O PONTEIRO LISTA)
            //Enquanto o valor do auxiliar for diferente da refer�ncia procurada
            //e aux n�o for o �ltimo n� (pr�ximo != NULO)
            while(aux->valor != ant && aux->proximo)
            {
                aux = aux->proximo;         //Passa pro pr�ximo n�
            }
            //Refer�ncia encontrada OU chegou no fim da lista
            novo->proximo = aux->proximo;   //Elo do novo � o elo da refer�ncia
            aux->proximo = novo;            //Elo da refer�ncia � o novo
        }
    }
    else printf("Erro ao alocar mem�ria! \n");
}

//Procedimento para imprimir a Lista Encadeada
void imprimir(No *no)
{
    printf("\n\tLista: ");
    //ENQUANTO n� n�o for NULO
    while(no)
    {
        printf("%d ", no->valor);           //Printa o valor do n�
        no = no->proximo;                   //Passa pro pr�ximo n�
    }
    printf("\n\n");
}

int main()
{
    int opcao, valor, anterior;
    No *lista = NULL;

    do
    {
        printf("\n\t0 - Sair\n\t1 - InserirInicio\n\t2 - InserirFinal\n\t3 - InserirMeio\n\t4 - Imprimir\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserirNoInicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserirNoFinal(&lista, valor);
            break;
        case 3:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            printf("Digite o valor de refer�ncia: ");
            scanf("%d", &anterior);
            inserirNoMeio(&lista, anterior, valor);
            break;
        case 4:
            imprimir(lista);
            break;
        default:
            if(opcao != 0)
            {
                printf("Op��o inv�lida!\n");
            }
        }
    }
    while(opcao != 0);

    return 0;
}
