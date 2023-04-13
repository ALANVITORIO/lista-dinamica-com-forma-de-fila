#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//DEFININDO A ESTRUTURA DA PILHA
int dado;
struct no
{
    int dado;
    struct no *proximo;    
};
//definindo as variáveis

typedef struct no *ptr_no;
ptr_no pilha;
int op;
int no;
//Prototipação

void menu_mostrar();
void menu_selecionar(int op);
void pilha_inserir(ptr_no pilha);
void pilha_remover(ptr_no pilha);
void pilha_mostrar(ptr_no pilha);

//função principal

int main(){
    srand(time(NULL));
    op = 1;

//criando o primeiro nó da pilha

pilha=(ptr_no)malloc(sizeof(no));
pilha-> dado = 0;
pilha->proximo = NULL;
//LAÇO PRINCIPAL

while(op!= 0){
    system("cls");
    menu_mostrar();
    scanf("%d", &op);
    menu_selecionar(op);
}

system("Pause");
return(0);



}

//mostra o menu de opções

void menu_mostrar(){
    pilha_mostrar(pilha);
    printf("\n\n escolha uma das opcoes: \n");
    printf("1-Inserir no final da pilha \n");
    printf("2-Remover no final da pilha \n");
    printf("0-Sair \n\n");
}

//execução do programa

void menu_selecionar (int op){
    switch(op){
        case 1 :
        pilha_inserir(pilha);
        break;
        case 2 :
        pilha_remover(pilha);
        break;
    }
}
//inserir um elemento no final da filha

void pilha_inserir(ptr_no pilha){
    while(pilha-> proximo != NULL){
        pilha = pilha->proximo;
    }
    pilha-> proximo = (ptr_no)malloc(sizeof(no));
    pilha = pilha->proximo;
    pilha -> dado = rand()%100;
    pilha->proximo = NULL;

}

//REMOVER UM ELEMENTO DA PILHA
void pilha_remover(ptr_no pilha){
    ptr_no atual;
    atual=(ptr_no)malloc(sizeof(no));
    while(pilha->proximo != NULL){
        atual = pilha;
        pilha = pilha ->proximo;
    }
    atual -> proximo = NULL;
}
//DESENHA O CONTEÚDO DA PILHA NA TELA
void pilha_mostrar(ptr_no pilha){
    system("cls");
    while(pilha -> proximo !=NULL){
        printf("%d, ", pilha->dado);
        pilha = pilha->proximo;
    }
    printf("%d, ", pilha->dado);
}
