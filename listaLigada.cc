#include <iostream> // incluindo a biblioteca principal do codigo
using namespace std; // com esse trecho e possivel utilizar as funções cin e cout sem usar o ::Std
typedef struct no { // criando struct
    int valor; // variavel que ira receber o valor
    no * proximo_no; // variavel do tipo no que ira apontar para a proxima struct 
}no; // nome da struct
no * IniciaLista() // função do tipo no que ira inicializar a lista
{
    no * no_cabeca = new no; // criando uma variavel do tipo no e atribuindo a ela um espaço da memoria do tamanho do no
    no_cabeca->proximo_no = NULL; // fazendo ela apontar para nada pois ainda não há elementos
    return no_cabeca; // retornando o ponteiro
}
int insereLista(no * p, int valor) // função que ira ser responsavel por inserir os elementos, recebe uma variavel do tipo no e o valor a ser inserido
{   
    if(!p) //verifica se houve erro
    {
        return -1; // retorna -1 pra encerrar a função
    }
    no * novo_no = new no; // criando uma variavel do tipo no e atribuindo a ela o tamanho de no
    if(!novo_no) // verificando se houve erro na alocação
    {
        return -2;// retornando -2 para encerrar a função
    }
    novo_no->valor = valor; // fazendo com que o no criado receba a variavel valor
    novo_no->proximo_no = p->proximo_no; // fazendo com que os ponteiros andem
    p->proximo_no = novo_no; //fazendo com que o proximo no receba o novo no
    return 1; // retorna 1, para caso de sucesso
}
int removeLista(no * p , int valorRemovido) // função que ira remover um elemento da lista, recebe como parametro uma variavel do tipo no e o elemento a ser removido
{
    if(!p) //verifica se a lista está iniciada
    {   printf("Lista não iniciada! \n"); //mensagem no usuario
        return -1; // encerra a função
    }
    if(!p->proximo_no) //verifica se a lista está vazia
    {
        printf("Lista vazia! \n"); // mensagem ao usuario
        return -2; //encerra a função
    }
    no * anterior = p; //criando uma variavel do tipo no e atribuindo a ela a variavel no
    no * atual = p->proximo_no; //criando a variavel do tipo no e atribuindo a ela o ponteiro da proxima struct
    while(atual!=NULL && atual->valor != valorRemovido)//laço de repetição que verifica se o elemento e nulo ou se encontrou o valor a ser removido
    {
        anterior = atual;//atribuindo a variavel anterior a atual
        atual = atual->proximo_no;// fazendo a struct andar
    }
    if(!atual)//verificando se o atual e null, se sim o laço de repetição foi encerrado devido a isso, ou seja o elemento não foi encontrado
    {   printf("Valor não encontrado! \n"); // mensagem ao usuario
        return -3; // verifica se encontrou o valor na lista
    }
    anterior->proximo_no = atual->proximo_no; //fazendo a struct anterior apontada para a proximo no receber o proximo no
    delete atual; //deletando a struct da memoria
    return 1;//encerrando o codigo
}
void imprimeLista(no * p)//função que ira imprimir a lista para o usuario
{
    if(!p) //verificando a lista
    {   printf("Lista não iniciada \n");// mensagem de erro
        return;//encerrando a função
    }
    no * atual = p->proximo_no; // atribuindo a variavel do tipo no a variavel para a proxima struct
    if(!atual)//verificando se há elementos na lista
    {
        printf("Lista vazia! \n");//mensagem de erro
        return;//encerrando a função
    }
    while(atual!=NULL) // repetição para imprimir os valores cuja condoção de parada é até o ultimo elemento 
    {
        printf("[%d] -> ", atual->valor); //imprimindo os valores para o usuario
        atual = atual->proximo_no; //andando com a struct
    }
    printf("\n"); // quebra de linha
}
int main() // corpo principal do main
{
   no * p = IniciaLista(); // criando uma variavel do tipo no e atribuindo a ela a função inicialista
   int navegador; // variavel que ira receber as instruções do menu pelo usuario
   int adicionar = 0; // variavel que ira receber o valor a ser adicionado pelo usuario
   int remover = 0; // variavel que ira receber o valor a ser removido pelo usuario
   while(true) // laço infinito
   {
        printf("Bem vindo a sua lista! Para imprimir os valores da tela digite '1', para adicionar um elemento a sua lista digite '2', para remover um elemento a sua escolha digite '3' e para sair do menu digite '4' \n");
        scanf("%d", &navegador);
        while (navegador != 1 && navegador != 2 && navegador != 3 && navegador != 4) // verifica se o usuario digitou algo além do que esperado
        {
            printf("Você não informou uma opção válida! Tente novamente \n"); // informa que ele não digitou uma opção válida das que foram ofertadas
            scanf("%d", &navegador);// recebe do usuario outra opção
        }
        if (navegador == 1) // verifica se ele escolheu a opção 1
        {
            if(!p) // verifica se a lista está vazia
            {
                printf("Lista vazia! \n"); // retorna uma mensagem
            }
            else{ // senao
            printf("Você optou por visualizar a lista!\n "); // retorna uma mensagem
            imprimeLista(p); // imprime a pilha na tela
            }
        }
        if (navegador == 2) // verifica se ele optou pela opção 2
        {   
            printf("Você optou por inserir! Por favor insira o numero abaixo: \n"); // retorna uma mensagem
            scanf("%d", &adicionar); // recebe do usuario um numero a ser adicionado
            insereLista(p, adicionar); // chamando a função que adiciona elementos na lista
        }
        if (navegador == 3) // verifica se o usuario optou pela opção 3
        {
            if(!p) // verifica se a lista está vazia
            {
                printf("Lista vazia! \n"); // retorna uma mensagem
            }
            else // senao
            {
              printf("Você optou por remover um elemento, insira abaixo o elemento a ser removido! \n "); // imprime uma mensagem na tela
              scanf("%d", &remover);
              removeLista(p, remover);
            }
        }
        if (navegador == 4) // verifica se o usuario optou pela opção 4
        {   printf("Você optou por sair da lista! \n"); // retorna uma mensagem
            break; // quebra o laço de repetição
        }
}
}
