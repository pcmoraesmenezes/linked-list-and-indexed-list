#include <iostream> // incluindo a biblioteca basica de c++
using namespace std; // com esse comando não é necessário utilizar std:: antes do cin e cout
#define MAX_SIZE 100 // definindo o tamanho maximo da lista
typedef struct lista{ // criando uma lista
    int lista[MAX_SIZE];//array que armazenara os valores da lista
    int tamanho = 0; //variavel que armazenara o tamanho atual da lista
}lista;// nome da struct

int insereLista(lista * p, int valor) // função que irá inserir elementos na lista, recebe dois parametros uma variavel do tipo lista e o valor a ser inserido
{
    if(p->tamanho == MAX_SIZE) //verifica se a lista está cheia
    { 
        printf("Lista cheia! \n"); // mensagem para o usuario
        return 0; // encerra a função
    }
    if (p->tamanho == 0) // verifica se a lista esta vazia
    {
        p->lista[p->tamanho] = valor; // inicializa a lista e insere no primeiro elemento o valor
        p->tamanho++; // incrementa a lista
        return 1; // encerra a função 
    }
    else // se nao
    {
        p->lista[p->tamanho] = valor; // insere o elemento na posição do tamanho
        p->tamanho++; // incrementa a função
        return 1;// encerra a função
    }
}
int removeLista(lista * p, int valorRemovido) // função que irá remover elementos da lista, recebe dois parametros uma variavel do tipo lista e o valor a ser removido
{
    if(p->tamanho == 0) // verifica se a lista esta vazia
    {
        printf("Lista vazia! \n"); //mensagem ao usuario
        return 0; // encerra a função
    }
    int i = 0; //criando uma variavel que ira percorrer todo o vetor da lista
    for(i = 0; i < p->tamanho; i ++) // repetição que irá ate o ultimo elemento da lista
    {
        if(p->lista[i] == valorRemovido)//condição que verifica se o elemento na posição i é o elemento a ser removido
        {
            break; // encerra o for se sim
        }
    }
    if(i == p->tamanho && p->lista[i] != valorRemovido) //verifica se o i pecorreu todo o vetor e se o valor e diferente do valor a ser removido
    {
        printf("Valor não encontrado! \n"); // mensagem ao usuario
        return 0; // encerra a função
    }
    for(; i < p->tamanho - 1; i++) //laço de repetição que irá ate o i ser menor que o tamanho da lista
    {
        p->lista[i] = p->lista[i+1]; // fazendo com que os elementos andem uma posição
    }
    p->tamanho--; // decrementa a lista
    printf("O valor removido foi [%d]\n", valorRemovido); // mensagem ao usuario
    return valorRemovido;//encerra a função
}
int imprimeLista(lista * p) // função do tipo inteira que recebe como parametro uma variavel do tipo lista
{
    if(p->tamanho == 0) //verifica se a lista esta vazia
    {
        printf("Lista vazia! \n"); // mensagem ao usuario
        return 0; // encerra a função
    }
    for(int i = 0; i < p->tamanho; i++) // laço de repetição que ira ate o ultimo elemento da lista
    {
        printf("[%d]-> ", p->lista[i]); // informa o elemento 
    }
    printf("\n"); // quebra de linha
}
int main() // corpo principal do main
{
    lista * p = new lista; // variavel do tipo lista que recebe um espaço da memoria do tamanho de lista
    int adicionar = 0; // variavel responsavel por adicionar elementos
    int navegador = 0; // variavel responsavel por navegar no menu
    int valor_removido; // variavel responsavel por remover elementos 
    while (true) // laço de repetição infinito
   {   
        printf("Bem vindo a sua lista! Para visualizar a sua lista digite '1', para inserir um valor em sua lista digite '2', para remover um elemento da sua lista digite '3' e para sair digite '4'\n"); //menu para o usuario
        scanf("%d", &navegador); //recebe do usuario uma informação
        while (navegador != 1 && navegador != 2 && navegador != 3 && navegador != 4) // verifica se o usuario escolheu uma opção valida
        {
            printf("Você não informou uma opção válida! Tente novamente \n"); // informa ao usuario erro
            scanf("%d", &navegador); // nova informação ao usuario
        }
        if (navegador == 1) // verifica se o usuario optou pela opção 1
        {
            if(p->tamanho == 0) // verifica se a lista esta vazia
            {
                printf("A sua lista está vazia! \n"); // mensagem ao usuario
            }
            else{ // senao
            printf("Você optou por visualizar a lista!\n "); // mensagem ao usuario
            imprimeLista(p); //chamando a função que mostra ao usuario os elementos
            }
        }
        if (navegador == 2) // verifica se o usuario optou pela opção 2
        {
            printf("Você optou por inserir! Por favor insira o numero a baixo: \n"); //mensagem ao usuario
            scanf("%d", &adicionar); //recebe um valor a ser adicionado
            insereLista(p, adicionar); //chama a função para inserir na lista
        }
        if (navegador == 3) // verifica se o usuario optou pela opção 3
        {
            printf("Você optou por remover um elemento, insira abaixo o elemento a ser removido ! \n "); // mensagem ao usuario
            scanf("%d", &valor_removido); //recebe do usuario o elemento a ser removido
            removeLista(p, valor_removido);//chama a função que remove os elementos
        }
        if (navegador == 4) //verifica se o usuario optou pela opção 4
        {   printf("Você optou por sair da lista! \n"); // mensagem ao usuario
            break;//encerra o laço de repetição
        }
   }    
}